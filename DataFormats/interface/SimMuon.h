#ifndef CSCGEMINT_DATAFORMATS_SIMMUON_H
#define CSCGEMINT_DATAFORMATS_SIMMUON_H


#include "../interface/Momentum.h"
#include <vector>
#include <utility>

class CSCDetId;


namespace CSCGEMInt {

class SimMuonCSCHit {
public:
	SimMuonCSCHit(float strip, size8 wg, size w) : strip(strip), wg(wg), w(w) {}
	float getStrip() const { return strip;}
	int getWG() const { return wg;}
	int getWire() const { return w;}
private:
	float strip = 0;
	size8 wg = 0;
	size w = 0;
};

typedef std::vector<std::pair<CSCDetId,SimMuonCSCHit>> SimMuonCSCHitCollection;
typedef std::vector<std::pair<CSCDetId,size8> > DigiLinkCollection;


class SimMuon : public MomentumF
{
public :
	SimMuon() :charge_(0) {}

  template <class InputCoordSystem>
  SimMuon(const ROOT::Math::LorentzVector<InputCoordSystem>& inMomentum, int8 charge ) : MomentumF(inMomentum), charge_(charge) {}
  ~SimMuon(){}

  int charge() const;
  void addCSCHit(const CSCDetId& detId, const SimMuonCSCHit& hit );
  const SimMuonCSCHitCollection& getCSCHits() const;

  void addStripDigiLink(const CSCDetId& detId, const size8& strip );
  const DigiLinkCollection& getStripDigiLinks() const;
  void addWireDigiLink(const CSCDetId& detId, const size8& wg );
  const DigiLinkCollection& getWireDigiLinks() const;

protected :
  int8 charge_;
  SimMuonCSCHitCollection tmbHits;
  DigiLinkCollection strip_digiLinks;
  DigiLinkCollection wire_digiLinks;
};

typedef std::vector<SimMuon> SimMuonCollection;



}
#endif
