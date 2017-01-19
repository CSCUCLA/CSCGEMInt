#include "../interface/CSCGEMIntTupleAnalyzer.h"
#include "../interface/BaseReader.h"

namespace CSCGEMInt {

CSCGEMIntTupleAnalyzer::CSCGEMIntTupleAnalyzer(std::string  fileName, std::string  treeName) : tree(fileName,treeName), eventNumber(0){}
CSCGEMIntTupleAnalyzer::~CSCGEMIntTupleAnalyzer() {for(auto * r : readers) delete r; }
void CSCGEMIntTupleAnalyzer::addReader(BaseReader * reader) {readers.push_back(reader);}
void CSCGEMIntTupleAnalyzer::setup() {for(auto * r : readers) r->setup(&tree);}

void CSCGEMIntTupleAnalyzer::analyze(int reportFrequency) {
    while(tree.readEvent(eventNumber, reportFrequency)){
    	for(auto * r : readers) r->processRun();
    	runAEvent();
    	eventNumber++;
    }
}


}
