#!/bin/bash
cd ..
i=0
while [ $i  -lt 10000 ]
do
cat books.bk >> longbooks
i=$((i + 1))
done
rm -f src/books
mv longbooks src/books
