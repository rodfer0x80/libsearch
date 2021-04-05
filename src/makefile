
CXX = g++
DEBUG = -g  -Wall -Wextra

.PHONY: all
main: main.cpp utils.cpp library.cpp
	$(CXX) main.cpp utils.cpp library.cpp -o main

.PHONY: clean
clean:
	rm -f main
	rm -rf main.dSYM
	rm -f errlog.txt
	rm -f main_test_version
	rm -rf main_test_version.dSYM
	rm -f *.h.gch

.PHONY: debug
debug:
	$(CXX) $(DEBUG) main.cpp utils.cpp -o main_test_version 2>errlog.txt
