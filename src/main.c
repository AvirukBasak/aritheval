# include "headers.h"
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
        return 1;
    }
    else if (argc > 2)
    {
        printf("aritheval: too many arguments provided\n"
               "USAGE: aritheval \"[expression]\"\n");
        return 2;
    }
    else if (strlen(argv[1]) > STRCPLEN)
    {
        printf("aritheval: input exceeded limit of %d bytes\n", STRLEN);
        return 3;
    }
    strncpy(EXPRESSION, argv[1], STRCPLEN);
    size_t len = strlen(EXPRESSION);
    if (strchr(".(^/*+-", EXPRESSION[len - 1]))
    {
        printf("aritheval: expression can't end with '%c'\n", EXPRESSION[len - 1]);
        return 4;
    }
    printAllTokens(0, strlen(EXPRESSION), OPERATORS[0]);
    /* for (size_t i = 0; i < strlen(OPERATORS); i++)
     * {
     *    evalOp(0, strlen(EXPRESSION), OPERATORS[i]);
     * }
     */
    printf("Result = %s\n", EXPRESSION);
    return 0;
}
