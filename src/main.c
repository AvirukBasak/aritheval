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
    else if (argv[1][0] == 0)
    {
        printf("aritheval: expression can't be empty\n");
        return EEMPEXP;
    }
    strncpy(EXPRESSION, argv[1], STRCPLEN);
    size_t len = strlen(EXPRESSION);
    if if (strchr(" )^/*", EXPRESSION[0]))
    {
        printf("aritheval: expression can't start with '%c'\n", EXPRESSION[0]);
        return ESTRTCHAR;
    }
    if (strchr(" .(^/*+-", EXPRESSION[len - 1]))
    {
        printf("aritheval: expression can't end with '%c'\n", EXPRESSION[len - 1]);
        return EENDCHAR;
    }
    tokenize();
    for (size_t i = 0; i <= TOKENS; i++)
    {
        printf("TOK: %s\n", STR_TOKENS[i]);
    }
    printf("Result = %s\n", EXPRESSION);
    return 0;
}
