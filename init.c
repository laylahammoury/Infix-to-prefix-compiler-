//~~~~~~~~~ init.c ~~~~~~~~

#include "global.h"

struct entry keywords[] = {
    "div", DIV,
    "mod", MOD,
    "inf", INF,
    "pos", POS,
    "program", PROGRAM,
    0, 0
};

init() /* loads keywords into symtable */
{
    struct entry *p;
    for (p = keywords; p->token; p++)
        insert(p->lexptr, p->token);
}