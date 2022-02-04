# ifndef __clang__
# error compiler is not 'clang', compilation may fail
# endif

# include "headers/headers.h"
# include "headers/errcodes.h"

# include "lib/const.h"
# include "lib/globals.h"
# include "lib/eval.h"

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

# ifdef DEBUG
    printf ("\n");
# endif

    const double result = eval ();

# ifdef DEBUG
    printf ("Result = ");
# endif

    printf (RSLT_ACCURACY_FORM "\n", result);

# ifdef DEBUG
    printf ("\n");
# endif

    return 0;
}
