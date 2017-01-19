
#if !defined(__CINT__) || defined(__MAKECINT__)
#include "TreeReading/interface/CSCGEMIntTupleAnalyzer.h"
#include "TreeReading/interface/TMBReader.h"

using namespace std;
using namespace CSCGEMInt;

class Analyzer : public CSCGEMIntTupleAnalyzer {
public:
  Analyzer(std::string fileName, std::string treeName) : CSCGEMIntTupleAnalyzer(fileName,treeName){
	  addReader(new TMBReader);
	  setup();
  }

  void runAEvent() {
	  cout << ((TMBReader*)readers.front())->comp_hs->size() <<endl;
  }



};

#endif

void studyComparators(std::string fileName ="output.root",std::string treeName = "Events",std::string outFileName = "plots.root"){
  Analyzer a(fileName,treeName);
  a.analyze();
}
