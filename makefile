CC=g++
CFLAGS=-std=c++17 -O3 -march=native -Wall -Wextra -Iinclude -Wshadow -g



SRCDIR=src
TARGETDIR=bin
BUILDDIR=build
HEADERDIR=include

UFILES=$(SRCDIR)/usuffix.cpp $(HEADERDIR)/usuffix.h
UFILESP=$(UFILES) $(BUILDDIR)/usuffix.o


all: $(TARGETDIR)/main $(TARGETDIR)/substring/suffixalgo $(TARGETDIR)/visualizer/visualize $(TARGETDIR)/substring/brute $(TARGETDIR)/speedtest/speedtest $(TARGETDIR)/speedtest/speedtest_old $(BUILDDIR)/usuffix.o



$(TARGETDIR)/main: $(SRCDIR)/main.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/main.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/main

$(TARGETDIR)/substring/suffixalgo: $(SRCDIR)/substring/suffixalgo.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/suffixalgo.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/substring/suffixalgo

$(TARGETDIR)/substring/brute: $(SRCDIR)/substring/brute.cpp
	$(CC) $(CFLAGS)  $(SRCDIR)/substring/brute.cpp -o $(TARGETDIR)/substring/brute

$(TARGETDIR)/visualizer/visualize: $(SRCDIR)/visualizer/visualize.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/visualizer/visualize.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/visualizer/visualize

$(TARGETDIR)/speedtest/speedtest: $(SRCDIR)/speedtest/speedtest.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest.cpp  $(BUILDDIR)/usuffix.o -o $(TARGETDIR)/speedtest/speedtest
	
$(TARGETDIR)/speedtest/speedtest_old: $(SRCDIR)/speedtest/speedtest_old.cpp $(UFILESP)
	$(CC) $(CFLAGS)  $(SRCDIR)/speedtest/speedtest_old.cpp   -o $(TARGETDIR)/speedtest/speedtest_old

$(BUILDDIR)/usuffix.o: $(UFILES)
	$(CC) $(CFLAGS) $(SRCDIR)/usuffix.cpp -o $(BUILDDIR)/usuffix.o -c 

clean:
	rm -f $(BUILDDIR)/*
