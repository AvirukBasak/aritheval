/**
 * @brief Operate on two numbers based on operator passed
 *
 * @param result Pointer to result, max length = RSLT_LEN
 * @param op Operator
 * @param num1 Number 1
 * @param num2 Number 2
 */
void operate(char* result, char op, double num1, double num2)
{
    switch (op)
    {
        case '^':
            snprintf(result, RSLT_LEN, RSLT_ACCURACY_FORM, (double) ((long) num1 ^ (long) num2));
            break;
        case '/':
            snprintf(result, RSLT_LEN, RSLT_ACCURACY_FORM, num1 / num2);
            break;
        case '%':
            snprintf(result, RSLT_LEN, RSLT_ACCURACY_FORM, (double) ((long) num1 % (long) num2));
            break;
        case '*':
            snprintf(result, RSLT_LEN, RSLT_ACCURACY_FORM, num1 * num2);
            break;
        case '+':
            snprintf(result, RSLT_LEN, RSLT_ACCURACY_FORM, num1 + num2);
            break;
        case '-':
            snprintf(result, RSLT_LEN, RSLT_ACCURACY_FORM, num1 - num2);
            break;
        default:
            printf("aritheval: unrecognised operator: %c\n", op);
            exit(EUNRECOP);
    }
}

/**
 * @brief Checks if passed string is a number through and through.
 *
 * @param str String to check
 * @return bool
 */
bool isNumber(const char *str)
{
    for (size_t i = 0; i < strlen(str); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
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
            char *token = STR_TOKENS[i];
        }
    }
}

/**
 * @brief Evaluates an expression based on a specific operator.
 *
 * @param result Pointer to result, max length = RSLT_LEN 
 * @param op Operator posn in OPERATORS array
 */
void evalOp(char *result, const byte op)
{

}
