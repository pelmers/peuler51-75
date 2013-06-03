CC = g++
ARGS = -O2 -Wall -ffast-math -lm -lgmp -lgmpxx -funroll-loops -std=c++0x
TARGET_DIR = linux_bin

test:
	$(CC) euler_test_hpp.cpp -o test_hpp $(ARGS)

e51:
	$(CC) euler51.cpp -o $(TARGET_DIR)/eu51 $(ARGS)

e52:
	$(CC) euler52.cpp -o $(TARGET_DIR)/eu52 $(ARGS)

e53:
	$(CC) euler53.cpp -o $(TARGET_DIR)/eu53 $(ARGS)

e54:
	$(CC) euler54.cpp -o $(TARGET_DIR)/eu54 $(ARGS)
