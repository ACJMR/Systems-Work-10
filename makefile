default: fileprac.o
	gcc fileprac.o
fileprac.o: fileprac.c
	gcc -c fileprac.c
run:
	./a.out
clean:
	rm -f *~ *.o *.exe *.out file
