INC_DIR:=./include/
SRC_DIR:=./src/
SRCS:=$(wildcard ./src/*.cpp)
LIBS:=
CXX:=g++
CXXFLAGS:= -Wall -g -std=c++11 $(addprefix -I, $(INC_DIR)) $(LIBS)
EXE:=./bin/main
$(EXE):$(SRCS)
	$(CXX) -o $(EXE) $(SRCS) $(CXXFLAGS)
clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
