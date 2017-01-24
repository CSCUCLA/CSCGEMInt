
#if !defined(__CINT__) || defined(__MAKECINT__)
#include "TreeReading/interface/CSCGEMIntTupleAnalyzer.h"
#include "TreeReading/interface/TMBReader.h"
#include "TreeReading/interface/SimMuonReader.h"

#include "DataFormats/interface/CSCDetId.h"
#include "DataFormats/interface/CSCComparator.h"
#include "DataFormats/interface/MuonDigiCollection.h"

#include "DataFormats/interface/SimMuon.h"

#include "AnalysisSupport/Utilities/interface/HistGetter.h"
#include<algorithm>
using namespace std;
using namespace CSCGEMInt;

class Analyzer : public CSCGEMIntTupleAnalyzer {
public:
  Analyzer(std::string fileName, std::string treeName) : CSCGEMIntTupleAnalyzer(fileName,treeName){
	  addReader(tmbReader);
	  addReader(simMuonReader);
	  setup();
  }

  void runAEvent() {


	  for(const auto& muon : (*simMuonReader->muons)) {
		  const auto& digiLinks = muon.getStripDigiLinks();
		  for(const auto& ch : muon.getCSCHits() ){
			  bool found = false;
			  for(unsigned int iL = 0; iL < digiLinks.size(); ++iL){
				  if(ch.first != digiLinks[iL].first) continue;
				  found = true;
				  break;
			  }
			  float minDist = 99;
			  //check to see if there was a strip hit made
			  auto comps = tmbReader->comparators->get(ch.first);
			  if(comps.first == comps.second) continue;
			  for(auto c = comps.first; c != comps.second; ++c ){
				  float dist= c->getStripF() - ch.second.getStrip();
				  minDist = TMath::Abs(dist) < TMath::Abs(minDist) ? dist: minDist;
			  }
		      plotter.getOrMake1D("dist",";comparator - sim hit (strips)",500,-10,10)->Fill(minDist);
		      if(found)plotter.getOrMake1D("good_dist",";comparator - sim hit (strips)",500,-10,10)->Fill(minDist);
		      if(TMath::Abs(minDist) > 1) cout << eventNumber <<" "<< ch.first <<" "<< ch.first.rawId() <<" "<< ch.second.getStrip() <<" "<< minDist << endl;

		  }
	  }

  }


  void write(TString fileName){ plotter.write(fileName);}

  TMBReader * tmbReader = new TMBReader;
  SimMuonReader * simMuonReader = new SimMuonReader;
  HistGetter plotter;

};

#endif

void studyComparators(std::string fileName ="output.root",std::string treeName = "Events",std::string outFileName = "plots.root"){
  Analyzer a(fileName,treeName);
  a.analyze();
  a.write(outFileName);
}
