# include "headers/headers.h"
# include "headers/errcodes.h"

# include "lib/const.h"
# include "lib/eval.h"

bool g_debug = false;
char g_expression [MAX_STRLEN] = { CH_NULL };

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

    // evaluates g_postfixedexp
    const double result = eval (g_debug, g_expression);

    if (g_debug) {
        printf ("\nResult = ");
    }
    printf (RSLT_ACCURACY_FORM "\n", result);
    if (g_debug) {
        printf ("\n");
    }
    return 0;
}
