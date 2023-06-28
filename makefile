BIN = ./bin
SRC = ./src
OBJ = ./obj

HASH_SRC = $(SRC)/hash_tab
HASH_OBJ = $(OBJ)/hash_tab
HASH_NAME = $(BIN)/hashtab

HASH_SRC_MAIN = $(HASH_SRC)/main.c
HASH_SRC_FUNC = $(HASH_SRC)/hash_tab.c

HASH_OBJ_MAIN = $(HASH_OBJ)/main.o
HASH_OBJ_FUNC = $(HASH_OBJ)/hash_tab.o

PHONY: hashtab

hashtab : $(HASH_NAME)
$(HASH_NAME) : $(HASH_OBJ_FUNC) $(HASH_OBJ_MAIN)
	gcc -Wall -o $(HASH_NAME) $(HASH_OBJ_MAIN) $(HASH_OBJ_FUNC)
$(HASH_OBJ_FUNC) : $(HASH_SRC_FUNC)
	gcc -Wall -I $(HASH_SRC) -o $(HASH_OBJ_FUNC) -c $(HASH_SRC_FUNC)
$(HASH_OBJ_MAIN) : $(HASH_SRC_MAIN)
	gcc -Wall -I $(HASH_SRC) -o $(HASH_OBJ_MAIN) -c $(HASH_SRC_MAIN)