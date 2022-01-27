/**
 * @brief Calculate exponential
 *
 * @param oprnd1
 * @param oprnd2
 * @return long
 */
double raiseToPower (long oprnd1, long oprnd2)
{
    bool negative_power = oprnd2 < 0;

    if (oprnd2 == 0) {
        return 1;
    } else if (oprnd2 == 1) {
        return oprnd2;
    }

    oprnd2 = llabs (oprnd2);
    while (oprnd2 > 1) {
        oprnd1 *= oprnd1;
        oprnd2--;
    }
    if (negative_power) {
        oprnd1 = 1 / oprnd1;
    }
    return oprnd1;
}

/**
 * @brief Operate on two numbers based on operator passed
 *
 * @param result Pointer to result, max length = RSLT_LEN
 * @param op Operator
 * @param num1 Number 1
 * @param num2 Number 2
 * @return double
 */
double operate (char op, double num1, double num2)
{
    double result = 0.0;
    switch (op) {
        case '&': result = (double) ((long) num1 & (long) num2); break;
        case '|': result = (double) ((long) num1 | (long) num2); break;
        case '^': result = (double) ((long) num1 ^ (long) num2); break;
        case '%': result = (double) ((long) num1 % (long) num2); break;
        case 'e':
            result = num1 * raiseToPower (10, (long) num2);
            break;
        case 'p':
            result = raiseToPower ((long) num1, (long) num2);
            break;
        case '/': result = num1 / num2; break;
        case '*': result = num1 * num2; break;
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        default:
            printf ("aritheval: unrecognised operator: %c\n", op);
            exit (E_UNRECOP);
    }
    return result;
}

/**
 * @brief Checks if passed string is a number through and through.
 *
 * @param str String to check
 * @return bool
 */
bool isNumeric (const char *str)
{
    for (int i = 0; i < strlen (str); i++) {
        if (!isdigit (str[i]) && str[i] != '.' &&  str[i] != '+' && str[i] != '-') {
            return false;
        }
    }
    return true;
}

/**
 * @brief Checks if passed string is an operator.
 *
 * @param str String to check
 * @return bool
 */
bool isOperator (const char *str)
{
    return strlen (str) == 1 && strchr (OPERATORS, str[0]);
}

/**
 * @brief Compares passed operators for protity
 *
 * @param op1
 * @param op2
 * @return bool
 */
bool hasMorePriority (char op1, char op2)
{
    int indexOp1 = (int) (strchr (OPERATORS, op1) - OPERATORS);
    int indexOp2 = (int) (strchr (OPERATORS, op2) - OPERATORS);
    return indexOp1 > indexOp2;
}

/**
 * @brief Converts expression to postfix.
 */
double postfix ()
{
    return 0.0;
}


/**
 * @brief Evaluates an expression based on a specific operator.
 */
double eval ()
{
    return 0.0;
}
