# include "headers/headers.h"
# include "headers/errcodes.h"

# include "lib/const.h"
# include "lib/globals.h"
# include "lib/eval.h"

int main (const int argc, const char *const argv[])
{
    // sets debug flag based on environment variable
    char *ENV_DEBUG = getenv ("DEBUG");
    if (ENV_DEBUG && strlen (ENV_DEBUG) == 4) {
        if ((ENV_DEBUG[0] == 't' ||  ENV_DEBUG[0] == 'T')
        &&  (ENV_DEBUG[1] == 'r' ||  ENV_DEBUG[1] == 'R')
        &&  (ENV_DEBUG[2] == 'u' ||  ENV_DEBUG[2] == 'U')
        &&  (ENV_DEBUG[3] == 'e' ||  ENV_DEBUG[3] == 'E')) {
            DEBUG = true;
        }
    }

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

    strncpy (Expression, argv[1], MAX_STRCPLEN);
    size_t len = strlen (Expression);

    if (strchr (" )^/*", Expression[0])) {
        printf ("aritheval: expression can't start with '%c'\n", Expression[0]);
        return E_STRTCHAR;
    }

    if (strchr (" .(^/*+-", Expression[len - 1])) {
        printf ("aritheval: expression can't end with '%c'\n", Expression[len - 1]);
        return E_ENDCHAR;
    }

    // evaluates g_postfixedexp
    if (DEBUG) printf ("\n");
    const double result = eval ();
    if (DEBUG) printf ("Result = ");
    printf (RSLT_ACCURACY_FORM "\n", result);
    if (DEBUG) printf ("\n");

    return 0;
}
