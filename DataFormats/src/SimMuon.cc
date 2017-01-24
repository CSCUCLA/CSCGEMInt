#include "../interface/SimMuon.h"
#include "DataFormats/interface/CSCDetId.h"

namespace CSCGEMInt {

int SimMuon::charge() const {return charge_;}
void SimMuon::addCSCHit(const CSCDetId& detId, const SimMuonCSCHit& hit ) {tmbHits.push_back(std::make_pair(detId,hit));}
const SimMuonCSCHitCollection& SimMuon::getCSCHits() const { return tmbHits;}


void SimMuon::addStripDigiLink(const CSCDetId& detId, const size8& strip ){
	strip_digiLinks.push_back(std::make_pair(detId,strip));
}
const DigiLinkCollection& SimMuon::getStripDigiLinks() const{ return strip_digiLinks;}
void SimMuon::addWireDigiLink(const CSCDetId& detId, const size8& wg ){
	strip_digiLinks.push_back(std::make_pair(detId,wg));
}
const DigiLinkCollection& SimMuon::getWireDigiLinks() const { return wire_digiLinks;}
}
