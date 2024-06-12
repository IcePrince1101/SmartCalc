CC = gcc
CFLAG = -Wall -Wextra -Werror -std=c11
APP = SmartCalc
SOURCES_ALL = $(wildcard ./*.c)
OBJ_LIBRARY := $(patsubst %.c, %.o, $(SOURCES_ALL))
GCOVFLAGS = -L. --coverage
TEST_FLAGS = -lm -lcheck -lsubunit

all: build

build: clean
	mkdir build
	cd ./build/ && qmake6 ../ && make && mv SmartCalc_v1 $(APP).app

install: build
	mv build/$(APP).app $(HOME)/my_app/

uninstall:
	rm -rf $(HOME)/my_app/$(APP).app
	make clean

dvi:
	open ../README.md

dist: 
	rm -rf Distribut_SmartCalc_v1.0/
	mkdir Distribut_SmartCalc_v1.0/
	cp Makefile *.c *.h *.pro *.cpp *.ui Distribut_SmartCalc_v1.0
	tar cf Distribut_SmartCalc_v1.0.tgz Distribut_SmartCalc_v1.0/ 
	rm -rf Distribut_SmartCalc_v1.0/

s21_calc.a:
	gcc $(CFLAG) $(SOURCES_ALL) -c
	ar rc s21_calc.a $(OBJ_LIBRARY)
	rm *.o

test: s21_calc.a
	gcc $(CFLAG) tests/calc_test.c s21_calc.a $(TEST_FLAGS) -o test.out
	./test.out

check_style:
	clang-format -n -style=google *.c
	clang-format -n -style=google tests/*.c
	clang-format -n -style=google *.cpp
	clang-format -n -style=google *.h

style:
	clang-format -i -style=google *.c
	clang-format -i -style=google tests/*.c
	clang-format -i -style=google *.cpp
	clang-format -i -style=google *.h

gcov_report: s21_calc.a 
	gcc $(CFLAG) tests/calc_test.c $(SOURCES_ALL) s21_calc.a $(TEST_FLAGS) $(GCOVFLAGS) -o test.out
	./test.out
	lcov -t tests/calc_test.c -o test.info -c -d .
	genhtml -o test_html test.info
	open ./test_html/index.html

leaks: s21_calc.a 
	gcc $(CFLAG) tests/calc_test.c s21_calc.a $(TEST_FLAGS) -o test.out
	CK_FORK=no valgrind --leak-check=full --tool=memcheck --trace-children=yes --track-origins=yes ./test.out

clean:
	rm -rf *.o *.a *.out
	rm -rf *.gcda *.gcno *.info
	rm -rf s21_test report
	rm -rf s21_calc s21_test
	rm -rf ./build*
	rm -rf ../build
	rm -rf test
	rm -rf test_html
	rm -rf *.pro.user
	rm -rf *.tgz