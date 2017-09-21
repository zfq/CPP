objs = BaseObject.o Person.o

all : $(objs)

BaseObject.o : BaseObject.cpp
Person.o : Person.cpp
