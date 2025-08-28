CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -g -O0
OBJ = main.o square.o output.o testing.o

solve: $(OBJ)
	$(CC) $(OBJ) -o solve -lm

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) solve

.PHONY: clean
