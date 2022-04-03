
CXX = g++                         # The C++ compiler command
CXXFLAGS = -std=c++14 -Wall -g     # The C++ compiler options

# The all target builds all of the programs handled by the makefile.
all: hash_table

hash_table: main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Indicate that the all and clean targets do not
# correspond to actual files.
.PHONY: all clean

# The following rule is effectively built into make and
# therefore need not be explicitly specified:

	$(CXX) $(CXXFLAGS) -c $<

# The clean target removes all of the executable files
# and object files produced by the build process
clean :
	rm -f hash_table *.o core