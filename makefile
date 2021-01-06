CC=gcc 
CFLAGS=-std=c99 -Wall -pedantic

all: test_getbytes test_getbits test_bits2ull test_bits2ll test_spff test_dpff

test_getbytes: test_getbytes.c bandb.h bandb.o
	$(CC) $(CFLAGS) test_getbytes.c bandb.o -o test_getbytes

test_getbytes.o: test_getbytes.c bandb.h
	$(CC) $(CFLAGS) -c test_getbytes.c -o test_getbytes.o

test_getbits: test_getbits.c bandb.h bandb.o
	$(CC) $(CFLAGS) test_getbits.c bandb.o -o test_getbits

test_getbits.o: test_getbits.c bandb.h
	$(CC) $(CFLAGS) -c test_getbits.c -o test_getbits.o

test_bits2ull: test_bits2ull.c bandb.h bandb.o
	$(CC) $(CFLAGS) test_bits2ull.c bandb.o -o test_bits2ull

test_bits2ull.o: test_bits2ull.c bandb.h
	$(CC) $(CFLAGS) -c test_bits2ull.c -o test_bits2ull.o

test_bits2ll: test_bits2ll.c bandb.h bandb.o
	$(CC) $(CFLAGS) test_bits2ll.c bandb.o -o test_bits2ll

test_bits2ll.o: test_bits2ll.c bandb.h
	$(CC) $(CFLAGS) -c test_bits2ll.c -o test_bits2ll.o

test_spff: test_spff.c bandb.h bandb.o
	$(CC) $(CFLAGS) test_spff.c bandb.o -o test_spff

test_spff.o: test_spff.c bandb.h
	$(CC) $(CFLAGS) -c test_spff.c -o test_spff.o

test_dpff: test_dpff.c bandb.h bandb.o
	$(CC) $(CFLAGS) test_dpff.c bandb.o -o test_dpff

test_dpff.o: test_dpff.c bandb.h
	$(CC) $(CFLAGS) -c test_dpff.c -o test_dpff.o

bandb.o: bandb.c
	$(CC) $(CFLAGS) -c bandb.c -o bandb.o

clean:
	rm -f *.o test_bits2ll test_bits2ull test_dpff test_getbits test_getbytes test_spff
