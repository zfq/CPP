all : StringUtil.o

StringUtil.o : StringUtil.cpp StringUtil.hpp
	g++ -c -std=c++11 StringUtil.cpp

clean :
	rm -rf *.o