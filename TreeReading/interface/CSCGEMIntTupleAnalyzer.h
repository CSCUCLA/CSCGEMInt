#ifndef CSCGEMINT_TREEREADING_BASETUPLEANALYZER_H
#define CSCGEMINT_TREEREADING_BASETUPLEANALYZER_H
#include "AnalysisSupport/TreeInterface/interface/TreeReadingWrapper.h"
#include "BaseReader.h"

namespace CSCGEMInt {
class CSCGEMIntTupleAnalyzer {
public:
	CSCGEMIntTupleAnalyzer(std::string  fileName, std::string  treeName);
	virtual ~CSCGEMIntTupleAnalyzer();
	virtual void addReader(BaseReader * reader);
	virtual void setup();
	virtual void analyze(int reportFrequency = 1000000);
	virtual void runAEvent() = 0;

protected:
  TreeReadingWrapper tree;
  int     eventNumber; //current event number
  std::vector<BaseReader*> readers;
};

}
#endif
