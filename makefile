targetFileName = foodDeliverySysterm
CC = g++
CCFLAGES = -o


# objects = BaseObject.o Person.o main.o
# objects = testCaseMakefile
# objects = testCase/testCase.o main.o
# objects =  TestCase.o main.o
# $(targetFileName) :  testCaseMakefile main.o
# 	g++ $(objects) -o $(targetFileName)


# ====测试model

# baseCs = $(notdir base/)
# tmp := $(allBaseFiles:%.cpp=%.o)

#base文件夹的所有的.o文件名称
baseDirPath = base
baseDirAllFiles := $(patsubst %.cpp,%.o,$(shell ls $(baseDirPath)))
baseDirTmpObjs := $(filter %.o, $(baseDirAllFiles))
baseDirAllObjs:=$(addprefix base/,$(baseDirTmpObjs))

#utils文件夹的所有.o文件名称
utilsDirPath = utils
utilsDirAllFiles := $(patsubst %.cpp,%.o,$(shell ls $(utilsDirPath)))
utilsDirTmpObjs := $(filter %.o, $(utilsDirAllFiles))
utilsDirAllObjs:=$(addprefix utils/,$(utilsDirTmpObjs))

#testCase文件夹的所有.o文件名称
testCaseDirPath = testCase
testCaseDirAllFiles := $(patsubst %.cpp,%.o,$(shell ls $(testCaseDirPath)))
testCaseDirTmpObjs := $(filter %.o, $(testCaseDirAllFiles))
testCaseDirAllObjs:=$(addprefix testCase/,$(testCaseDirTmpObjs))

#model文件夹的所有.o文件名称
modelDirPath = model
modelDirAllFiles := $(patsubst %.cpp,%.o,$(shell ls $(modelDirPath)))
modelDirTmpObjs := $(filter %.o, $(modelDirAllFiles))
modelDirAllObjs:=$(addprefix model/,$(modelDirTmpObjs))

objs = $(baseDirAllObjs) $(utilsDirAllObjs) $(modelDirAllObjs) $(testCaseDirAllObjs) main.o

# objs := $(wildcard base/*.o) $(wildcard utils/*.o) $(wildcard model/*.o) main.o

$(targetFileName) : modelMakefile testCaseMakefile $(objs)
	g++ -o $@ $(filter %.o, $^)


.PHONY:modelMakefile
modelMakefile:
	cd model; make -f model.mk;

.PHONY:testCaseMakefile
testCaseMakefile:
	cd testCase; make -f testCase.mk

main.o : main.cpp

.PHONY: clean
clean:
	rm -rf *.o; rm -rf */*.o;rm -rf $(targetFileName)
