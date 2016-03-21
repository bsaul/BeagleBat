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
	$(CC) -o bin/beaglebat src/configure.c $(CFLAGS) 

clean:
	rm *o beaglebat