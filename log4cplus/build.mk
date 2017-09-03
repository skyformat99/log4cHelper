#This is the makefile of EpollTest

logcpp: main.o iLog.o
	g++   main.o iLog.o -o logcpp  -L./lib  -llog4cplus -lpthread -Wl,-rpath=./:./lib
main.o:main.cpp
	g++ -c main.cpp -I ./include/  -o main.o
iLog.o:iLog.cpp
	g++ -c iLog.cpp -I ./include/  -o iLog.o
clean:
	rm -f logcpp main.o