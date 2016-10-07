CXX = g++
CXXFLAGS = -W -Wall
ROOTLIBS = $(shell root-config --libs) -lMinuit -lTMVA
INCLUDES = -I./ -I$(shell root-config --incdir)

#Written by HOEE's brother.

TARGET = test
all : libTUnfolder.so $(TARGET)

$(TARGET) : test.o
	$(CXX) $(CXXFLAGS) $(ROOTLIBS) $(INCLUDES) -o $@ $^ -L. -lTUnfolder

test.o : test.cxx
	$(CXX) $(CXXFLAGS) $(ROOTLIBS) $(INCLUDES) -c $^ -o $@

libTUnfolder.so : TUnfolder.o GenerateTestTree.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) -shared -fPIC -o $@ $^

TUnfolder.o : TUnfolder.cxx
	$(CXX) $(CXXFLAGS) $(ROOTLIBS) $(INCLUDES) -fPIC -c $^ -o $@

GenerateTestTree.o : GenerateTestTree.cxx
	$(CXX) $(CXXFLAGS) $(ROOTLIBS) $(INCLUDES) -fPIC -c $^ -o $@

clean :
	rm -rfv test.o
	rm -rfv TUnfolder.o
	rm -rfv libTUnfolder.so
	rm -rfv GenerateTestTree.o
	rm -rfv test

