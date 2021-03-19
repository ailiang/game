CC=g++
CPPFLAGS=-Wall -std=c++11 -ggdb
LIB=-L../libs -lmuduo_base -lmuduo_net -lpthread -lmysqlcppconn
INC=-I../incs

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o, $(SRC))

serv: $(OBJ) 
	$(CC) -o $@ $(OBJ) $(LIB)
$(OBJ): %.o:%.c
	$(CC) $(INC) -c $<

clean:
	rm -f serv *.o
