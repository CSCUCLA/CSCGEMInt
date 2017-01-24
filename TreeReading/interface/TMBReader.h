#ifndef CSCGEMINT_TREEREADING_TMBREADER_H
#define CSCGEMINT_TREEREADING_TMBREADER_H
#include <vector>
#include <map>

#include "../../DataFormats/interface/CSCDetId.h"
#include "TreeReading/interface/BaseReader.h"

#include "DataFormats/interface/TMBTypes.h"

namespace CSCGEMInt{
class TMBReader : public BaseReader {
public:
	TMBReader(std::string branchName = "tmb");
	virtual ~TMBReader();
	virtual void setup(TreeReadingWrapper * wrapper);
	virtual void processRun();


	CSCComparatorCollection* comparators = 0;


private:
	std::vector<size  > * comp_detID         = new std::vector<size  >;
	std::vector<size16> * comp_hs            = new std::vector<size16>;
	std::vector<size16> * comp_timeBinWord   = new std::vector<size16>;



};
}

#endif
