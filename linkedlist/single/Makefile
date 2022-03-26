CC=gcc
CFLAGS=-Wall -Wextra -pedantic -g -std=gnu11
LDFLAGS=-fsanitize=address -fsanitize=leak -fsanitize=undefined 
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

BINDIR=bin
BIN=$(BINDIR)/main
RM=rm

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.c createdir
	$(CC) $(CFLAGS) -c $< -o $@

createdir:
	mkdir $(OBJ) $(BINDIR)

clean:
	$(RM) -r $(BINDIR) $(OBJ)
