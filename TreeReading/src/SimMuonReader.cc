
#include "../interface/SimMuonReader.h"
#include "AnalysisSupport/TreeInterface/interface/TreeReadingWrapper.h"
#include "DataFormats/interface/SimMuon.h"
#include "DataFormats/interface/CSCDetId.h"

namespace CSCGEMInt{

SimMuonReader::SimMuonReader(std::string branchName) : BaseReader(branchName), muons(new SimMuonCollection) {};
SimMuonReader::~SimMuonReader() {delete muons;}

void SimMuonReader::setup(TreeReadingWrapper * wrapper){
    wrapper->setBranchAddressPre(branchName, "pt"          , &pt          , true);
    wrapper->setBranchAddressPre(branchName, "eta"         , &eta         , true);
    wrapper->setBranchAddressPre(branchName, "phi"         , &phi         , true);
    wrapper->setBranchAddressPre(branchName, "charge"      , &charge      , true);
    wrapper->setBranchAddressPre(branchName, "csc_nHits"   , &csc_nHits   , false);
    wrapper->setBranchAddressPre(branchName, "csc_tpNumber", &csc_tpNumber, false);
    wrapper->setBranchAddressPre(branchName, "csc_detID"   , &csc_detID   , false);
    wrapper->setBranchAddressPre(branchName, "csc_strip"   , &csc_strip   , false);
    wrapper->setBranchAddressPre(branchName, "csc_wg"      , &csc_wg      , false);
    wrapper->setBranchAddressPre(branchName, "csc_w"       , &csc_w       , false);
    wrapper->setBranchAddressPre(branchName,"csc_stLink_nHits",& csc_stLink_nHits ,false);
    wrapper->setBranchAddressPre(branchName,"csc_stLink_detId",& csc_stLink_detId ,false);
    wrapper->setBranchAddressPre(branchName,"csc_stLink_strip",& csc_stLink_strip ,false);
    wrapper->setBranchAddressPre(branchName,"csc_wrLink_nHits",& csc_wrLink_nHits ,false);
    wrapper->setBranchAddressPre(branchName,"csc_wrLink_detId",& csc_wrLink_detId ,false);
    wrapper->setBranchAddressPre(branchName,"csc_wrLink_wire" ,& csc_wrLink_wire  ,false);
}

void SimMuonReader::processRun() {
	muons->clear();
	int cscIDX = 0;
	int cscStLinkIDX = 0;
	int cscWrLinkIDX = 0;
	for(unsigned int iM = 0; iM < pt->size(); ++iM){
		muons->emplace_back(CylLorentzVectorF(pt->at(iM), eta->at(iM), phi->at(iM),0.1056584),charge->at(iM));
		const unsigned int nCSCHits = csc_nHits->size() ? csc_nHits->at(iM) : 0;
		for(unsigned int iC = 0; iC < nCSCHits; iC++){
			CSCDetId detId(csc_detID->at(cscIDX));
			SimMuonCSCHit hit(csc_strip->at(cscIDX),csc_wg->at(cscIDX),csc_w->at(cscIDX));
			muons->back().addCSCHit(detId,hit);
			cscIDX++;
		}
		const unsigned int nStripLinks = csc_stLink_nHits->size() ? csc_stLink_nHits->at(iM) : 0;
		for(unsigned int iC = 0; iC < nStripLinks; iC++){
			CSCDetId detId(csc_stLink_detId->at(cscStLinkIDX));
			muons->back().addStripDigiLink(detId,csc_stLink_strip->at(cscStLinkIDX));
			cscStLinkIDX++;
		}
		const unsigned int nWireLinks = csc_wrLink_nHits->size() ? csc_wrLink_nHits->at(iM) : 0;
		for(unsigned int iC = 0; iC < nWireLinks; iC++){
			CSCDetId detId(csc_wrLink_detId->at(cscWrLinkIDX));
			muons->back().addWireDigiLink(detId,csc_wrLink_wire->at(cscWrLinkIDX));
			cscWrLinkIDX++;
		}

	}
}


}
