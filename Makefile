CC = gcc
CFLAGS = -Wall -Wextra
OBJS = main.o grid.o

main : $(OBJS)

clean : 
	$(RM) *.o main
