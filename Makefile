CC ?= cc
CFLAGS ?= -O2 -Wall -Wextra -std=c11
all: recursion_demo
recursion_demo: src/main.c
	$(CC) $(CFLAGS) -o $@ $<
clean:
	rm -f recursion_demo
.PHONY: all clean
