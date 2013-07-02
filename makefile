ARGS = -O2 -Wall -lm -lgmp -lgmpxx -funroll-loops -std=c++0x
TARGET_DIR = linux_bin

all: docs e51 e52 e53 e54 e55 e56 e57 e58 e59 e60 e61 e62 e63 e64 e65 e66 e67 e68 e69

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

e64:
	$(CXX) euler64.cpp -o $(TARGET_DIR)/eu64 $(ARGS)

e65:
	$(CXX) euler65.cpp -o $(TARGET_DIR)/eu65 $(ARGS)

e66:
	$(CXX) euler66.cpp -o $(TARGET_DIR)/eu66 $(ARGS)

e67:
	$(CXX) euler67.cpp -o $(TARGET_DIR)/eu67 $(ARGS)

e68:
	$(CXX) euler68.cpp -o $(TARGET_DIR)/eu68 $(ARGS)

e69:
	$(CXX) euler69.cpp -o $(TARGET_DIR)/eu69 $(ARGS)
