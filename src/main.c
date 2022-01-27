# include "headers.h"
# include "errcodes.h"
# include "typedefs.c"
# include "globalvars.c"
# include "stack.c"
# include "queue.c"
# include "tokenizer.c"
# include "eval.c"

int main (const int argc, const char *const argv[])
{
    if (argc < 2) {
        printf ("aritheval: no expression provided\n"
                "USAGE: aritheval \"[expression]\"\n");
        return E_NOEXPR;
    } else if (argc > 2) {
        printf ("aritheval: too many arguments provided\n"
                "USAGE: aritheval \"[expression]\"\n");
        return E_EXCARGS;
    } else if (strlen (argv[1]) > MAX_STRCPLEN) {
        printf ("aritheval: input exceeded limit of %d bytes\n", MAX_STRLEN);
        return E_EXBLIM;
    } else if (argv[1][0] == 0) {
        printf ("aritheval: expression can't be empty\n");
        return E_EMPEXP;
    }
    strncpy (g_expression, argv[1], MAX_STRCPLEN);
    size_t len = strlen (g_expression);
    if (strchr (" )^/*", g_expression[0])) {
        printf ("aritheval: expression can't start with '%c'\n", g_expression[0]);
        return E_STRTCHAR;
    }
    if (strchr (" . (^/*+-", g_expression[len - 1])) {
        printf ("aritheval: expression can't end with '%c'\n", g_expression[len - 1]);
        return E_ENDCHAR;
    }
    tokenize ();
    if (g_debug) {
        printf ("\nResult = ");
    }
    printf ("%lf\n", eval ());
    if (g_debug) {
        printf ("\n");
    }
    return 0;
}
