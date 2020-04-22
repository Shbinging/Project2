CFLAGS = -g
test : CommandSH.o main.o DirHelper.o UI.o Commandbase.o CommandMAN.o CommandCP.o CommandCMP.o CommandWC.o CommandCAT.o CommandCD.o CommandLS.o algori.o
	g++ CommandSH.o main.o DirHelper.o UI.o Commandbase.o CommandCMP.o CommandCP.o CommandWC.o CommandCAT.o CommandMAN.o CommandCD.o CommandLS.o algori.o -o  test
clean:
	rm *.o test
run:
	./test