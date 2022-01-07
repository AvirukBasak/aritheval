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
            exit(EUNRECOP);
    }
}

/**
 * @brief Arranges numbers and operators in the two queues: OP_QUEUE and NUM_QUEUE in order of priority.
 */
void arrangeTokens()
{
    for (size_t op = 0; op < OP_COUNT; op++)
    {
        for (size_t i = 0; i < TOKENS; i++)
        {
            //
        }
    }
}

/**
 * @brief Returns evaluation of an expression
 *
 * @param init Initial posn of expression
 * @param final Final posn of expression
 * @return double
 */
void evalOp(const byte op)
{

}
