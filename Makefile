program_NAME := regalloc
program_C_SRC := $(wildcard *.c)
program_OBJS := ${program_C_SRC:.c=.o}
CC := gcc
CFLAGS := -g

.PHONY: all clean distclean

all: $(program_NAME)
$(program_NAME): $(program_OBJS)
	$(CC) $(CFLAGS) $(program_OBJS) -o $(program_NAME)


clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean
