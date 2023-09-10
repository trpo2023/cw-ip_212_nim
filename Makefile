CC = g++
CFLAGS = -Wall -Wextra -Werror -I src/ -I thirdparty/
NIM_SRC = src/game_nim_main/
LIBNIM_SRC = src/game_nim_lib/

NIM_OBJ = obj/src/game_nim_main/
LIBNIM_OBJ = obj/src/game_nim_lib/

BIN = bin/

TEST_BIN = bin/game_nim_test/

SRC = src/

TEST = test/

TEST_OBJ = obj/game_nim_test/

THIRDPARTY = thirdparty/

SRCS := $(shell find . -type f -name '*.cpp')
HDRS := $(shell find . -type f -name '*.h')

.PHONY: main

$(BIN)game_nim_main/main.out: $(NIM_OBJ)main.o $(LIBNIM_OBJ)libnim.a
	$(CC) $(CFLAGS) -o $@ $^
$(NIM_OBJ)main.o: $(NIM_SRC)main.cpp 
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBNIM_OBJ)libnim.a: $(LIBNIM_OBJ)is_nim.o $(LIBNIM_OBJ)optimal_move.o $(LIBNIM_OBJ)print_piles.o
	ar rcs $@ $^
$(LIBNIM_OBJ)is_nim.o: $(LIBNIM_SRC)is_nim.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBNIM_OBJ)optimal_move.o: $(LIBNIM_SRC)optimal_move.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(LIBNIM_OBJ)print_piles.o: $(LIBNIM_SRC)print_piles.cpp
	$(CC) -c $(CFLAGS) -o $@ $^


.PHONY: test

test: $(BIN)game_nim_test/test
	./$<

$(BIN)game_nim_test/test: $(TEST_OBJ)ctest.o $(TEST_OBJ)main.o $(TEST_OBJ)testlibnim.a 
	$(CC) $(CFLAGS) -o $@ $^
$(TEST_OBJ)ctest.o: $(TEST)ctest.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)main.o: $(TEST)main.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)testlibnim.a: $(TEST_OBJ)is_nim.o $(TEST_OBJ)optimal_move.o $(TEST_OBJ)print_piles.o
	ar rcs $@ $^
$(TEST_OBJ)is_nim.o: $(LIBNIM_SRC)is_nim.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)optimal_move.o: $(LIBNIM_SRC)optimal_move.cpp
	$(CC) -c $(CFLAGS) -o $@ $^
$(TEST_OBJ)print_piles.o: $(LIBNIM_SRC)print_piles.cpp
	$(CC) -c $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rf $(NIM_OBJ)*.o
	rm -rf $(LIBNIM_OBJ)*.o
	rm -rf $(LIBNIM_OBJ)*.a
	rm -rf $(TEST_OBJ)*.o
	rm -rf $(TEST_OBJ)*.a
	rm -rf $(BIN)*.out

.PHONY: format

format:
	clang-format -i $(SRCS) $(HDRS)