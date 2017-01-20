
#if !defined(__CINT__) || defined(__MAKECINT__)
#include "TreeReading/interface/CSCGEMIntTupleAnalyzer.h"
#include "TreeReading/interface/TMBReader.h"

#include "DataFormats/interface/CSCDetId.h"
#include "DataFormats/interface/CSCComparator.h"
#include "DataFormats/interface/MuonDigiCollection.h"

using namespace std;
using namespace CSCGEMInt;

class Analyzer : public CSCGEMIntTupleAnalyzer {
public:
  Analyzer(std::string fileName, std::string treeName) : CSCGEMIntTupleAnalyzer(fileName,treeName){
	  addReader(new TMBReader);
	  setup();
  }

  void runAEvent() {

	  int nComps =0;
	  for(CSCComparatorCollection::DigiRangeIterator it = ((TMBReader*)readers.front())->comparators->begin();
		it != ((TMBReader*)readers.front())->comparators->end(); ++it){
		  auto comps = *it;
	  	  nComps += (comps.second.second - comps.second.first);
	  }
	  cout << nComps <<endl;
  }



};

#endif

void studyComparators(std::string fileName ="output.root",std::string treeName = "Events",std::string outFileName = "plots.root"){
  Analyzer a(fileName,treeName);
  a.analyze();
}
