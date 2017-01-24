#ifndef CSCGEMINT_TREEREADING_SIMMUONREADER_H
#define CSCGEMINT_TREEREADING_SIMMUONREADER_H

#include "TreeReading/interface/BaseReader.h"
#include <vector>

namespace CSCGEMInt{

class SimMuon;
typedef std::vector<SimMuon> SimMuonCollection;

class SimMuonReader : public BaseReader {
public:
	SimMuonReader(std::string branchName = "simmuon");
	virtual ~SimMuonReader();
	virtual void setup(TreeReadingWrapper * wrapper);
	virtual void processRun();


	SimMuonCollection * muons;

private:
    std::vector<float> * pt            = new std::vector<float> ;
    std::vector<float> * eta           = new std::vector<float> ;
    std::vector<float> * phi           = new std::vector<float> ;
    std::vector<int8>  * charge        = new std::vector<int8>  ;
    std::vector<size8> * csc_nHits     = new std::vector<size8> ;
    std::vector<size8> * csc_tpNumber  = new std::vector<size8> ;
    std::vector<size>  * csc_detID     = new std::vector<size>  ;
    std::vector<float> * csc_strip     = new std::vector<float> ;
    std::vector<size8> * csc_wg        = new std::vector<size8> ;
    std::vector<size>  * csc_w         = new std::vector<size>  ;
    std::vector<size8> * csc_stLink_nHits  = new std::vector<size8>  ;
    std::vector<size>  * csc_stLink_detId  = new std::vector<size>   ;
    std::vector<size8> * csc_stLink_strip  = new std::vector<size8>  ;
    std::vector<size8> * csc_wrLink_nHits  = new std::vector<size8>  ;
    std::vector<size>  * csc_wrLink_detId  = new std::vector<size>   ;
    std::vector<size8> * csc_wrLink_wire   = new std::vector<size8>  ;
};
}

#endif
