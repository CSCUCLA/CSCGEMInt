#ifndef CSCGEMINT_DATAFORMATS_DETIDCONTAINER_H
#define CSCGEMINT_DATAFORMATS_DETIDCONTAINER_H
#include <map>

namespace CSCGEMInt{
template<typename DIDType, typename valType>
class DetIdContainer {
public:
	DetIdContainer();
	~DetIdContainer() {}
	void clear() {data.clear();}
	valType * get(const DIDType& detId) {
		std::map<DIDType,valType>::iterator it = data->find(detId);
		if(it == data->end()) return 0;
		return &(it->second);
	}
private:
	std::map<DIDType,valType> data;

};
}

#endif
