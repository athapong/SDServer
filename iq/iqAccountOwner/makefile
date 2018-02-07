#
# Make file for  iqAccountOwner system components
#
#
IBXOVER=/u01/ccw/rnd/xover



#CPPFLAGS=$(INCFLAGS)
IQLIBS = -liqAccountOwners
SDLIBS= -lbcAccountCommon  -lbcMwServices -lbcCommon  -ltwSupport -lbcComSupports 

LINKLIBS= $(IQLIBS) $(ROGUELIBS) $(STDLIBS) $(ORALIBS) $(SDLIBS) $(BCHOSTLIBS)
LINKOBJS=  $(ROGUEOBJS) $(ORAOBJS)
########################  Objects to build #######################

STANDALONEOBJECTS=iqAccountOwnersTest.o 
OBJECTS=  iqPAccountOwner.o iqDAccountOwner.o apptbl.o
SERVOBJS= iqXAccountOwners.o iqSAccountOwner.o  
SERVICES= iqSAccountOwner
SOURCES=${OBJECTS:.o=.cpp} ${SERVOBJS:.o=.cpp} ${STANDALONEOBJECTS:.o=.cpp}                                                                                    

###########################  Dependencies  ########################
.SUFFIXES: .cpp .C .cc .cxx .o

all : crtest1 crtest3 crtest4 libiqAccountOwners.$(LIB_EXT)  iqAccountOwnersTest iqXAccountOwners
lib : libiqAccountOwners.$(LIB_EXT)
bin : iqXAccountOwners
test : iqAccountOwnersTest
cleanlink : 
	rm -f libiqAccountOwners.$(LIB_EXT) iqXAccountOwners iqAccountOwnersTest

# must be below all: because it has target in it
include $(MAKEROOT)/MakeDefaults


IQINCFLAGS = -I../include $(INCFLAGS) 
IQLIBFAGS = -L../lib $(LIBFLAGS)
IQCPPFLAGS=  $(IQINCFLAGS) $(IQLIBFAGS) $(CPPFLAGS) $(DEBUG) $(SOURCEDEBUG)

include MakeDependencies

libiqAccountOwners.$(LIB_EXT) : $(OBJECTS)
	$(CC) $(LINKFLAGS) -o $@ $(IQCPPFLAGS) $(OBJECTS) 
	rm -f *~ ../include/*~
	cp $@ ../lib


iqAccountOwnersTest : $(STANDALONEOBJECTS)
	$(CC) -o $@ $(TESTFLAGS) $(IQCPPFLAGS) $(LIBFLAGS) $(STANDALONEOBJECTS) $(LINKOBJS) $(LINKLIBS)
	
iqXAccountOwners: $(SERVOBJS)
	buildserver -v -o iqXAccountOwners \
	-s $(SERVICES) \
	-f "$(BLDSRVRFLAGS) $(IQCPPFLAGS) $(SERVOBJS) $(BCOBJS) $(LINKOBJS) $(LINKLIBS)"
	cp iqXAccountOwners ../bin


wvxover:
	cp iqXAccountOwners $(WVXOVER)/bin
	cp libiqAccountOwners.$(LIB_EXT) $(WVXOVER)/lib
	chown cswdevl $(WVXOVER)/bin/iqXAccountOwners
	chown cswdevl $(WVXOVER)/lib/libiqAccountOwners.$(LIB_EXT) 
	
bcxover:
	cp iqXAccountOwners $(BCXOVER)/bin
	cp libiqAccountOwners.$(LIB_EXT) $(BCXOVER)/lib
	chown cswdevl $(BCXOVER)/bin/iqXAccountOwners
	chown cswdevl $(BCXOVER)/lib/libiqAccountOwners.$(LIB_EXT) 

ibxover:
	cp iqXAccountOwners $(IBXOVER)/bin
	cp libiqAccountOwners.$(LIB_EXT) $(IBXOVER)/lib	
	chown ccwrnd $(IBXOVER)/bin/iqXAccountOwners
	chown ccwrnd $(IBXOVER)/lib/libiqAccountOwners.$(LIB_EXT) 
	
clean:
	rm -f *.o
	rm -f *.$(LIB_EXT) 
	rm -f *~
	rm -f iqXAccountOwners iqAccountOwnersTest MakeDependencies crtest1 crtest3 crtest4
	rm -f -r ptre*
	touch MakeDependencies

###########################  Dependencies  ########################
.SUFFIXES: .cpp .C .cc .cxx .o

.cpp.o:
	$(CC) $(COMPILEFLAGS) $< $(IQCPPFLAGS) $(SPECIAL) $(SOURCEDEBUG)
	
