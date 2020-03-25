//~~~~~~~~~ global.h ~~~~~~~~
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <ctype.h>
/* load i/o routines */
/* load character test routines */
#define BSIZE 128 /* buffer size */
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260
#define INF 261
#define POS 262
#define PROGRAM 263
#define EOEX 264

FILE* ifptr;
FILE* ofptr;
//ifptr = fopen("C:\\Users\\Layla H\\source\\repos\\infix to prefix\\infix to prefix", "r");

int tokenval; /* value of token attribute */
int lineno;

struct entry { /* form of symbol table entry */
    char *lexptr;
    int token;
};
struct entry symtable[];  /*  symbol table */
