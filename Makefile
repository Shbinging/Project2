CFLAGS = -g
test : main.o DirHelper.o 
	g++ main.o DirHelper.o -o test
DirHelper.o : DirHelper.h diag.h
	g++ -g -c DirHelper.cpp
main.o: diag.h DirHelper.h
	g++ -g -c main.cpp
clean:
	rm *.o test
run:
	./test