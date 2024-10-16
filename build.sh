#!/bin/bash

gcc -I/opt/lua-5.4.7/src -L/opt/lua-5.4.7/src -Wall -o lua-from-c lua-from-c.c -llua -ldl -lm
