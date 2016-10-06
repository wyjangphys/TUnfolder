CXX = g++
CXXFLAGS = -W -Wall
ROOTLIBS = $(shell root-config --libs) -lMinuit -lTMVA
INCLUDES = -I./

TARGET = test
all : $(TARGET) libTUnfolder.so

$(TARGET) : test.o TUnfolder.o
	$(CXX) $(CXXFLAGS) $(ROOTLIBS) $(INCLUDES) -o $@ $^ -L. -lTUnfolder

test.o : test.cxx
	$(CXX) $(CXXFLAGS) $(ROOTLIBS) $(INCLUDES) -c $^ -o $@

TUnfolder.o : TUnfolder.cxx
	$(CXX) $(CXXFLAGS) $(ROOTLIBS) $(INCLUDES) -fPIC -c $^ -o $@

libTUnfolder.so : TUnfolder.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) -shared -fPIC -o $@ $^

clean :
	rm -rfv test.o
	rm -rfv TUnfolder.o
	rm -rfv libTUnfoler.so
	rm -rfv test
