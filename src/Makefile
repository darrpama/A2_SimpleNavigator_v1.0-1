PROJECTDIR = $(CURDIR)
STATICLIB = s21_graph.a

GRAPH_SOURCES = $(PROJECTDIR)/s21_graph.cc
GRAPH_OBJECTS = $(GRAPH_SOURCES:.cc=.o)

build: $(STATICLIB)
	g++ main.cc $(STATICLIB)
	./a.exe

%.o: %.cc
	g++ -o $@ -c $<

$(STATICLIB): $(GRAPH_OBJECTS)
	ar rcs $(STATICLIB) $^
	rm -rf *.o
