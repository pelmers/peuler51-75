ARGS = -O2 -Wall -lm -lgmp -lgmpxx -funroll-loops -std=c++0x
TARGET_DIR = linux_bin

all: test docs e51 e52 e53 e54 e55 e56 e57 e58 e59 e60 e61 e62 e63

test:
	$(CXX) euler_test_hpp.cpp -o test_hpp $(ARGS)

docs:
	doxygen Doxyfile

e51:
	$(CXX) euler51.cpp -o $(TARGET_DIR)/eu51 $(ARGS)

e52:
	$(CXX) euler52.cpp -o $(TARGET_DIR)/eu52 $(ARGS)

e53:
	$(CXX) euler53.cpp -o $(TARGET_DIR)/eu53 $(ARGS)

e54:
	$(CXX) euler54.cpp -o $(TARGET_DIR)/eu54 $(ARGS)

e55:
	$(CXX) euler55.cpp -o $(TARGET_DIR)/eu55 $(ARGS)

e56:
	$(CXX) euler56.cpp -o $(TARGET_DIR)/eu56 $(ARGS)

e57:
	$(CXX) euler57.cpp -o $(TARGET_DIR)/eu57 $(ARGS)

e58:
	$(CXX) euler58.cpp -o $(TARGET_DIR)/eu58 $(ARGS)

e59:
	$(CXX) euler59.cpp -o $(TARGET_DIR)/eu59 $(ARGS)

e60:
	$(CXX) euler60.cpp -o $(TARGET_DIR)/eu60 $(ARGS)

e61:
	$(CXX) euler61.cpp -o $(TARGET_DIR)/eu61 $(ARGS)

e62:
	$(CXX) euler62.cpp -o $(TARGET_DIR)/eu62 $(ARGS)

e63:
	$(CXX) euler63.cpp -o $(TARGET_DIR)/eu63 $(ARGS)
