# Define the compiler we are using
CC = gcc

# Define any compile-time flags (-Wall and -Wextra turn on useful warnings)
CFLAGS = -Wall -Wextra -std=c11

program1: program1.c
	$(CC) $(CFLAGS) program1.c -o program1

run: program1
	./program1
# A rule to clean up our directory (removes the executable)
clean:
	rm -f program1