#ifndef CSCGEMINT_DATAFORMATS_TMB_H
#define CSCGEMINT_DATAFORMATS_TMB_H
#include <vector>


namespace CSCGEMInt{
class TMB {
public:
	TMB(std::string branchName = "tmb");
	virtual ~TMB();
};
}

#endif
