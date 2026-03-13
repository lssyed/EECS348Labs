# Define the compiler we are using
CC = gcc

# Define any compile-time flags (-Wall and -Wextra turn on useful warnings)
CFLAGS = -Wall -Wextra -std=c11

program2: program2.c
	$(CC) $(CFLAGS) program2.c -o program2

run: program2
	./program2
	
# A rule to clean up our directory (removes the executable)
clean:
	rm -f program2