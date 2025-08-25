CC = gcc
CFLAGS = -Wall -O2
SRC_DIR = src
SRC_FILE = supermarket_queue_simulator
SRC = $(SRC_DIR)/$(SRC_FILE).c
TARGET = $(SRC_FILE)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: all clean
