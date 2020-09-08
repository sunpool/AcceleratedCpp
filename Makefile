#
# This does not work yet. Use following to compile
# 	g++ -std=c++17 -stdlib=libc++ *.cpp Str/Str.cpp Vec/Vec_clone.cpp
#


# CCFLAGS = -std=c++2a -O3
# LINKFLAGS = -lstdc++fs -lboost_timer

CC = gcc
CXX = g++
CXXFLAGS = -std=c++17
# LDFLAGS = -lstdc++fs

SRCS=$(ls *cpp */*cpp)
echo $(SRCS)
OBJS=$(subst, *cpp, *o, $SRCS)
echo $(OBJS)

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $@

Vec_clone.o: Vec/Vec_clone.cpp Vec/Vec.h 

Str.o: Str/Str.cpp Str/Str.h

clean:
	rm -rf *.o

clobber: clean
	rm -rf main
