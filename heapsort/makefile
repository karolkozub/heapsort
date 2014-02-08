CC=g++
TAR=tar
ZIP=zip
RM=rm
CFLAGS=-Wall -g
DBGFLAGS=$(CFLAGS) -DDEBUG
SRC=heap.hh heapsort.hh main.cc
FILES=$(SRC) makefile
EXEC=heapsort
TARF=$(EXEC).tar.bz2
ZIPF=$(EXEC).zip

all: $(SRC)
	$(CC) main.cc -o $(EXEC) $(CFLAGS)

debug: $(SRC)
	$(CC) main.cc -o $(EXEC) $(DBGFLAGS)

tar:
	$(TAR) cjvf $(TARF) $(FILES)

zip:
	$(ZIP) $(ZIPF) $(FILES)

clean:
	-$(RM) -f *~ $(EXEC) $(TARF) $(ZIPF)
