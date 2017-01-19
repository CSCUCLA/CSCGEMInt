
#include "../interface/TMBReader.h"
#include "AnalysisSupport/TreeInterface/interface/TreeReadingWrapper.h"

namespace CSCGEMInt{

TMBReader::TMBReader(std::string branchName) : BaseReader(branchName) {};
TMBReader::~TMBReader() {}

void TMBReader::setup(TreeReadingWrapper * wrapper){
    wrapper->setBranchAddressPre(branchName, "comp_detID"      ,&comp_detID      ,true);
    wrapper->setBranchAddressPre(branchName, "comp_hs"         ,&comp_hs         ,true);
    wrapper->setBranchAddressPre(branchName, "comp_timeBinWord",&comp_timeBinWord,true);
}

void TMBReader::processRun() {};

}
