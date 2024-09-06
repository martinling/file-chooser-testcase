CFLAGS = $(shell pkg-config --cflags gtk4) -Wall -Wno-deprecated-declarations
LDFLAGS = $(shell pkg-config --libs gtk4)

file-chooser-testcase: src/main.c Makefile
	gcc $(CFLAGS) $< $(LDFLAGS) -o $@

run: file-chooser-testcase
	./$<
