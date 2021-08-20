CC = gcc
#CFLAG = -I. -L.
#OBJS = main.o
OBJS = pstring.o
#LIBS = pstring
RUN = test

all: $(OBJS)
	ar rcs ../libpstring.a pstring.o


.c.o:
	$(CC) -c $^

	