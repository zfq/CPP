
CPPFLAGS = -g -c -std=c++11
allDao : baseMakefile modelMakefile BaseDao.o OrderDao.o

baseMakefile:
	cd ../base && make -f base.mk

modelMakefile:
	cd ../model && make -f model.mk

BaseDao.o : BaseDao.cpp
OrderDao.o : OrderDao.cpp