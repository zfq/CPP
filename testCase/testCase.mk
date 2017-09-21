testCaseAll : modelMakefile utilsMakefile TestCase.o

modelMakefile :
	cd ../model; make -f model.mk
utilsMakefile:
	cd ../utils && make -f utils.mk
TestCase.o : TestCase.cpp
# thirdPartyMakefile:
# 	cd ../thirdParty; make -f thirdParty.mk