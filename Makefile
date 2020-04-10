CFLAGS = -g
test : main.o DirHelper.o CommandCP.o
	g++ main.o DirHelper.o CommandCP.o -o test
clean:
	rm *.o test
run:
	./test