CC = g++
CPPFLAGS = -c -std=c++11

objs = BaseObject.o Person.o

all : $(objs)

BaseObject.o : BaseObject.cpp BaseObject.hpp
	$(CC) $(CPPFLAGS) BaseObject.cpp

Person.o : Person.cpp Person.hpp BaseObject.hpp
	$(CC) $(CPPFLAGS) Person.cpp
