# For Makefiles, lines preceded with # are comment lines
# Remember, Makefiles are your friends. You do not want to be compiling
# files individually.
#
# Makefile for Matrix class
#
# Author: Arie
# Jan. 8, 2007
#

# some settings...
# use the gnu C++ compiler
CCC= g++
# list all warnings
CCCFLAGS = -Wall -g -std=c++11 -lX11

# all is called a target, memberTest is called a dependency
# ie. "the target all is dependent on the executable memberTest
all : matchTest 

# the target memberTest is dependent on member.o and membertest.o
# the following line is the required executable
matchTest : member.o matchTest.o match.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule compiling .cc to .o
# all .o file targets are dependent on the corresponding .cc files
%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

# Don't need next two lines because of the above default rule
# But no harm including them
# In the following two lines make knows that the .cc file is required in the
# current dependency so you can leave it out.  You can also leave out the
# corresponding executable line
member.o : member.h
match.o : match.h
matchTest.o : member.h match.h
clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f matchTest
