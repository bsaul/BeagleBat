# makefile for beaglebat 

CC = gcc
CFLAGS = -I.
DEPS = beaglebat.h
IDIR = ../include

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

#beaglebat: src/alsa-record-example.c
#	$(CC) -o bin/beaglebat -lasound src/alsa-record-example.c $(CFLAGS) 

beaglebat: src/configure.c
	$(CC) -o bin/beaglebat -lconfig -lasound src/configure.c src/beaglebat.c src/record.c $(CFLAGS) 

clean:
	rm *o beaglebat