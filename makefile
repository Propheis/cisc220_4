#Deven Bernard - 10099810
#Marissa Huang - 10179169
#Kevin Zuern - 10134425
#Quentin Petraroia - 10145835

#Rule 1
mystring.o: mystring.c mystring.h
	gcc -Wall -c mystring.c

#Rule 2
main.o: main.c
	gcc -Wall -c main.c
#Rule 3
copier: main.o mystring.o
	gcc -Wall -o main.o mystring.o

