
allDao : baseMakefile BaseDao.o OrderDao.o

baseMakefile:
	cd ../base && make -f base.mk

BaseDao.o : BaseDao.cpp
#g++ -I /usr/local/include  -c BaseDao.cpp

OrderDao.o : OrderDao.cpp