// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// filterCells
int filterCells(std::string fragments, std::string outfile, std::vector<std::string> keep_cells, int buffer_length, bool verbose);
RcppExport SEXP _esATAC_filterCells(SEXP fragmentsSEXP, SEXP outfileSEXP, SEXP keep_cellsSEXP, SEXP buffer_lengthSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type fragments(fragmentsSEXP);
    Rcpp::traits::input_parameter< std::string >::type outfile(outfileSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type keep_cells(keep_cellsSEXP);
    Rcpp::traits::input_parameter< int >::type buffer_length(buffer_lengthSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(filterCells(fragments, outfile, keep_cells, buffer_length, verbose));
    return rcpp_result_gen;
END_RCPP
}
// groupCommand
SEXP groupCommand(std::string fragments, Rcpp::Nullable<Rcpp::StringVector> some_whitelist_cells, std::size_t max_lines, bool verbose);
RcppExport SEXP _esATAC_groupCommand(SEXP fragmentsSEXP, SEXP some_whitelist_cellsSEXP, SEXP max_linesSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type fragments(fragmentsSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<Rcpp::StringVector> >::type some_whitelist_cells(some_whitelist_cellsSEXP);
    Rcpp::traits::input_parameter< std::size_t >::type max_lines(max_linesSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(groupCommand(fragments, some_whitelist_cells, max_lines, verbose));
    return rcpp_result_gen;
END_RCPP
}
// fastxrenamer
int fastxrenamer(Rcpp::List argvs);
RcppExport SEXP _esATAC_fastxrenamer(SEXP argvsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type argvs(argvsSEXP);
    rcpp_result_gen = Rcpp::wrap(fastxrenamer(argvs));
    return rcpp_result_gen;
END_RCPP
}
// sc_fastxrenamer
int sc_fastxrenamer(Rcpp::List argvs);
RcppExport SEXP _esATAC_sc_fastxrenamer(SEXP argvsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type argvs(argvsSEXP);
    rcpp_result_gen = Rcpp::wrap(sc_fastxrenamer(argvs));
    return rcpp_result_gen;
END_RCPP
}
// mergeFile
void mergeFile(Rcpp::CharacterVector destFile, Rcpp::CharacterVector fileList);
RcppExport SEXP _esATAC_mergeFile(SEXP destFileSEXP, SEXP fileListSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type destFile(destFileSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type fileList(fileListSEXP);
    mergeFile(destFile, fileList);
    return R_NilValue;
END_RCPP
}
// R_sam2bed_wrapper
Rcpp::List R_sam2bed_wrapper(Rcpp::List argvs, Rcpp::CharacterVector filterList);
RcppExport SEXP _esATAC_R_sam2bed_wrapper(SEXP argvsSEXP, SEXP filterListSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type argvs(argvsSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type filterList(filterListSEXP);
    rcpp_result_gen = Rcpp::wrap(R_sam2bed_wrapper(argvs, filterList));
    return rcpp_result_gen;
END_RCPP
}
// R_sam2bed_merge_wrapper
Rcpp::List R_sam2bed_merge_wrapper(Rcpp::List argvs, Rcpp::CharacterVector filterList);
RcppExport SEXP _esATAC_R_sam2bed_merge_wrapper(SEXP argvsSEXP, SEXP filterListSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type argvs(argvsSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type filterList(filterListSEXP);
    rcpp_result_gen = Rcpp::wrap(R_sam2bed_merge_wrapper(argvs, filterList));
    return rcpp_result_gen;
END_RCPP
}
// bedOprUtils
Rcpp::List bedOprUtils(Rcpp::List argvs, Rcpp::CharacterVector filterList);
RcppExport SEXP _esATAC_bedOprUtils(SEXP argvsSEXP, SEXP filterListSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type argvs(argvsSEXP);
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type filterList(filterListSEXP);
    rcpp_result_gen = Rcpp::wrap(bedOprUtils(argvs, filterList));
    return rcpp_result_gen;
END_RCPP
}
// lib_complex_qc
Rcpp::List lib_complex_qc(Rcpp::List argvs);
RcppExport SEXP _esATAC_lib_complex_qc(SEXP argvsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type argvs(argvsSEXP);
    rcpp_result_gen = Rcpp::wrap(lib_complex_qc(argvs));
    return rcpp_result_gen;
END_RCPP
}
// ChrDivi_wrapper
Rcpp::StringVector ChrDivi_wrapper(Rcpp::List argvs);
RcppExport SEXP _esATAC_ChrDivi_wrapper(SEXP argvsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type argvs(argvsSEXP);
    rcpp_result_gen = Rcpp::wrap(ChrDivi_wrapper(argvs));
    return rcpp_result_gen;
END_RCPP
}
// CutCountPre_wrapper
Rcpp::StringVector CutCountPre_wrapper(Rcpp::List argvs);
RcppExport SEXP _esATAC_CutCountPre_wrapper(SEXP argvsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type argvs(argvsSEXP);
    rcpp_result_gen = Rcpp::wrap(CutCountPre_wrapper(argvs));
    return rcpp_result_gen;
END_RCPP
}
// CutSiteCount_wrapper
int CutSiteCount_wrapper(Rcpp::List argvs);
RcppExport SEXP _esATAC_CutSiteCount_wrapper(SEXP argvsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type argvs(argvsSEXP);
    rcpp_result_gen = Rcpp::wrap(CutSiteCount_wrapper(argvs));
    return rcpp_result_gen;
END_RCPP
}
// splitFragments
int splitFragments(std::string fragments, std::vector<std::string> cells, std::vector<std::string> idents, std::vector<std::string> unique_idents, std::string outdir, std::string suffix, int buffer_length, bool append, bool verbose);
RcppExport SEXP _esATAC_splitFragments(SEXP fragmentsSEXP, SEXP cellsSEXP, SEXP identsSEXP, SEXP unique_identsSEXP, SEXP outdirSEXP, SEXP suffixSEXP, SEXP buffer_lengthSEXP, SEXP appendSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type fragments(fragmentsSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type cells(cellsSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type idents(identsSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type unique_idents(unique_identsSEXP);
    Rcpp::traits::input_parameter< std::string >::type outdir(outdirSEXP);
    Rcpp::traits::input_parameter< std::string >::type suffix(suffixSEXP);
    Rcpp::traits::input_parameter< int >::type buffer_length(buffer_lengthSEXP);
    Rcpp::traits::input_parameter< bool >::type append(appendSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(splitFragments(fragments, cells, idents, unique_idents, outdir, suffix, buffer_length, append, verbose));
    return rcpp_result_gen;
END_RCPP
}
// validateCells
bool validateCells(std::string fragments, std::vector<std::string> cells, std::size_t find_n, std::size_t max_lines, bool verbose);
RcppExport SEXP _esATAC_validateCells(SEXP fragmentsSEXP, SEXP cellsSEXP, SEXP find_nSEXP, SEXP max_linesSEXP, SEXP verboseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type fragments(fragmentsSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type cells(cellsSEXP);
    Rcpp::traits::input_parameter< std::size_t >::type find_n(find_nSEXP);
    Rcpp::traits::input_parameter< std::size_t >::type max_lines(max_linesSEXP);
    Rcpp::traits::input_parameter< bool >::type verbose(verboseSEXP);
    rcpp_result_gen = Rcpp::wrap(validateCells(fragments, cells, find_n, max_lines, verbose));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_esATAC_filterCells", (DL_FUNC) &_esATAC_filterCells, 5},
    {"_esATAC_groupCommand", (DL_FUNC) &_esATAC_groupCommand, 4},
    {"_esATAC_fastxrenamer", (DL_FUNC) &_esATAC_fastxrenamer, 1},
    {"_esATAC_sc_fastxrenamer", (DL_FUNC) &_esATAC_sc_fastxrenamer, 1},
    {"_esATAC_mergeFile", (DL_FUNC) &_esATAC_mergeFile, 2},
    {"_esATAC_R_sam2bed_wrapper", (DL_FUNC) &_esATAC_R_sam2bed_wrapper, 2},
    {"_esATAC_R_sam2bed_merge_wrapper", (DL_FUNC) &_esATAC_R_sam2bed_merge_wrapper, 2},
    {"_esATAC_bedOprUtils", (DL_FUNC) &_esATAC_bedOprUtils, 2},
    {"_esATAC_lib_complex_qc", (DL_FUNC) &_esATAC_lib_complex_qc, 1},
    {"_esATAC_ChrDivi_wrapper", (DL_FUNC) &_esATAC_ChrDivi_wrapper, 1},
    {"_esATAC_CutCountPre_wrapper", (DL_FUNC) &_esATAC_CutCountPre_wrapper, 1},
    {"_esATAC_CutSiteCount_wrapper", (DL_FUNC) &_esATAC_CutSiteCount_wrapper, 1},
    {"_esATAC_splitFragments", (DL_FUNC) &_esATAC_splitFragments, 9},
    {"_esATAC_validateCells", (DL_FUNC) &_esATAC_validateCells, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_esATAC(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
