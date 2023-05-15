EXE           = midnight-move-gen

SOURCES      := $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp)
SOURCES      += $(wildcard tests/*.cpp)

CXXFLAGS     := -O3 -Isrc -flto -std=c++20 -march=native -Wall -Wextra -Wno-deprecated -pedantic -DNDEBUG
LDFLAGS      :=

CXX          := g++
SUFFIX       :=

ifeq ($(OS), Darwin)
	CXXFLAGS += -fconstexpr-steps=900000000
else
    CXXFLAGS += -fconstexpr-ops-limit=900000000
endif

# Detect Windows
ifeq ($(OS), Windows_NT)
    DETECTED_OS := Windows
    SUFFIX   := .exe
    CXXFLAGS += -static
else
    DETECTED_OS := $(shell uname -s)
    CXXFLAGS += -pthread
endif

ifneq (,$(findstring clang,$(shell $(CXX) --version)))
    ifneq ($(DETECTED_OS),Darwin)
        LDFLAGS += -fuse-ld=lld
    endif
endif

OUT := $(EXE)$(SUFFIX)

.PHONY: all

all: $(EXE)
$(EXE) : $(SOURCES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(OUT) $(SOURCES)

clean:
	rm $(OUT)