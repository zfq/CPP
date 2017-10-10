CPPFLAGS = -g -c -std=c++11
objs = BaseObject.o Person.o

all : $(objs)

BaseObject.o : BaseObject.cpp
Person.o : Person.cpp
