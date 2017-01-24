//--------------------------------------------------------------------------------------------------
// 
// Momemntum.h
// 
// Momentum class, used as base class for custom objects.
// 
// 
//--------------------------------------------------------------------------------------------------

#ifndef CSCGEMINT_DATAFORMATS_MOMENTUM_H
#define CSCGEMINT_DATAFORMATS_MOMENTUM_H

#include "AnalysisSupport/Utilities/interface/Types.h"
#include<TMathBase.h>
using namespace ASTypes;

// root compiler needs this to be defined in this namespace....odd
namespace CSCGEMInt {

typedef ROOT::Math::PtEtaPhiM4D<double>				                CylLorentzCoord;
typedef ROOT::Math::PtEtaPhiM4D<float> 				                CylLorentzCoordF;
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >	XYZTLorentzVectorF;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double> >	PtEtaPhiMLorentzVectorD;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >	PtEtaPhiMLorentzVectorF;
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >	CartLorentzVector;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double> >	CylLorentzVector;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >	CylLorentzVectorF;

}


namespace CSCGEMInt {
template <class CoordSystem>
class Momentum
{

public :
  Momentum() {}

  template <class InputCoordSystem>
  Momentum(ROOT::Math::LorentzVector<InputCoordSystem> inMomentum) : fMom(inMomentum) {}

  ~Momentum(){}

  // Functions to facilitate momentum operations
  float   pt()      const { return fMom.Pt();       }
  float   eta()     const { return fMom.Eta();      }
  float   absEta()  const { return TMath::Abs(fMom.Eta());}
  float   phi()     const { return fMom.Phi();      }
  float   mass()    const { return fMom.M();        }
  float   E()       const { return fMom.E();        }
  float   energy()  const { return fMom.E();        }
  float   Et()      const { return fMom.Et();       }
  float   mt()      const { return fMom.Mt();       }
  float   px()      const { return fMom.Px();       }
  float   py()      const { return fMom.Py();       }
  float   pz()      const { return fMom.Pz();       }
  float   p()       const { return fMom.P();        }
  float   y()       const { return fMom.Rapidity(); }
  float   theta()   const { return fMom.Theta();    }

  //Momentum getting and setting functions
  ROOT::Math::LorentzVector<CoordSystem>&        p4()         { return fMom; }
  const  ROOT::Math::LorentzVector<CoordSystem>& p4()   const { return fMom; }

  template< class Coords >
  void setP4(const ROOT::Math::LorentzVector<Coords> & v )    { fMom = v;    }

  //cout the momentum
  friend std::ostream& operator<<(std::ostream& os, const Momentum<CoordSystem>& m){
    os << "("<<m.pt()<<","<<m.eta()<<","<<m.phi()<<","<<m.mass()<<")";
    return os;
  }

private:
  ROOT::Math::LorentzVector<CoordSystem>	 fMom;

};

  typedef Momentum<CylLorentzCoord>  MomentumD;
  typedef Momentum<CylLorentzCoordF> MomentumF;

  typedef std::vector<MomentumD> MomentumDCollection;
  typedef std::vector<MomentumF> MomentumFCollection;

}

#endif
