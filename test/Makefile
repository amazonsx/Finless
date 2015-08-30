cc = gcc -ggdb -Wall -std=c99

base_header_test: base_header_test.o 
	$(cc) -o base base_header_test.o

base_header_test.o: base_header_test.c base_header_list.h \
	../include/base/list.h
	$(cc) -c base_header_test.c

clean:
	rm base base_header_test.o
