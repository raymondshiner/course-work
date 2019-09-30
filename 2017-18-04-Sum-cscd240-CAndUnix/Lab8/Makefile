DIR=./utils/

all:	lab8

lab8:	cscd240Lab8.c lab8.o ${DIR}fileUtils.o
	gcc cscd240Lab8.c lab8.o ${DIR}fileUtils.o -o lab8

fileUtils.o:	${DIR}fileUtils.c ${DIR}fileUtils.h
	gcc -c ${DIR}fileUtils.c 

lab8.o:	lab8.h lab8.c
	gcc -c lab8.c

clean:
	rm ${DIR}fileUtils.o
	rm lab8.o
	rm lab8
