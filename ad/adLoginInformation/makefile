STANDALONEOBJECTS= adLoginInformationTest.o
OBJECTS= ControlBlockSupport.o adLoginInformation.o adPLoginInformation.o 
SERVOBJS= adXLoginInfo.o adSLoginInfo.o adSLoginInfo2.o
SERVICES= adSLoginInfo,adSLoginInfo2			

SOURCES=${OBJECTS:.o=.cpp} ${SERVOBJS:.o=.cpp} ${STANDALONEOBJECTS:.o=.cpp}

DEBUG=-g
SOURCEDEBUG=-D_DEBUG

all : crtest libadLoginInformation.$(LIB_EXT) adLoginInformationTest adXLoginInfo
#all : libadLoginInformation.$(LIB_EXT) adXLoginInfo 
lib : libadLoginInformation.$(LIB_EXT)
bin : adXLoginInfo
test : adLoginInformationTest
cleanlink :
	rm -f libadLoginInformation.$(LIB_EXT) adXLoginInfo adLoginInformationTest

include $(MAKEROOT)/MakeDefaults
SDLIBS= -lbcCommon -lbcComSupports -ltwSupport -lbcMwServices -lbcSecurity
MYLIB= -ladLoginInformation

LINKLIBS= $(BCLIBS) $(ROGUELIBS) $(STDLIBS) $(ORALIBS) $(SDLIBS) $(MYLIB)  $(GCLIBS)

include MakeDependencies 

ADINCFLAGS = -I../include $(INCFLAGS) 
ADLIBFAGS = -L../lib $(LIBFLAGS)
ADCPPFLAGS=  $(ADINCFLAGS) $(ADLIBFAGS) $(DEBUG) $(SOURCEDEBUG)


libadLoginInformation.$(LIB_EXT) : $(OBJECTS)
	$(CC) -o $@ $(ADCPPFLAGS) +Z -b  $(OBJECTS) 
	#cp $@ ../../bc/lib
	cp $@ ../lib
	rm -f *~ ../include/*~


adLoginInformationTest: $(STANDALONEOBJECTS)
	$(CC) -o adLoginInformationTest -g -Wl,-Bimmediate,+s,+vshlibunsats,-E $(CPPFLAGS) $(LIBFLAGS) $(STANDALONEOBJECTS) $(LINKOBJS) $(LINKLIBS)
	

adXLoginInfo: $(SERVOBJS)
	buildserver -v -o adXLoginInfo \
	-s $(SERVICES) \
	-f "-Wl,-Bimmediate,+s,+vshlibunsats -g $(CPPFLAGS) $(SERVOBJS) $(BCOBJS) $(LINKOBJS) $(LINKLIBS)"
	cp adXLoginInfo ../bin

clean:
	rm -f *.o *.$(LIB_EXT) *~ ULOG.*

###########################  Dependencies  ########################
.SUFFIXES: .cpp .C .cc .cxx .o

.cpp.o:                                                                                                     
	$(CC) -c $< +Z $(CPPFLAGS) $(ADCPPFLAGS) $(SPECIAL) $(SOURCEDEBUG) -I ../../bc/include
	

