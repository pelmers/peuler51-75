CXX := g++
CFLAGS := -O2 -Wall -lm -lgmp -lgmpxx -funroll-loops -std=c++0x
TARGET_DIR := linux_bin
SRCS=$(wildcard *.cpp)
OUT=$(SRCS:.cpp=)

all: $(OUT)

clean:
	rm -f $(OUT)

% : %.c
	$(CXX) $(CFLAGS) $< -o $(TARGET_DIR)/$@
