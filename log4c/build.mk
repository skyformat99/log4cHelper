
test: test.o iLog.o
	gcc test.o iLog.o -o test  -L./lib -llog4c -Wl,-rpath=.:..:lib
iLog.o: iLog.c
	gcc -c iLog.c -o iLog.o -I./include 

test.o:test.c
	gcc -c test.c  -o test.o -I./include
	
clean:
	rm test.o iLog.o test