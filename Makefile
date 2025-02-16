.PHONY: all run clean

BUILD = build
TARGET = $(BUILD)/snake
SRC_DIR = src

# Find all the C++ files to compile.
SRC = $(shell find $(SRC_DIR) -name '*.cpp')
OBJS= $(patsubst %.cpp, %.o, $(SRC))

# Link library and sanitizer flags.
ifeq ($(OS), Windows_NT)
	LIBS= -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
else
	LIBS= -lSDL2 -lSDL2_image
endif

CXXFLAGS = --std=c++20  -Wall -Wformat -Werror

# ===================
#    TARGET RULES
# ===================

all: $(TARGET)

$(TARGET): $(OBJS)
	@ mkdir -p $(BUILD)
	$(CXX) -o $@ $^ $(LIBS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

run:
	$(BUILD)/snake

clean:
	rm -rf $(BUILD) $(OBJS)
