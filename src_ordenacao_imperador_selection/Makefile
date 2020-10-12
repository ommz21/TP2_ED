# == VARIAVEIS ===
# ================
CC=g++ 
CFLAGS=-g -Wall -Wextra
EXEC=./selection
TMPOUT=selection.testresult

# === REGRAS =====
# ================
$(EXEC): main.cc selection.o
	$(CC) $(CFLAGS) main.cc selection.o -o $(EXEC)

selection.o: headers/selection.o
	$(CC) $(CFLAGS) -c headers/selection.cc -o selection.o

all: $(EXEC)
	$(EXEC)
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf selection.o selection headers/selection.o