#ifndef CSCGEMINT_TREEREADING_BASEREADER_H
#define CSCGEMINT_TREEREADING_BASEREADER_H
#include <string>
#include "../../../../AnalysisSupport/interface/Types.h"
using namespace AnalysisSupportTypes;

class TreeReadingWrapper;

namespace CSCGEMInt{
class BaseReader {
public:
	BaseReader(std::string branchName) : branchName(branchName) {};
	virtual ~BaseReader() {}
	virtual void setup(TreeReadingWrapper * wrapper) = 0; //set active branches
	virtual void processRun() = 0; //build objects

	std::string branchName;

};
}

#endif
