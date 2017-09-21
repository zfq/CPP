
CC = g++
CPPFLAGS = -c -std=c++11


all : baseMakefile utilsMakefile Comment.o DeliveryDriver.o Dish.o Order.o Reply.o Restaurant.o User.o


Comment.o : Comment.cpp
DeliveryDriver.o : DeliveryDriver.cpp
Dish.o : Dish.cpp
Order.o : Order.cpp
Reply.o : Reply.cpp
Restaurant.o : Restaurant.cpp
User.o : User.cpp

baseMakefile:
	cd ../base && make -f base.mk
utilsMakefile:
	cd ../utils && make -f utils.mk

.PHONY: clean
clean :
	rm -rf *.o
