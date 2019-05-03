CC=gcc
LIBS=/home/users/mharmon/cs277/includes/libarch.a
INCLUDES=-I/home/users/mharmon/cs277/includes
FLAGS=-g -Wall -O0
EXEC=transpose


all: $(EXEC)

$(EXEC): *.o
	$(CC) $(FLAGS) -o $(EXEC) *.o $(LIBS)

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c *.c

clean:
	rm -f *.o $(LIB) $(EXEC)
