# Tests
CC=g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR=src
BUILDDIR=build
TESTDIR=tests

SRCEXT=cpp
SOURCES=$(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
TESTS=$(shell find $(TESTDIR) -type f -name *.$(SRCEXT))
OBJECTS=$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS=-g -Wall
LIB=
INC=-I include

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

# Tests
tester: build/matrix.o build/cholesky.o
	$(CC) $(CFLAGS) $(TESTS) $^ $(INC) $(LIB) -o bin/tester

clean:
	echo " Cleaning...";
	echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)



all:
	echo ${SOURCES}

#all: chol_alu.cpp
#	g++ -Wall -Wextra -std=c++11 -o chol_alu chol_alu.cpp -I.
