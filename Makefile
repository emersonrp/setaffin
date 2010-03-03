
all:	setaffin.exe

setaffin.exe:

	gcc -mno-cygwin -o setaffin.exe setaffin.c

clean:
	rm -f *.o *.exe
