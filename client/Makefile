CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LIB=-L../libs -lmuduo_base -lmuduo_net -lpthread
INC=-I../incs

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o, $(SRC))

cli: $(OBJ) 
	$(CC) -o $@ $(OBJ) $(LIB)
$(OBJ): %.o:%.c
	$(CC) $(INC) -c $<

clean:
	rm -f cli *.o
