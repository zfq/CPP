targetFileName = foodDeliverySysterm
CC = g++
CCFLAGES = -o


objects = BaseObject.o Person.o main.o
$(targetFileName) :  $(objects)
	g++ $(objects) -o $(targetFileName)


BaseObject.o : base/BaseObject.cpp base/BaseObject.hpp
	g++ -c base/BaseObject.cpp

Person.o : base/Person.cpp base/Person.hpp base/BaseObject.hpp
	g++ -c base/Person.cpp

main.o : main.cpp base/Person.hpp
	g++ -c main.cpp


clean:
	rm -rf *.o
