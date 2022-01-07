# include "headers.h"
# include "errcodes.h"
# include "typedefs.c"
# include "globalvars.c"
# include "queue.c"
# include "tokenizer.c"
# include "eval.c"

int main(const int argc, const char *const argv[])
{
    if (argc < 2)
    {
        printf("aritheval: no expression provided\n"
               "USAGE: aritheval \"[expression]\"\n");
        return ENOEXPR;
    }
    else if (argc > 2)
    {
        printf("aritheval: too many arguments provided\n"
               "USAGE: aritheval \"[expression]\"\n");
        return EEXCARGS;
    }
    else if (strlen(argv[1]) > STRCPLEN)
    {
        printf("aritheval: input exceeded limit of %d bytes\n", STRLEN);
        return EEXBLIM;
    }
    strncpy(EXPRESSION, argv[1], STRCPLEN);
    size_t len = strlen(EXPRESSION);
    if (strchr(".(^/*+-", EXPRESSION[len - 1]))
    {
        printf("aritheval: expression can't end with '%c'\n", EXPRESSION[len - 1]);
        return EENDCHAR;
    }
    /* for (size_t i = 0; i < strlen(OPERATORS); i++)
     * {
     *    evalOp(0, strlen(EXPRESSION), OPERATORS[i]);
     * }
     */
    tokenize();
    printf("Result = %s\n", EXPRESSION);
    return 0;
}
