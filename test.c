//~~~~~~~~~ test.c ~~~~~~~~

#include "global.h"



int test() {

    ifptr = fopen("C:\\Users\\Layla H\\source\\repos\\infix to prefix\\infix to prefix\\input.txt", "r");
    int t;
    while (1) {
        t = fgetc(ifptr);
        char ch = t;
           
    }

    close(ifptr);
}
//int test() /* lexical analyzer */
//{
//    ifptr = fopen("C:\\Users\\Layla H\\source\\repos\\infix to prefix\\infix to prefix\\input.txt", "r");
//
//    int t;
//    while (1) {
//        t = fgetc(ifptr);
//        //t = getchar();
//        if (t == ' ' || t == '\t')
//            ; /* strip out white space */
//        else if (t == '\n')
//            lineno = lineno + 1;
//        else if (isdigit(t)) { /* t is a digit */
//            ungetc(t, ifptr);
//            //ungetc(t, stdin);
//            //scanf_s("%d", &tokenval);
//            fscanf_s(ifptr, "%d", &tokenval);
//            return NUM;
//        }
//        else if (isalpha(t)) { /* t is a letter */
//            int p, b = 0;
//            while (isalnum(t)) { /* t is alphanumeric */
//                lexbuf[b] = t;
//                t = fgetc(ifptr);
//                //t = getchar();
//                b = b + 1;
//                if (b >= BSIZE)
//                    error("compiler error");
//            }
//            lexbuf[b] = EOS;
//            if (t != EOF)
//            {
//                //int temp = ungetc(t, ifptr);
//                //int temp = ungetc(t, stdin);
//                //temp = -858993460;
//            }
//            p = lookup(lexbuf);
//            if (p == 0)
//                p = insert(lexbuf, ID);
//            tokenval = p;
//            return symtable[p].token;
//        }
//        else if (t == EOF)
//            return DONE;
//
//        else {
//            tokenval = NONE;
//            return t;
//        }
//
//    }
//    close(ifptr);
//}

