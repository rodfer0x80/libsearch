#!/bin/bash
cd ..
cat books.bk > books
rm -f src/books
mv books src/books
