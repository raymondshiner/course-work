all:	lab9

lab9:	cscd240Lab9.c lab9.c lab9.h ./utils/utils.o 
	gcc cscd240Lab9.c lab9.c ./utils/utils.o -o lab9
	
utils.o:	./utils/utils.c ./utils/utils.h
	gcc -c ./utils/utils.c

clean:
	rm ./utils/utils.o
	rm lab9