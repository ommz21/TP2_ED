# == VARIAVEIS ===
# ================
CC=g++ 
CFLAGS=-g -Wall -Wextra
EXEC=./tp2
TMPOUT=tp2.testresult

# === REGRAS =====
# ================
$(EXEC): main.cc insertion.o
	$(CC) $(CFLAGS) main.cc insertion.o -o $(EXEC)

insertion.o: headers/insertion.o
	$(CC) $(CFLAGS) -c headers/insertion.cc -o insertion.o

all: $(EXEC)
	$(EXEC)
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf insertion.o insertion headers/insertion.o tp2