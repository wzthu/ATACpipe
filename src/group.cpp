////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////This file using the following license////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// MIT License
//
// Copyright (c) 2021 Tim Stuart
//
//     Permission is hereby granted, free of charge, to any person obtaining a copy
//     of this software and associated documentation files (the "Software"), to deal
//     in the Software without restriction, including without limitation the rights
//     to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//     copies of the Software, and to permit persons to whom the Software is
//     furnished to do so, subject to the following conditions:
//
//         The above copyright notice and this permission notice shall be included in all
//         copies or substantial portions of the Software.
//
//     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//         IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//         FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//         AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//         LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//         OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//         SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include <Rcpp.h>
#include <zlib.h>

// [[Rcpp::export]]
SEXP groupCommand(
    std::string fragments,
    Rcpp::Nullable<Rcpp::StringVector> some_whitelist_cells = R_NilValue,
    std::size_t max_lines = 0,
    bool verbose = true
) {
  // opening gzipped compressed stream
  gzFile fileHandler = gzopen(fragments.c_str(), "rb");

  // determine if we read the whole file or the first n lines
  bool read_part {false};
  if (max_lines > 0) {
    read_part = true;
  }

  // return empty list if it can't find the file
  if (fileHandler == NULL) {
    Rcpp::Rcerr << "can't open file" << std::flush;
    return (Rcpp::DataFrame::create());
  }

  // C based buffered string parsing
  char* cb_char;
  size_t line_counter {1};
  uint32_t buffer_length = 256;
  char *buffer = new char[buffer_length];

  // Hash Map storing the count data
  std::unordered_map<std::string, size_t> index_hash;

  bool has_whitelist {false};
  size_t num_whitelist_cells {0};
  if (some_whitelist_cells.isNotNull()) {
    has_whitelist = true;
    Rcpp::StringVector whitelist_cells(some_whitelist_cells);
    for (size_t i=0; i<whitelist_cells.size(); i++) {
      index_hash[Rcpp::as<std::string>(whitelist_cells[i])] = i;
    }

    num_whitelist_cells = index_hash.size();
    if (verbose) {
      Rcpp::Rcerr << "Found " << num_whitelist_cells
                  << " cell barcodes"
                  << std::endl << std::flush;
    }
  }

  // char * to string extraction
  std::string cb_seq, line_seq;
  cb_seq.reserve(32);
  line_seq.reserve(buffer_length);

  // metadata from fragments file
  size_t start, end, reads;
  std::vector<size_t> freq_count, mono_nuc_count, nuc_free_count, read_count;
  // if we have external cells reserve the size
  if (has_whitelist) {
    freq_count.assign(num_whitelist_cells, 0);
    mono_nuc_count.assign(num_whitelist_cells, 0);
    nuc_free_count.assign(num_whitelist_cells, 0);
    read_count.assign(num_whitelist_cells, 0);
  }

  // skip header if present
  bool eof_check;
  while ((eof_check = gzgets(fileHandler, buffer, buffer_length)) !=0) {
    line_seq.clear();
    line_seq.append(buffer);

    if (line_seq.at(0) != '#') {
      break;
    }
  }

  if (!eof_check) {
    Rcpp::Rcerr << "Error: fragment file contains header only" << std::flush;
    gzclose(fileHandler);
    return (Rcpp::DataFrame::create());
  }

  // looping over the fragments file
  do {
    cb_char = strtok ( buffer, "\t" );

    for (auto i=1; i<=4; i++) {
      cb_char = strtok (NULL, "\t");

      switch(i) {
      case 3:
        cb_seq.clear();
        cb_seq.append(cb_char);
        break;
      case 1:
        start = atoi(cb_char);
        break;
      case 2:
        end = atoi(cb_char);
        break;
      case 4:
        reads = atoi(cb_char);
        break;
      }
    }

    uint8_t nuc_free_inc = end-start < 147 ? 1: 0;
    uint8_t mono_inc = (end-start > 147) and (end-start < 294) ? 1: 0;

    // index of the cellular barcode
    size_t cb_idx = index_hash.size();
    auto it = index_hash.find(cb_seq);
    if (it == index_hash.end()) {
      if (not has_whitelist) {
        // extracting the index
        index_hash[cb_seq] = cb_idx;

        // increment the count
        freq_count.emplace_back(1);
        mono_nuc_count.emplace_back(mono_inc);
        nuc_free_count.emplace_back(nuc_free_inc);
        read_count.emplace_back(reads);
      }
    } else {
      // extracting the index
      cb_idx = it->second;

      // increment the count
      freq_count[cb_idx] += 1;
      if (mono_inc > 0) mono_nuc_count[cb_idx] += mono_inc;
      if (nuc_free_inc > 0) nuc_free_count[cb_idx] += nuc_free_inc;
      read_count[cb_idx] += reads;
    }

    line_counter += 1;
    if (read_part) {
      if (line_counter > max_lines) {
        break;
      }
    }

    if (verbose) {
      if (line_counter % 10000000 == 0) {
        Rcpp::Rcerr << "\r                                                  ";
      }

      if (line_counter % 1000000 == 0) {
        Rcpp::Rcerr << "\rDone Processing " << line_counter / 1000000
                    << " million lines";
      }
    }
    if (line_counter % 2000000 == 0) {
      Rcpp::checkUserInterrupt();
    }
    line_seq.clear();
  } while(gzgets(fileHandler, buffer, buffer_length) !=0 );

  //Cleanup
  gzclose(fileHandler);

  // extracting cellular barcode names
  std::vector<std::string> keys(index_hash.size());
  for(auto kv : index_hash) {
    keys[kv.second] = kv.first;
  }

  // creating data frame and returning
  Rcpp::DataFrame cb_groups = Rcpp::DataFrame::create(
    Rcpp::Named("CB") = keys,
    Rcpp::Named("frequency_count") = freq_count,
    Rcpp::Named("mononucleosomal") = mono_nuc_count,
    Rcpp::Named("nucleosome_free") = nuc_free_count,
    Rcpp::Named("reads_count") = read_count);

  return (cb_groups);
}
