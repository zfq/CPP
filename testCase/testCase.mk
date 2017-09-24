
# VPATH = /usr/local/include:../thirdParty/boost:../thirdParty/boost/smart_ptr
# VPATH = /usr/local/include/boost:/usr/local/include/boost/smart_ptr:../thirdParty/boost:../thirdParty/boost/smart_ptr
# vpath %.h ../thirdParty/boost
# vpath %.h ../thirdParty/boost/smart_ptr
testCaseAll : modelMakefile utilsMakefile TestCase.o

.PHONY:modelMakefile
modelMakefile :
	cd ../model; make -f model.mk

.PHONY:utilsMakefile
utilsMakefile:
	cd ../utils && make -f utils.mk

TestCase.o : TestCase.cpp
	g++ -I /usr/local/include  -c TestCase.cpp
# g++ -I $(boostPath) -c TestCase.cpp
# thirdPartyMakefile:
# 	cd ../thirdParty; make -f thirdParty.mk