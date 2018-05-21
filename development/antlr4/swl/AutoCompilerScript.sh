#!/bin/bash
make clean
make distclean
antlr4 -Dlanguage=Cpp swl.g4
make syncheck
make translate
