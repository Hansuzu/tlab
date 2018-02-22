CC=g++
CFLAGS=-std=c++17 -O3 -march=native -Wall -Wextra -Iinclude -Wshadow -g



SRCDIR=src
TARGETDIR=bin
BUILDDIR=build
HEADERDIR=include

UFILES=$(SRCDIR)/usuffix.cpp $(HEADERDIR)/usuffix.h $(HEADERDIR)/vector.h
UFILESP=$(UFILES) $(BUILDDIR)/usuffix.o

UFILES_AR=$(HEADERDIR)/usuffix_array.cpp $(HEADERDIR)/usuffix_array.h

UFILES_FS=$(SRCDIR)/usuffix_fastset.cpp $(HEADERDIR)/usuffix.h $(HEADERDIR)/fastset.h $(HEADERDIR)/vector.h
UFILESP_FS=$(UFILES_FS) $(BUILDDIR)/usuffix_fastset.o

UFILES_SS=$(SRCDIR)/usuffix_stdset.cpp $(HEADERDIR)/usuffix.h $(HEADERDIR)/vector.h
UFILESP_SS=$(UFILES_FS) $(BUILDDIR)/usuffix_stdset.o

UFILES_BS=$(SRCDIR)/usuffix_binary_search.cpp $(HEADERDIR)/usuffix.h $(HEADERDIR)/vector.h
UFILESP_BS=$(UFILES_BS) $(BUILDDIR)/usuffix_binary_search.o


all:    $(TARGETDIR)/substring/suffixalgo $(TARGETDIR)/substring/suffixalgo_fastset $(TARGETDIR)/substring/suffixalgo_stdset $(TARGETDIR)/substring/suffixalgo_binary_search $(TARGETDIR)/substring/brute \
	$(TARGETDIR)/visualizer/visualize \
	$(TARGETDIR)/speedtest/speedtest $(TARGETDIR)/speedtest/speedtest_fastset $(TARGETDIR)/speedtest/speedtest_stdset $(TARGETDIR)/speedtest/speedtest_binary_search $(TARGETDIR)/speedtest/speedtest_array $(TARGETDIR)/speedtest/gener \
	$(BUILDDIR)/usuffix.o $(BUILDDIR)/usuffix_fastset.o $(BUILDDIR)/usuffix_stdset.o $(BUILDDIR)/usuffix_binary_search.o



$(TARGETDIR)/main: $(SRCDIR)/main.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/main.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/main



$(TARGETDIR)/substring/suffixalgo: $(SRCDIR)/substring/suffixalgo.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/suffixalgo.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/substring/suffixalgo

$(TARGETDIR)/substring/suffixalgo_fastset: $(SRCDIR)/substring/suffixalgo.cpp $(UFILESP_FS)
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/suffixalgo.cpp  $(BUILDDIR)/usuffix_fastset.o -o $(TARGETDIR)/substring/suffixalgo_fastset

$(TARGETDIR)/substring/suffixalgo_stdset: $(SRCDIR)/substring/suffixalgo.cpp $(UFILESP_SS)
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/suffixalgo.cpp  $(BUILDDIR)/usuffix_stdset.o -o $(TARGETDIR)/substring/suffixalgo_stdset

$(TARGETDIR)/substring/suffixalgo_binary_search: $(SRCDIR)/substring/suffixalgo.cpp $(UFILESP_BS)
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/suffixalgo.cpp  $(BUILDDIR)/usuffix_binary_search.o -o $(TARGETDIR)/substring/suffixalgo_binary_search

$(TARGETDIR)/substring/brute: $(SRCDIR)/substring/brute.cpp
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/brute.cpp -o $(TARGETDIR)/substring/brute



$(TARGETDIR)/visualizer/visualize: $(SRCDIR)/visualizer/visualize.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/visualizer/visualize.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/visualizer/visualize



$(TARGETDIR)/speedtest/speedtest: $(SRCDIR)/speedtest/speedtest.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/speedtest/speedtest

$(TARGETDIR)/speedtest/speedtest_array: $(SRCDIR)/speedtest/speedtest_array.cpp $(FUFILES_AR)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest_array.cpp  -o $(TARGETDIR)/speedtest/speedtest_array

$(TARGETDIR)/speedtest/speedtest_fastset: $(SRCDIR)/speedtest/speedtest.cpp $(UFILESP_FS)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest.cpp $(BUILDDIR)/usuffix_fastset.o -o $(TARGETDIR)/speedtest/speedtest_fastset

$(TARGETDIR)/speedtest/speedtest_stdset: $(SRCDIR)/speedtest/speedtest.cpp $(UFILESP_SS)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest.cpp $(BUILDDIR)/usuffix_stdset.o -o $(TARGETDIR)/speedtest/speedtest_stdset

$(TARGETDIR)/speedtest/speedtest_binary_search: $(SRCDIR)/speedtest/speedtest.cpp  $(UFILESP_BS)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest.cpp $(BUILDDIR)/usuffix_binary_search.o -o $(TARGETDIR)/speedtest/speedtest_binary_search

$(TARGETDIR)/speedtest/gener: $(SRCDIR)/speedtest/gener.cpp
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/gener.cpp  -o $(TARGETDIR)/speedtest/gener



$(BUILDDIR)/usuffix.o: $(UFILES)
	$(CC) $(CFLAGS) $(SRCDIR)/usuffix.cpp -o $(BUILDDIR)/usuffix.o -c 

$(BUILDDIR)/usuffix_fastset.o: $(UFILES_FS)
	$(CC) $(CFLAGS) $(SRCDIR)/usuffix_fastset.cpp -o $(BUILDDIR)/usuffix_fastset.o -c 

$(BUILDDIR)/usuffix_stdset.o: $(UFILES_SS)
	$(CC) $(CFLAGS) $(SRCDIR)/usuffix_stdset.cpp -o $(BUILDDIR)/usuffix_stdset.o -c 

$(BUILDDIR)/usuffix_binary_search.o: $(UFILES_BS)
	$(CC) $(CFLAGS) $(SRCDIR)/usuffix_binary_search.cpp -o $(BUILDDIR)/usuffix_binary_search.o -c 


clean:
	rm -f $(BUILDDIR)/*
