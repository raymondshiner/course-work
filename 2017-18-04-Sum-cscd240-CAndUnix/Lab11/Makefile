CC = gcc

all:	lab11

lab11:	cscd240Lab11.c  lab11.o ./utils/fileUtils.c ./utils/fileUtils.h ./utils/utils.c ./utils/utils.h
	gcc -m32 cscd240Lab11.c ./utils/fileUtils.c ./utils/utils.c lab11.o -o lab11

lab11.o:	lab11.c lab11.h
	gcc -c -m32 lab11.c

clean:
	rm lab11.o
	rm lab11

