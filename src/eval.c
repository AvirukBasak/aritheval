void operate(char* result, size_t len, char op, double num1, double num2)
{
    switch (op)
    {
        case '^':
            snprintf(result, len, RSLT_ACCURACY_FORM, (double) ((long) num1 ^ (long) num2));
            break;
        case '/':
            snprintf(result, len, RSLT_ACCURACY_FORM, num1 / num2);
            break;
        case '%':
            snprintf(result, len, RSLT_ACCURACY_FORM, (double) ((long) num1 % (long) num2));
            break;
        case '*':
            snprintf(result, len, RSLT_ACCURACY_FORM, num1 * num2);
            break;
        case '+':
            snprintf(result, len, RSLT_ACCURACY_FORM, num1 + num2);
            break;
        case '-':
            snprintf(result, len, RSLT_ACCURACY_FORM, num1 - num2);
            break;
        default:
            printf("aritheval: unrecognised operator: %c\n", op);
            break;
    }
}

/**
 * @brief Returns evaluation of an expression
 * 
 * @param init Initial posn of expression
 * @param final Final posn of expression
 * @return double 
 */
void eval(const size_t init, const size_t final, byte op)
{
    char num1[STRLEN] = { CH_NULL };
    char num2[STRLEN] = { CH_NULL };

    char str_result[STRLEN] = { CH_NULL };

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
                strncpy(num1, STR_TOKEN, strlen(STR_TOKEN));
                break;
            case CHAR_TOKEN:
                if (OPERATORS[op] != STR_TOKEN[0])
                {
                    strncat(str_result, num1, strlen(num1) - 1);
                    strncat(str_result, STR_TOKEN, 1);
                    break;
                }
                token_type = nextToken(&posn);
                switch (token_type)
                {
                    case INT_TOKEN:
                        strncpy(num2, STR_TOKEN, strlen(STR_TOKEN));
                        break;
                    case CHAR_TOKEN:
                        break;
                }
                char rslt[STRLEN] = { CH_NULL };
                operate(rslt, STRLEN, OPERATORS[op], atof(num1), atof(num1));
                strncat(str_result, rslt, strlen(rslt) - 1);
                break;
            default:
                printf("aritheval: logical error, report output to developer\n"
                       "token_type = %d\n"
                       "STR_TOKEN  = %s\n", token_type, STR_TOKEN);
                break;
        }
        i = posn;
    }
    strncpy(EXPRESSION, str_result, STRCPLEN);
}
