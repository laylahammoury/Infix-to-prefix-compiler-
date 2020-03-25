///*************** global.h ***************/
//#include <stdio.h>
//#include <ctype.h>
///* load i/o routines */
///* load character test routines */
//#define BSIZE 128 /* buffer size */
//#define NONE -1
//#define EOS '\0'
//
//#define NUM 256
//#define DIV 257
//#define MOD 258
//#define ID 259
//#define DONE 260
//
//int tokenval; /* value of token attribute */
//int lineno;
//struct entry { /* form of symbol table entry */
//    char *lexptr;
//    int token;
//};
//struct entry symtable[];  /*  symbol table */
//
//
//
//
//
///*************** lexer.c ***************/
//#include "global.h"
//
//char lexbuf[BSIZE];
//int lineno = 1;
//int tokenval = NONE;
//int lexan() /* lexical analyzer */
//{
//    int t;
//    while(1) {
//        t = getchar();
//        if (t == ' ' || t == '\t')
//            ; /* strip out white space */
//        else if (t == '\n')
//            lineno = lineno + 1;
//        else if (isdigit(t)) { /* t is a digit */
//            ungetc(t, stdin);
//            scanf("%d", &tokenval);
//            return NUM;
//        }
//        else if (isalpha(t)) { /* t is a letter */
//            int p, b = 0;
//            while (isalnum(t)) { /* t is alphanumeric */
//            lexbuf[b] = t;
//            t = getchar();
//            b = b + 1;
//            if (b >= BSIZE)
//                error("compiler error");
//        }
//        lexbuf[b] = EOS;
//        if (t != EOF)
//            ungetc(t, stdin);
//        p = lookup(lexbuf);
//        if (p == 0)
//            p = insert(lexbuf, ID);
//        tokenval = p;
//        return symtable[p].token;
//    }
//        else if (t == EOF)
//            return DONE;
//
//        else {
//            tokenval = NONE;
//            return t;
//        }
//
//    }
//}
//
//
//
//
//
///*************** parser.c ***************/
//#include "global.h"
//
//int lookahead;
//parse() /* parses and translates expression list */
//{
//    lookahead = lexan();
//    while (lookahead != DONE ) {
//    expr(); match(';');
//    }
//}
//
//expr()
//{
//    int t;
//    term();
//    while(1)
//        switch (lookahead) {
//        case '+': case '-':
//            t = lookahead;
//            match(lookahead); term(); emit(t, NONE);
//            continue;
//        default:
//            return;
//        }
//}
//term()
//{
//    int t;
//    factor();
//    while(1)
//        switch (lookahead) {
//        case '*': case '/' : case DIV: case MOD:
//            t = lookahead;
//            match(lookahead); factor(); emit(t, NONE);
//            continue;
//        default:
//            return;
//        }
//}
//
//factor()
//{
//    switch(lookahead) {
//        case '(':
//            match('('); expr(); match(')'); break;
//        case NUM:
//            emit(NUM, tokenval); match (NUM); break;
//        case ID:
//            emit(ID, tokenval); match (ID); break;
//        default:
//            error("syntax error");
//    }
//    
//}
//
//match(t)
//{
//    int t;
//    if (lookahead == t)
//        lookahead = lexan();
//    else error("syntax error");
//}
//
//
//
//
///*************** emitter.c ***************/
//#include "global.h"
//
//emit(t, tval) /* generates output */
//    int t, tval;
//{
//    switch(t) {
//    case '+': case '-': case '*': case '/':
//        printf("%c\n", t); break;
//    case DIV:
//        printf("DIV\n"); break;
//    case MOD:
//        printf ("MOD\n"); break;
//    case NUM:
//        printf("%d\n", tval); break;
//    case ID:
//        printf("%s\n", symtable[tval].lexptr); break;
//    default:
//        printf("token %d, tokenval %*d, tokenval %d\n", t, tval)
//    }
//}
//
//
//
//
///*************** symbol.c ***************/
//#include "global.h"
//
//#define STRMAX 999 /* size of lexemes array */
//#define SYMMAX 100 /* size of symtable */
//char lexemes (STRMAX);
//int lastchar = -1; /*last used position in lexemes */
//struct entry symtable(SYMMAX);
//int lastentry = 0; /* last used position in symtable */
//
//int lookup(s)  /* returns position of entry for s */
//    char s[];
//{
//    int p;
//    for (p = lastentry; p > 0; p = p - 1)
//        if (strcmp( symtable[p].lexptr, s) == 0)
//            return p;
//    return 0;
//}
//            
//            
//            
//            
//            
//            
//            
//int insert(s, tok) /* returns position of entry for s */
//    char s[];
//    int tok;
//{
//    int len;
//    len = strlen(s); /* strlen computes length of s */
//    if (lastentry + 1 >= SYMMAX)
//        error("symbol table full");
//    if (lastchar + len + 1 >= STRMAX)
//        error("lexemes array full");
//    lastentry = lastentry + 1;
//    symtable[lastentry].token = tok;
//    symtable[lastentry].lexptr = &lexemes[lastchar + 1];
//    lastchar = lastchar + len + 1;
//    strcpy(symtable[lastentry].lexptr, s);
//    return lastentry;
//}
//
//
//
//
///*************** init.c ***************/
//
//#include "global.h"
//struct entry keywords[] = {
//    "div", DIV,
//    "mod", MOD,
//    0, 0
//};
//
//init() /* loads keywords into symtable */
//{
//    struct entry *p;
//    for (p = keywords; p->token; p++)
//        insert(p->lexptr, p->token);
//}
//
//
//
//
///*************** error.c ***************/
//
//#include "global.h"
//error(m) /* generates all error */
//    char *m;
//{
//fprintf(stderr, "line %d: %s\n", lineno, m);
//exit(1); /* unsuccessful termination */
//}
//
//
//
//
///*************** main.c ***************/
//
//#include "global.h"
//
//main()
//{
//    init();
//    parse();
//    exit(0); /* successful termination */
//}
