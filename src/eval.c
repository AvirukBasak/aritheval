/**
 * @brief Returns evaluation of an expression
 * 
 * @param init Initial posn of expression
 * @param final Final posn of expression
 * @return double 
 */
double eval(const size_t init, const size_t final, byte op)
{
    double num1 = 0.0;
    double num2 = 0.0;
    double rslt = 0.0;

    size_t len = strlen(EXPRESSION);
    char *posn = EXPRESSION;

    // Loop through the entire input
    for (size_t i = 0; i < len; )
    {
        size_t posn = i;
        byte token_type = nextToken(&posn);
        switch (token_type)
        {
            case INT_TOKEN:
                printf("N:%s\n", STR_TOKEN);
                break;
            case CHAR_TOKEN:
                // if (OPERATORS[op] == STR_TOKEN[0])
                printf("O:%s\n", STR_TOKEN);
                break;
            case INVAL_TOKEN:
                exit(4);
                break;
            default:
                printf("aritheval: logical error, report output to developer\n"
                       "token_type = %d\n"
                       "STR_TOKEN  = %s\n", token_type, STR_TOKEN);
                break;
        }
        i = posn;
    }
    return 0.0;
}
