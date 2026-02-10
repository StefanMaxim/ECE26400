CC = gcc

CFLAGS = -std=c99 -g -Wall -Wshadow -pedantic -Wvla -Werror \
         -DRUN_INTEGRATE -DTEST_INTEGRATE

LDLIBS = -lm

EXEC = hw4

# Source files
SRCS = integrator-hw4.c hw4.c func1.c func2.c func3.c func4.c func5.c
OBJS = $(SRCS:.c=.o)

TESTDIR = testcases
TESTS = $(wildcard $(TESTDIR)/*)

.PHONY: all clean testall

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

testall: $(EXEC)
	@for testfile in $(TESTS); do \
		echo "Running $$testfile"; \
		./$(EXEC) $$testfile output.txt; \
		cat output.txt; \
	done

clean:
	rm -f *.o
	rm -f testgen
	rm -f *.gcda *.gcno gmon.out *gcov
	rm -f $(EXEC) hw4.prof output.txt
