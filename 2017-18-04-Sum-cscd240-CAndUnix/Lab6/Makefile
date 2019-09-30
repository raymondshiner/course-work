all:	lab6

lab6:	cscd240Lab6.c lab6.o fileUtils.o
	gcc cscd240Lab6.c lab6.o fileUtils.o -o lab6
	

lab6.o:	lab6.c lab6.h
	gcc -c lab6.c
	

fileUtils.o:	fileUtils.c fileUtils.h
	gcc -c fileUtils.c
	


clean:
	rm fileUtils.o
	rm lab6.o
	rm lab6
	