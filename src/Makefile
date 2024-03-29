PROJECTDIR = $(CURDIR)
TEST_EXE = GraphTests
BUILDDIR=build
LINTER=$(CURDIR)/../materials/linters/.clang-format

ifeq ($(shell uname), Darwin)
	COMPILER21 = -DCMAKE_CXX_COMPILER="/usr/local/bin/g++"
endif


.PHONY: tests s21_graph.a s21_graph_algorithms.a
all: s21_graph.a s21_graph_algorithms.a install tests clean


install:
	cmake . -G "Unix Makefiles" -B $(BUILDDIR) && \
	cmake --build $(BUILDDIR) --target GraphApplication --config=Release


s21_graph.a:
	cmake . -G "Unix Makefiles" -B $(BUILDDIR) && \
	cmake --build $(BUILDDIR) --target s21_graph --config=Release


s21_graph_algorithms.a:
	cmake . -G "Unix Makefiles" -B $(BUILDDIR) && \
	cmake --build $(BUILDDIR) --target s21_graph_algorithms --config=Release


tests:
	cmake . -G "Unix Makefiles" -B $(BUILDDIR) && \
	cmake --build $(BUILDDIR) --target GraphTests --config=Release
	./$(TEST_EXE)


style:
	cp $(LINTER) .
	clang-format --verbose --Werror -n */*.cc */*.h */*/*.cc */*/*.h
	rm $(notdir $(LINTER))


clean:
	rm -rf build *.a $(TEST_EXE)

