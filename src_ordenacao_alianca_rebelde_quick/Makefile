# == VARIAVEIS ===
# ================
CC=g++ 
CFLAGS=-g -Wall -Wextra
EXEC=./tp2
TMPOUT=tp2.testresult

# === REGRAS =====
# ================
$(EXEC): main.cc quick.o
	$(CC) $(CFLAGS) main.cc quick.o -o $(EXEC)

quick.o: headers/quick.o
	$(CC) $(CFLAGS) -c headers/quick.cc -o quick.o

all: $(EXEC)
	$(EXEC)
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf quick.o quick headers/quick.o tp2