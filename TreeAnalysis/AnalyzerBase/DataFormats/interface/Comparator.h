#ifndef CSCGEMINT_DATAFORMATS_TMB_H
#define CSCGEMINT_DATAFORMATS_TMB_H
#include "../../../../AnalysisSupport/interface/Types.h"
using namespace AnalysisSupportTypes;

namespace CSCGEMInt{
class Comparator {
public:
	Comparator();
	Comparator(size16 HS, size16 timeWord);
	virtual ~Comparator(Comparator);

	size16 HS = 0;
	size16 timeWord = 0;
};
}

#endif
