targetFileName = foodDeliverySysterm
CC = g++
CCFLAGES = -o


# objects = BaseObject.o Person.o main.o
# objects = testCaseMakefile
# objects = testCase/testCase.o main.o
# objects =  TestCase.o main.o
# $(targetFileName) :  testCaseMakefile main.o
# 	g++ $(objects) -o $(targetFileName)

# $(targetFileName) :  testCase/TestCase.o main.o
# 	g++ testCase/TestCase.o main.o -o $(targetFileName)

# testCaseMakefile:
# 	cd testCase; make -f testCase.mk
# main.o: main.cpp testCaseMakefile
# 	g++ -c main.cpp

# TestCase.o: testCaseMakefile
# main.o : main.cpp testCase/TestCase.hpp

# BaseObject.o : base/BaseObject.cpp base/BaseObject.hpp
# 	g++ -c base/BaseObject.cpp

# Person.o : base/Person.cpp base/Person.hpp base/BaseObject.hpp
# 	g++ -c base/Person.cpp

# main.o : main.cpp base/Person.hpp
# 	g++ -c main.cpp

# ====测试model

# objs = base/BaseObject.o utils/StringUtil.o model/Comment.o main.o


objs := $(wildcard base/*.o) $(wildcard utils/*.o) $(wildcard model/*.o) main.o

$(targetFileName) : modelMakefile $(objs)
	g++ $(objs) -o $(targetFileName)

modelMakefile:
	cd model; make -f model.mk

main.o : main.cpp

.PHONY: clean
clean:
	rm -rf *.o; rm -rf */*.o
