CFLAGS = -g
test : main.o DirHelper.o CommandCP.o CommandCMP.o algori.o
	g++ main.o DirHelper.o CommandCMP.o CommandCP.o algori.o -o  test
clean:
	rm *.o test
run:
	./test