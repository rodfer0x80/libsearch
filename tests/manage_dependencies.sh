#!/bin/sh
# -- Dependencies --
# :: Catch2 v2.x (stable)
FILE=catch.hpp
if [ -f "$FILE" ]; then
    continue
else 
    curl https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp -o catch.hpp
fi
# :: Project modules from /src
cp ../src/book.hpp .
cp ../src/matrix.hpp .
cp ../src/menu.hpp .
cp ../src/menu.h .
cp ../src/library.hpp .
cp ../scripts/books.bak books
