TGT = play
CC = g++
CFLAGS = -Wall -std=c++17

$(TGT): main.cpp tictagtoe.cpp
	$(CC) $(CFLAGS) main.cpp tictagtoe.cpp -o $(TGT)

.PHONY: clean
clean:
	rm -f $(TGT)
