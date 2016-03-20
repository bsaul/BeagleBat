# makefile for beaglebat 

CC = gcc
CFLAGS = -I.
DEPS = beaglebat.h
IDIR = ../include

all: beaglebat

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

beaglebat: alsa-record-example.o
	$(CC) -o src/alsa-record-example.c -lasound bin/beaglebat

clean:
	rm *o beaglebat