//~~~~~~~~~ parser.c ~~~~~~~~

#include "global.h"

int lookahead;
parse() /* parses and translates expression list */
{

    lookahead = lexan();
    prog();
    //while (lookahead != DONE) {
    while (lookahead != ']') {
        expr(); match(';');
    }
    emit(lookahead, NONE); match(']'); //printf("%c", ']');
}

prog()
{
    int t;
        //program
    emit(PROGRAM, tokenval); match(PROGRAM);
        //lookahead == '(';
    t = lookahead;
    if (lookahead == '(')
    {
        emit(lookahead, NONE); match('(');//printf("%c", '(');
    }
    else error("syntax error");
        //inf
        emit(INF, tokenval); match(INF);
    //lookahead == ',';
    if (lookahead == ',')
    {
        emit(lookahead, NONE); match(','); //printf("%c", ',');
    }
    else error("syntax error");
        //pos
        emit(POS, tokenval); match(POS);
     //lookahead == ')';
    if (lookahead == ')')
    {
        emit(lookahead, NONE); match(')'); //printf("%c", ')');
    }
    else error("syntax error");
        //lookahead == '[';
    if (lookahead == '[')
    {
        emit(lookahead, NONE); match('['); //printf("%c\n", '[');
    }
    else error("syntax error");

}
expr()
{
    int t;
    term();
    while (1)
        switch (lookahead) {
        case '+': case '-':
            t = lookahead;
            match(lookahead); term(); emit(t, NONE);
            continue;
        default:
            return;
        }
}
term()
{
    int t;
    factor();
    while (1)
        switch (lookahead) {
        case '*': case '/': case DIV: case MOD:
            t = lookahead;
            match(lookahead); factor(); emit(t, NONE);
            continue;
        default:
            return;
        }
}

factor()
{
    switch (lookahead) {
    case '(':
        match('('); expr(); match(')'); break;
    case NUM:
        emit(NUM, tokenval); match(NUM); break;
    case ID:
        emit(ID, tokenval); match(ID); break;
    default:
        error("syntax error");
    }

}

match(t)
int t;
{
    if (lookahead == t)
        lookahead = lexan();
    else error("syntax error");
}


