CC = gcc
CFLAGS = -lm -Wall -Werror -std=c17

adt_path := src/modules/
feat_path := src/

email := $(adt_path)email/
user := $(adt_path)user/
mesinKata := $(adt_path)mesinKata/
prioqueue := $(adt_path)priorityQueue/
narytree := $(adt_path)naryTree/
Datetime := $(adt_path)Datetime/
matrix := $(adt_path)matrix/
stack := $(adt_path)stack/

perintah := $(feat_path)perintah/
load := $(feat_path)load/
save := $(feat_path)save/
inisialisasi := $(feat_path)inisialisasi/

# Ensure the bin directory exists
bin_dir:
	mkdir -p bin

# Compile all C files in the src, src/* and src/*/* directories
build: bin_dir
	$(CC) $(CFLAGS) $(filter-out src/driver.c src/*/driver.c src/*/*/driver.c, $(wildcard src/*.c src/*/*.c src/*/*/*.c)) -o bin/main.out

build_debug: bin_dir
	$(CC) $(CFLAGS) -g $(filter-out src/driver.c src/*/driver.c src/*/*/driver.c, $(wildcard src/*.c src/*/*.c src/*/*/*.c)) -o bin/main.out

# Run the compiled program
run:
	./bin/main.out

run_debug:
	gdb ./bin/main.out

# Compile and run the program
all: build run

debug: build_debug run_debug

# Clean up the compiled program
clean:
	rm -f bin/main.out bin/mesinKata.out

buildmesinKata: bin_dir
	$(CC) $(CFLAGS) $(filter-out src/*/*/driver.c, $(wildcard src/modules/mesinKata/*.c)) -o bin/mesinKata.out

runmesinKata:
	./bin/mesinKata.out