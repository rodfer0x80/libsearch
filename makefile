# Stockman makefile
CXX = g++
DEBUG = -g -Wall -Wextra
# Compile using C++11 (required by catch2 test framework version but not for main program)
C++11 = -std=c++11
.PHONY: main
main: src/main.cpp
	$(CXX) $(C++11) src/main.cpp -o src/main

.PHONY: debug
debug: user.cpp
	cd src/ && $(CXX) $(C++11) $(DEBUG) main.cpp -o debug_main 2>debug.log && gdb debug_main 

.PHONY: run
run: main
	cd src/ && ./main

.PHONY: tests
tests: tests/tests.cpp
	cd tests/ && ./manage_dependencies.sh && $(CXX) $(C++11) tests.cpp -o tests && ./tests 

.PHONY: clean
clean:
	cd src/ && rm -f main
	cd src/ && rm -rf main.dSYM
	cd src/ && rm -f books

	cd src/ && rm -f debug_main
	cd src/ && rm -rf debug_main.dSYM	
	cd src/ && rm -f debug.log
	cd src/ && rm -f *.h.gch

	cd tests/ && rm -f tests
	cd tests/ && rm -rf tests.dSYM
	cd tests/ && rm -f *.hpp
	cd tests/ && rm -f *.h
	cd tests/ && rm -f books
	cd tests/ && rm -f backup
