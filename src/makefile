
CXX = g++
DEBUG = -g -Wall -Wextra

.PHONY: all
main: main.cpp library.cpp menu.cpp
	$(CXX) main.cpp library.cpp menu.cpp -o main

.PHONY: test
test: tests.cpp library.cpp
	$(CXX) tests.cpp library.cpp -o test

.PHONY: clean
clean:
	rm -f main
	rm -f test
	rm -rf main.dSYM
	rm -f errlog.txt
	rm -f main_test_version
	rm -rf main_test_version.dSYM
	rm -f *.h.gch

.PHONY: debug
debug:
	$(CXX) $(DEBUG) main.cpp utils.cpp library.cpp -o main_test_version 2>errlog.txt
