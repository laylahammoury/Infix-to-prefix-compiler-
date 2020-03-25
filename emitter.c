//~~~~~~~~~ emmitter.c ~~~~~~~~

#include "global.h"

emit(t, tval) /* generates output */
    int t, tval;
{

    switch(t) {
    case '+': case '-': case '*': case '/': 
        fprintf(ofptr,"%c\n", t); break;
    case '[': case ']':
        fprintf(ofptr,"%c\n", t); break;
    case '(': case ')': case ',': 
        fprintf(ofptr,"%c", t); break;
    case DIV:
        fprintf(ofptr,"DIV\n"); break;
    case MOD:
        fprintf (ofptr,"MOD\n"); break;
    case PROGRAM:
        fprintf (ofptr,"PROGRAM"); break;
    case INF:
        fprintf (ofptr,"INF"); break;
    case POS:
        fprintf (ofptr,"POS"); break;
    case NUM:
        fprintf(ofptr,"%d\n", tval); break;
    case ID:
        fprintf(ofptr,"%s\n", symtable[tval].lexptr); break;
    default:
        fprintf(ofptr,"token %d, tokenval %*d, tokenval %d\n", t, tval);
    }
}
