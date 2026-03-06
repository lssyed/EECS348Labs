# Define the compiler we are using
CC = gcc

# Define any compile-time flags (-Wall and -Wextra turn on useful warnings)
CFLAGS = -Wall -Wextra -std=c11

# Define the name of the final executable file
TARGET = program2

# The default rule that runs when you just type 'make'
all: $(TARGET)

# The rule to build our executable
$(TARGET): program2.c
	$(CC) $(CFLAGS) -o $(TARGET) program2.c

# A rule to clean up our directory (removes the executable)
clean:
	rm -f $(TARGET)