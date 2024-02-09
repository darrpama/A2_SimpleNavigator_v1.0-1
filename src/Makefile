CXXFLAGS = -Wall -Werror -Wextra
PROJECTDIR = $(CURDIR)
TEST_EXE = GraphTests

ifeq ($(shell uname), Darwin)
	COMPILER21 = -DCMAKE_CXX_COMPILER="/usr/local/bin/g++"
endif


all: s21_graph.a s21_graph_algorithms.a tests clean

# for dbg only
build:
	mkdir -p build && cd build && \
	cmake ../ -DS21_GRAPH_ALGORITHMS=ON -G "Unix Makefiles" && make

	./SimpleNavigator.exe

install:
	mkdir -p build && cd build && \
	cmake ../ -DAPPLICATION=ON -DS21_GRAPH_ALGORITHMS=ON -G "Unix Makefiles" && make


s21_graph.a:
	mkdir -p build && cd build && \
	cmake ../ -DS21_GRAPH=ON -G "Unix Makefiles" && make


s21_graph_algorithms.a:
	mkdir -p build && cd build && \
	cmake ../ -DS21_GRAPH_ALGORITHMS=ON -G "Unix Makefiles" && make


tests:
	mkdir -p build && cd build && \
	cmake ../ $(COMPILER21) -DS21_GRAPH_ALGORITHMS=ON -DTESTING=ON -G "Unix Makefiles" && make
	./$(TEST_EXE)


clean:
	rm -rf build *.a $(TEST_EXE)

