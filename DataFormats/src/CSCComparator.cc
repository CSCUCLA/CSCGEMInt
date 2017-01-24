
#include "../interface/CSCComparator.h"
namespace CSCGEMInt{


CSCComparator::CSCComparator(size16 HS, size16 timeWord) : timeWord(timeWord){
	comp = HS % 2;
	strip = 1 + (HS - comp) / 2;

}
int CSCComparator::getTimeBin() const {
	// Find first bin which fired, counting from 0
	size16 tbit=1;
	for(int i=0;i<16;++i) {
		if(tbit & timeWord) { return i;}
		tbit=tbit<<1;
	}
	return -1;
}

std::vector<int> CSCComparator::getTimeBinsOn() const {
	std::vector<int> tbins;
	size16 tbit = timeWord;
	const size16 one=1;
	for(int i=0;i<16;++i) {
		if(tbit & one) tbins.push_back(i);
		tbit=tbit>>1;
		if(tbit==0) break; // end already if no more bits set
	}
	return tbins;
}


float CSCComparator::getStripF() const {return float(strip)  + float(comp)/2 - 0.75; };
int CSCComparator::getStrip() const { return strip;}
int CSCComparator::getComp() const {return comp;}
int CSCComparator::getHS() const {return (getStrip() - 1) * 2 + getComp(); }
}
