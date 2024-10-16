#!/bin/bash

gcc -I/opt/lua-5.4.7/src -L/opt/lua-5.4.7/src -Wall -o lua_from_c lua_from_c.c -llua -ldl -lm
