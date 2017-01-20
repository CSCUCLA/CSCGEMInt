
#include "../interface/TMBReader.h"
#include "AnalysisSupport/TreeInterface/interface/TreeReadingWrapper.h"

#include "DataFormats/interface/CSCDetId.h"
#include "DataFormats/interface/CSCComparator.h"
#include "DataFormats/interface/MuonDigiCollection.h"

namespace CSCGEMInt{

TMBReader::TMBReader(std::string branchName) : BaseReader(branchName) {};
TMBReader::~TMBReader() {}

void TMBReader::setup(TreeReadingWrapper * wrapper){
    wrapper->setBranchAddressPre(branchName, "comp_detID"      ,&comp_detID      ,true);
    wrapper->setBranchAddressPre(branchName, "comp_hs"         ,&comp_hs         ,true);
    wrapper->setBranchAddressPre(branchName, "comp_timeBinWord",&comp_timeBinWord,true);
}

void TMBReader::processRun() {
	delete comparators;
	comparators = new CSCComparatorCollection;

	int curIDX = 0;
	for(unsigned int iD = 0; iD < comp_detID->size(); iD += 2){
		CSCDetId layId(comp_detID->at(iD));
		const size nComps = comp_detID->at(iD + 1 );
		std::vector<CSCComparator> comps; comps.reserve(nComps);
		for(unsigned int iC = 0; iC < nComps; ++iC){
			comps.emplace_back(comp_hs->at(curIDX),comp_timeBinWord->at(curIDX));
			curIDX++;
		}
		comparators->put(std::make_pair(comps.begin(),comps.end()), layId );
	}
}


}
