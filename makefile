targetFileName = foodDeliverySysterm
CC = g++
CCFLAGES = -o


# objs := $(wildcard base/*.o) $(wildcard utils/*.o) $(wildcard model/*.o) main.o
# -L thirdParty/mySqlConn/lib/libmysqlcppconn-static.a
$(targetFileName) : main.o
	g++  main.o -L/usr/local/lib -lmysqlcppconn -o $(targetFileName)   
# g++ -I /usr/local/include -L /usr/local/mysql/lib -L thirdParty/mySqlConn/lib -o main.o
# g++  main.o -L/usr/local/mysql/lib -LthirdParty/mySqlConn/lib -lmysqlcppconn -lmysqlclient_r -o $(targetFileName)   
#-L/usr/local/mysql/lib -LthirdParty/mySqlConn/lib

main.o : main.cpp
	g++ -I /usr/local/include -c main.cpp

# .PHONY: clean
# clean:
#     rm -rf *.o; rm -rf */*.o;rm -rf $(targetFileName)
