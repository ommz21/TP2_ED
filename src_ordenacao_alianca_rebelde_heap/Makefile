# == VARIAVEIS ===
# ================
CC=g++ 
CFLAGS=-g -Wall -Wextra
EXEC=./tp2
TMPOUT=tp2.testresult

# === REGRAS =====
# ================
$(EXEC): main.cc heap.o
	$(CC) $(CFLAGS) main.cc heap.o -o $(EXEC)

heap.o: headers/heap.o
	$(CC) $(CFLAGS) -c headers/heap.cc -o heap.o

all: $(EXEC)
	$(EXEC)
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf heap.o heap headers/heap.o tp2