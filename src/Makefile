CXX = g++ -std=c++17
CXXFLAGS = -Wall -Werror -Wextra
PROJECTDIR = $(CURDIR)
GRAPH_STATICLIB = s21_graph.a
GRAPH_SOURCES = $(PROJECTDIR)/graph/s21_graph.cc
GRAPH_OBJECTS = $(GRAPH_SOURCES:.cc=.o)

GRAPH_ALG_STATICLIB = s21_graph_algorithms.a
GRAPH_ALG_SOURCES = $(PROJECTDIR)/graph/s21_graph_algorithms.cc
GRAPH_ALG_OBJECTS = $(GRAPH_ALG_SOURCES:.cc=.o)

TEST_SOURCES = \
	$(PROJECTDIR)/tests/main_tests.cc \
	$(PROJECTDIR)/tests/graph_algorithms_tests.cc \
	$(PROJECTDIR)/tests/graph_tests.cc \

TEST_EXE = GraphTests


all: $(GRAPH_STATICLIB) $(GRAPH_ALG_STATICLIB) tests clean


build: $(GRAPH_ALG_STATICLIB)
	g++ main.cc $(GRAPH_ALG_STATICLIB) $(GRAPH_STATICLIB)
	./a.exe


$(GRAPH_STATICLIB): $(GRAPH_OBJECTS)
	ar rcs $(GRAPH_STATICLIB) $^


$(GRAPH_ALG_STATICLIB): $(GRAPH_ALG_OBJECTS) $(GRAPH_STATICLIB)
	ar rcs $(GRAPH_ALG_STATICLIB) $^


tests: $(GRAPH_STATICLIB) $(GRAPH_ALG_STATICLIB)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) $^ -lgtest -o $(TEST_EXE)
	./$(TEST_EXE)


clean:
	rm -rf *.o */*.o


%.o: %.cc
	g++ -o $@ -c $<

