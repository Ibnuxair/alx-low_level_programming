#!/bin/bash

gcc -c -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

gcc -shared -o liball.so *.o

rm *.o

echo "Dynamic library created!"
