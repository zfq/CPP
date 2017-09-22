testCaseAll : modelMakefile utilsMakefile TestCase.o

.PHONY:modelMakefile
modelMakefile :
	cd ../model; make -f model.mk

.PHONY:utilsMakefile
utilsMakefile:
	cd ../utils && make -f utils.mk

TestCase.o : TestCase.cpp
# thirdPartyMakefile:
# 	cd ../thirdParty; make -f thirdParty.mk