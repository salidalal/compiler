#! /bin/bash
if [ $1 = "-d" ]; then
    rm y.tab.c y.tab.h lex.yy.c project
elif [ $1 ="-r" ]; then
    ./project<1.txt
else
    yacc -d project.y -v
    lex project.l
    cc -o project y.tab.c
fi
