EXE:=./bin/main
INC_DIR:=./include/ ./include/net/ ./include/threadpool/
SRC_DIR:=./src/ ./src/net/ ./src/threadpool/
SRCS:=$(wildcard ./src/*.cpp) $(wildcard ./src/net/*.cpp) $(wildcard ./src/net/*.c) $(wildcard ./src/threadpool/*.cpp)
LIBS:= -lpthread
CXX:=g++
CXXFLAGS:= -Wall -g -std=c++11 $(addprefix -I, $(INC_DIR)) $(LIBS)

EXE:=./bin/main

$(EXE):$(SRCS)
	$(CXX) -o $(EXE) $(SRCS) $(CXXFLAGS)
clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
