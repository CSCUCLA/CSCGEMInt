#ifndef CSCGEMINT_DATAFORMATS_CSCCOMPARATOR_H
#define CSCGEMINT_DATAFORMATS_CSCCOMPARATOR_H
#include<vector>
#include "AnalysisSupport/Utilities/interface/Types.h"
using namespace ASTypes;

namespace CSCGEMInt{
class CSCComparator {
public:
	CSCComparator() {};
	CSCComparator(size16 HS, size16 timeWord);
	~CSCComparator() {};

	int getTimeBin() const;	//Get first time bin on
	std::vector<int> getTimeBinsOn() const; //fill 1 for the time bins on

	float getStripF() const; //get float version of strip (0-NStrips)
	int   getStrip() const; //get integer strip value
	int   getComp()  const; //get 0/1 (left/right) comparator
	int   getHS()    const; //Half strip

private:
	size16 timeWord = 0;
	size16 strip = 0;
	size16 comp = 0;

};
}

#endif
