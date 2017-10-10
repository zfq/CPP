
# VPATH = /usr/local/include:../thirdParty/boost:../thirdParty/boost/smart_ptr
# VPATH = /usr/local/include/boost:/usr/local/include/boost/smart_ptr:../thirdParty/boost:../thirdParty/boost/smart_ptr
# vpath %.h ../thirdParty/boost
# vpath %.h ../thirdParty/boost/smart_ptr
CPPFLAGS = -g -c -std=c++11
testCaseAll : modelMakefile utilsMakefile TestCase.o

.PHONY:modelMakefile
modelMakefile :
	cd ../model; make -f model.mk

.PHONY:utilsMakefile
utilsMakefile:
	cd ../utils && make -f utils.mk

TestCase.o : TestCase.cpp