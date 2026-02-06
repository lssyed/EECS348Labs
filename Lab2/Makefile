CC = gcc
CFLAGS = -Wall -I.

# Final executable name
TARGET = myProgram

# Link ALL object files (added isOdd.o)
$(TARGET): main.o isEven.o isOdd.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o isEven.o isOdd.o

# Compile main.c (added dependency on isOdd.h)
main.o: main.c isEven.h isOdd.h
	$(CC) $(CFLAGS) -c main.c

# Compile isEven.c
isEven.o: isEven.c isEven.h
	$(CC) $(CFLAGS) -c isEven.c

# Compile isOdd.c (New Rule!)
isOdd.o: isOdd.c isOdd.h
	$(CC) $(CFLAGS) -c isOdd.c

clean:
	rm -f *.o $(TARGET)
