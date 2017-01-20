include $(ROOTSYS)/etc/Makefile.arch

CXXFLAGS += -I../.. -I.

ifeq ($(PLATFORM),macosx)
CXXFLAGS += -std=c++11
endif


TARGET=libCSCGEMIntTupleAnalysis.so

ASTREEINT = AnalysisSupport/TreeInterface/src
ASUTILITIES = AnalysisSupport/Utilities/src
TREEREADING = TreeReading/src
DATAFORMATS = DataFormats/src

SOURCE = $(wildcard $(ASTREEINT)/*.cc) $(wildcard $(ASUTILITIES)/*.cc) $(wildcard $(TREEREADING)/*.cc) $(wildcard $(DATAFORMATS)/*.cc)
OBJ=$(join $(addsuffix ../obj/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cc=.o))) 
DEPENDS=$(join $(addsuffix ../.dep/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cc=.d)))


all:  $(TARGET)
	@true
clean:
	@-rm -f $(TARGET) $(OBJ) $(DEPENDS)
        
        
$(TARGET): $(OBJ)
	@echo "============="
	@echo "Linking the target $@"
	@echo "============="
ifeq ($(PLATFORM),macosx)
		$(LD) $(SOFLAGS)$@ $(LDFLAGS) $^ $(OutPutOpt) $@ $(EXPLLINKLIBS)
else
		$(LD) $(SOFLAGS) $(LDFLAGS) $^ $(OutPutOpt) $@ $(EXPLLINKLIBS) 
endif
	@echo -- Link finished --
        
%.o : %.cc
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $<  -o $@

$(ASTREEINT)/../obj/%.o : $(ASTREEINT)/%.cc
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $<  -o $@
$(ASTREEINT)/../.dep/%.d: $(ASTREEINT)/%.cc
	@mkdir -p $(dir $@)
	@echo "============="
	@echo Building dependencies file for $*.o
	@$(SHELL) -ec '$(CXX) -M $(CXXFLAGS) $< | sed "s^$*.o^$(ASTREEINT)/../obj/$*.o^" > $@'
	
$(ASUTILITIES)/../obj/%.o : $(ASUTILITIES)/%.cc
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $<  -o $@
$(ASUTILITIES)/../.dep/%.d: $(ASUTILITIES)/%.cc
	@mkdir -p $(dir $@)
	@echo "============="
	@echo Building dependencies file for $*.o
	@$(SHELL) -ec '$(CXX) -M $(CXXFLAGS) $< | sed "s^$*.o^$(ASUTILITIES)/../obj/$*.o^" > $@'

$(TREEREADING)/../obj/%.o : $(TREEREADING)/%.cc
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $<  -o $@
$(TREEREADING)/../.dep/%.d: $(TREEREADING)/%.cc
	@mkdir -p $(dir $@)
	@echo "============="
	@echo Building dependencies file for $*.o
	@$(SHELL) -ec '$(CXX) -M $(CXXFLAGS) $< | sed "s^$*.o^$(TREEREADING)/../obj/$*.o^" > $@'
	
$(DATAFORMATS)/../obj/%.o : $(DATAFORMATS)/%.cc
	@mkdir -p $(dir $@)
	@echo "============="
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $<  -o $@
$(DATAFORMATS)/../.dep/%.d: $(DATAFORMATS)/%.cc
	@mkdir -p $(dir $@)
	@echo "============="
	@echo Building dependencies file for $*.o
	@$(SHELL) -ec '$(CXX) -M $(CXXFLAGS) $< | sed "s^$*.o^$(DATAFORMATS)/../obj/$*.o^" > $@'
	
	

-include $(DEPENDS)


#CC=g++
#TARGET=cppTest
#OTHERDIR=../../someotherpath/in/project/src
#
#SOURCE = cppTest.cpp
#SOURCE = $(OTHERDIR)/file.cpp
#
### End sources definition
#INCLUDE = -I./ $(AN_INCLUDE_DIR)  
#INCLUDE = -I.$(OTHERDIR)/../inc
### end more includes
#
#VPATH=$(OTHERDIR)
#OBJ=$(join $(addsuffix ../obj/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.o))) 
#
### Fix dependency destination to be ../.dep relative to the src dir
#DEPENDS=$(join $(addsuffix ../.dep/, $(dir $(SOURCE))), $(notdir $(SOURCE:.cpp=.d)))
#
### Default rule executed
#all: $(TARGET)
#        @true
#
### Clean Rule
#clean:
#        @-rm -f $(TARGET) $(OBJ) $(DEPENDS)
#
#
### Rule for making the actual target
#$(TARGET): $(OBJ)
#        @echo "============="
#        @echo "Linking the target $@"
#        @echo "============="
#        @$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
#        @echo -- Link finished --
#
### Generic compilation rule
#%.o : %.cpp
#        @mkdir -p $(dir $@)
#        @echo "============="
#        @echo "Compiling $<"
#        @$(CC) $(CFLAGS) -c $< -o $@
#
#
### Rules for object files from cpp files
### Object file for each file is put in obj directory
### one level up from the actual source directory.
#../obj/%.o : %.cpp
#        @mkdir -p $(dir $@)
#        @echo "============="
#        @echo "Compiling $<"
#        @$(CC) $(CFLAGS) -c $< -o $@
#
## Rule for "other directory"  You will need one per "other" dir
#$(OTHERDIR)/../obj/%.o : %.cpp
#        @mkdir -p $(dir $@)
#        @echo "============="
#        @echo "Compiling $<"
#        @$(CC) $(CFLAGS) -c $< -o $@
#
### Make dependancy rules
#../.dep/%.d: %.cpp
#        @mkdir -p $(dir $@)
#        @echo "============="
#        @echo Building dependencies file for $*.o
#        @$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^../obj/$*.o^" > $@'
#
### Dependency rule for "other" directory
#$(OTHERDIR)/../.dep/%.d: %.cpp
#        @mkdir -p $(dir $@)
#        @echo "============="
#        @echo Building dependencies file for $*.o
#        @$(SHELL) -ec '$(CC) -M $(CFLAGS) $< | sed "s^$*.o^$(OTHERDIR)/../obj/$*.o^" > $@'
#
### Include the dependency files
#-include $(DEPENDS)
