CC := gcc

EXEC := programa-principal
FLAGS := -std=c11 -Wall -Wextra -Wdouble-promotion -Werror=pedantic -Werror=vla -pedantic-errors -Wfatal-errors

LIBS := -lm `pkg-config --libs glib-2.0`
PKG_CONFIG := `pkg-config --cflags glib-2.0`
INC := -I includes/
SRC := $(shell find src/ -name "*.c")
OBJ := $(SRC:src/%.c=build/%.o)

EXEC_TEST := programa-testes
FLAGS_TEST := $(FLAGS) -Wno-unused-function
INC_TEST := $(INC)
SRC_TEST := $(shell find tests/ -name "*.c")
OBJ_TEST := $(filter-out build/main.o, $(OBJ)) $(SRC_TEST:tests/%.c=build/%.o)

INCLUDE_FILES := $(shell find includes/ -name "*.h")

.PHONY: all
all: $(EXEC) $(EXEC_TEST)

$(EXEC): $(OBJ)
	@$(CC) $(FLAGS) $^ ${PKG_CONFIG} $(LIBS) -o $@ ; echo "[Compiling] $@"

build/%.o: src/%.c
	@$(CC) $(FLAGS) -c $< ${PKG_CONFIG} $(LIBS) $(INC) -o $@ ; echo "[Linking] $@"

$(EXEC_TEST): $(OBJ_TEST)
	@$(CC) $(FLAGS_TEST) $^ ${PKG_CONFIG} $(LIBS) -o $@ ; echo "[Compiling] $@"

build/%.o: tests/%.c
	@$(CC) $(FLAGS_TEST) -c $< ${PKG_CONFIG} $(LIBS) $(INC_TEST) -o $@ ; echo "[Linking] $@"

.PHONY: clean
clean:
	rm -rf build/*.o
	rm -rf Resultados
	rm -f programa-principal
	rm -rf programa-testes

.PHONY: format
format:
	clang-format -i src/*.c includes/*.h tests/*.c

