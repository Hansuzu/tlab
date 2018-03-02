CC=g++
CFLAGS=-std=c++17 -O3 -march=native -Wall -Wextra -Iinclude -Wshadow -g



SRCDIR=src
TARGETDIR=bin
BUILDDIR=build
HEADERDIR=include

UFILESC=$(SRCDIR)/usuffix.cpp $(HEADERDIR)/usuffix.h $(HEADERDIR)/vector.h $(HEADERDIR)/bitset.h 

UFILES=$(UFILESC) $(SRCDIR)/usuffixnode_vector.cpp $(HEADERDIR)/vector.h
UFILESP=$(UFILES) $(BUILDDIR)/usuffix.o

UFILES_AR=$(HEADERDIR)/usuffix_array.cpp $(HEADERDIR)/usuffix_array.h

UFILES_FS=$(UFILESC) $(SRCDIR)/usuffixnode_fastset.cpp $(HEADERDIR)/fastset.h
UFILESP_FS=$(UFILES_FS) $(BUILDDIR)/usuffix_fastset.o

UFILES_SS=$(UFILESC) $(SRCDIR)/usuffixnode_stdset.cpp
UFILESP_SS=$(UFILES_FS) $(BUILDDIR)/usuffix_stdset.o

UFILES_OV=$(UFILESC) $(SRCDIR)/usuffixnode_ordered_vector.cpp
UFILESP_OV=$(UFILES_OV) $(BUILDDIR)/usuffix_ordered_vector.o


all:    $(TARGETDIR)/substring/suffixalgo $(TARGETDIR)/substring/suffixalgo_fastset $(TARGETDIR)/substring/suffixalgo_stdset $(TARGETDIR)/substring/suffixalgo_ordered_vector $(TARGETDIR)/substring/brute \
	$(TARGETDIR)/LCS/lcs $(TARGETDIR)/LCS/brute \
	$(TARGETDIR)/visualizer/visualize \
	$(TARGETDIR)/speedtest/speedtest $(TARGETDIR)/speedtest/speedtest_fastset $(TARGETDIR)/speedtest/speedtest_stdset $(TARGETDIR)/speedtest/speedtest_ordered_vector $(TARGETDIR)/speedtest/speedtest_array $(TARGETDIR)/speedtest/gener \
	$(BUILDDIR)/usuffix.o $(BUILDDIR)/usuffix_fastset.o $(BUILDDIR)/usuffix_stdset.o $(BUILDDIR)/usuffix_ordered_vector.o



$(TARGETDIR)/main: $(SRCDIR)/main.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/main.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/main



$(TARGETDIR)/substring/suffixalgo: $(SRCDIR)/substring/suffixalgo.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/suffixalgo.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/substring/suffixalgo

$(TARGETDIR)/substring/suffixalgo_fastset: $(SRCDIR)/substring/suffixalgo.cpp $(UFILESP_FS)
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/suffixalgo.cpp  $(BUILDDIR)/usuffix_fastset.o -o $(TARGETDIR)/substring/suffixalgo_fastset

$(TARGETDIR)/substring/suffixalgo_stdset: $(SRCDIR)/substring/suffixalgo.cpp $(UFILESP_SS)
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/suffixalgo.cpp  $(BUILDDIR)/usuffix_stdset.o -o $(TARGETDIR)/substring/suffixalgo_stdset

$(TARGETDIR)/substring/suffixalgo_ordered_vector: $(SRCDIR)/substring/suffixalgo.cpp $(UFILESP_OV)
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/suffixalgo.cpp  $(BUILDDIR)/usuffix_ordered_vector.o -o $(TARGETDIR)/substring/suffixalgo_ordered_vector

$(TARGETDIR)/substring/brute: $(SRCDIR)/substring/brute.cpp
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/brute.cpp -o $(TARGETDIR)/substring/brute



$(TARGETDIR)/visualizer/visualize: $(SRCDIR)/visualizer/visualize.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/visualizer/visualize.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/visualizer/visualize


$(TARGETDIR)/LCS/lcs: $(SRCDIR)/LCS/lcs.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/LCS/lcs.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/LCS/lcs

$(TARGETDIR)/LCS/brute: $(SRCDIR)/LCS/brute.cpp
	$(CC) $(CFLAGS)  $(SRCDIR)/LCS/brute.cpp -o $(TARGETDIR)/LCS/brute



$(TARGETDIR)/speedtest/speedtest: $(SRCDIR)/speedtest/speedtest.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/speedtest/speedtest

$(TARGETDIR)/speedtest/speedtest_array: $(SRCDIR)/speedtest/speedtest_array.cpp $(FUFILES_AR)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest_array.cpp  -o $(TARGETDIR)/speedtest/speedtest_array

$(TARGETDIR)/speedtest/speedtest_fastset: $(SRCDIR)/speedtest/speedtest.cpp $(UFILESP_FS)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest.cpp $(BUILDDIR)/usuffix_fastset.o -o $(TARGETDIR)/speedtest/speedtest_fastset

$(TARGETDIR)/speedtest/speedtest_stdset: $(SRCDIR)/speedtest/speedtest.cpp $(UFILESP_SS)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest.cpp $(BUILDDIR)/usuffix_stdset.o -o $(TARGETDIR)/speedtest/speedtest_stdset

$(TARGETDIR)/speedtest/speedtest_ordered_vector: $(SRCDIR)/speedtest/speedtest.cpp  $(UFILESP_OV)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest.cpp $(BUILDDIR)/usuffix_ordered_vector.o -o $(TARGETDIR)/speedtest/speedtest_ordered_vector

$(TARGETDIR)/speedtest/gener: $(SRCDIR)/speedtest/gener.cpp
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/gener.cpp  -o $(TARGETDIR)/speedtest/gener



$(BUILDDIR)/usuffix.o: $(UFILES)
	$(CC) $(CFLAGS) $(SRCDIR)/usuffixnode_vector.cpp -o $(BUILDDIR)/usuffix.o -c 

$(BUILDDIR)/usuffix_fastset.o: $(UFILES_FS)
	$(CC) $(CFLAGS) $(SRCDIR)/usuffixnode_fastset.cpp -o $(BUILDDIR)/usuffix_fastset.o -c 

$(BUILDDIR)/usuffix_stdset.o: $(UFILES_SS)
	$(CC) $(CFLAGS) $(SRCDIR)/usuffixnode_stdset.cpp -o $(BUILDDIR)/usuffix_stdset.o -c 

$(BUILDDIR)/usuffix_ordered_vector.o: $(UFILES_OV)
	$(CC) $(CFLAGS) $(SRCDIR)/usuffixnode_ordered_vector.cpp -o $(BUILDDIR)/usuffix_ordered_vector.o -c 


clean:
	rm -f $(BUILDDIR)/*
