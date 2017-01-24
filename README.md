# CSCGEMInt
`git clone git@github.com:{USER}/CSCGEMInt.git`   
`cd CSCGEMInt`   
`git submodule init`   
`git submodule update`   
`make`      
`cd macros`   
`root -b -q studyComparators.C+`   

Make sure to add this to your default rootLogon.C:   
`gSystem->AddIncludePath(" -I{LOCALPATH}/CSCGEMInt ");`   
`gSystem->Load("{LOCALPATH}/CSCGEMInt/libCSCGEMIntTupleAnalysis.so");`   
Where {LOCALPATH} is the absolute path to the CSCGEMInt directory.
