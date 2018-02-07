#
# Make file for  iqSecureFunding system components
#
#
IBXOVER=/u01/ccw/rnd/xover



#CPPFLAGS=$(INCFLAGS)
IQLIBS = -liqSecureFunding
SDLIBS= -lbcMwServices -lbcCommon  -ltwSupport -lbcComSupports 

LINKLIBS= $(IQLIBS) $(ROGUELIBS) $(STDLIBS) $(ORALIBS) $(SDLIBS) $(BCHOSTLIBS)
LINKOBJS=  $(ROGUEOBJS) $(ORAOBJS)
########################  Objects to build #######################

STANDALONEOBJECTS=iqAccountOwnersTest.o 
OBJECTS=  iqSecureFunding.o iqPSecureFundingAccount.o iqPSecureFundingInquiry.o iqDSecureFundingInquiry.o 
SERVOBJS= iqXSecureFunding.o iqSSecureFndInq.o  
SERVICES= iqSSecureFndInq
SOURCES=${OBJECTS:.o=.cpp} ${SERVOBJS:.o=.cpp} ${STANDALONEOBJECTS:.o=.cpp}                                                                                    

###########################  Dependencies  ########################
.SUFFIXES: .cpp .C .cc .cxx .o

all : libiqSecureFunding.$(LIB_EXT) iqXSecureFunding
lib : libiqSecureFunding.$(LIB_EXT)
bin : iqXSecureFunding
cleanlink : 
	rm -f libiqSecureFunding.$(LIB_EXT) iqXSecureFunding

# must be below all: because it has target in it
include $(MAKEROOT)/MakeDefaults


IQINCFLAGS = -I../include $(INCFLAGS) 
IQLIBFAGS = -L../lib $(LIBFLAGS)
IQCPPFLAGS=  $(IQINCFLAGS) $(IQLIBFAGS) $(CPPFLAGS) $(DEBUG) $(SOURCEDEBUG)

include MakeDependencies

libiqSecureFunding.$(LIB_EXT) : $(OBJECTS)
	$(CC) $(LINKFLAGS) -o $@ $(IQCPPFLAGS) $(OBJECTS) 
	rm -f *~ ../include/*~
	cp $@ ../lib
	
iqXSecureFunding: $(SERVOBJS)
	buildserver -v -o iqXSecureFunding \
	-s $(SERVICES) \
	-f "$(BLDSRVRFLAGS) $(IQCPPFLAGS) $(SERVOBJS) $(BCOBJS) $(LINKOBJS) $(LINKLIBS)"
	cp iqXSecureFunding ../bin


wvxover:
	cp iqXSecureFunding $(WVXOVER)/bin
	cp libiqSecureFunding.$(LIB_EXT) $(WVXOVER)/lib
	chown cswdevl $(WVXOVER)/bin/iqXSecureFunding
	chown cswdevl $(WVXOVER)/lib/libiqSecureFunding.$(LIB_EXT) 
	
bcxover:
	cp iqXSecureFunding $(BCXOVER)/bin
	cp libiqSecureFunding.$(LIB_EXT) $(BCXOVER)/lib
	chown cswdevl $(BCXOVER)/bin/iqXSecureFunding
	chown cswdevl $(BCXOVER)/lib/libiqSecureFunding.$(LIB_EXT) 

ibxover:
	cp iqXSecureFunding $(IBXOVER)/bin
	cp libiqSecureFunding.$(LIB_EXT) $(IBXOVER)/lib	
	chown ccwrnd $(IBXOVER)/bin/iqXSecureFunding
	chown ccwrnd $(IBXOVER)/lib/libiqSecureFunding.$(LIB_EXT) 
	
clean:
	rm -f *.o
	rm -f *.$(LIB_EXT) 
	rm -f *~
	rm -f iqXSecureFunding MakeDependencies
	rm -f -r ptre*
	touch MakeDependencies

###########################  Dependencies  ########################
.SUFFIXES: .cpp .C .cc .cxx .o

.cpp.o:
	$(CC) $(COMPILEFLAGS) $< $(IQCPPFLAGS) $(SPECIAL) $(SOURCEDEBUG)
	
