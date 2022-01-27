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
    oprnd2 = llabs (oprnd2);
    double result = oprnd1;

    if (oprnd2 == 0) {
        return 1;
    } else if (oprnd2 == 1) {
        return oprnd2;
    }

    while (oprnd2 > 1) {
        result *= oprnd1;
        oprnd2--;
    }
    if (negative_power) {
        result = 1 / result;
    }
    return result;
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
void postfix ()
{
    // operator stack
    int opstack_top = STACK_INIT_TOP;
    byte opstack [MAX_QUEUE_LEN] = { CH_NULL };

    for (int i = 0; i <= g_tokens; i++) {
        const char *token = g_tokenizedexp[i];
        if (isOperator (token)) {
            const char oprtr = token[0];
            if (stack_isempty (&opstack_top)) {
                byte_stack_push (opstack, &opstack_top, oprtr);
            } else {
                const char prev_oprtr = byte_stack_peek (opstack, &opstack_top);
                if (!hasMorePriority (oprtr, prev_oprtr)) {
                    byte_stack_push (opstack, &opstack_top, oprtr);
                } else {
                    const char prev_oprtr = byte_stack_pop (opstack, &opstack_top);
                    char token[MAX_TOKEN_LEN] = { CH_NULL };
                    token[0] = prev_oprtr;
                    string_queue_push (g_postfixqueue, &g_postfixqueue_front, &g_postfixqueue_rear, token);
                    byte_stack_push (opstack, &opstack_top, oprtr);
                }
            }
        } else if (isNumeric (token)) {
            string_queue_push (g_postfixqueue, &g_postfixqueue_front, &g_postfixqueue_rear, token);
        } else {
            /** @todo resolve identifiers */
        }
    }
    // pop out remaining operators and push to queue
    while (!stack_isempty (&opstack_top)) {
        char token[MAX_TOKEN_LEN] = { CH_NULL };
        token[0] = byte_stack_pop (opstack, &opstack_top);
        string_queue_push (g_postfixqueue, &g_postfixqueue_front, &g_postfixqueue_rear, token);
    }
}

/**
 * @brief Evaluates a postfix expression.
 *
 * @return double -- The result
 */
double eval ()
{
    // numeric stack
    int numstack_top = STACK_INIT_TOP;
    double numstack [MAX_QUEUE_LEN] = { 0.0 };

    while (!queue_isempty (&g_postfixqueue_front, &g_postfixqueue_rear)) {
        const char *token = string_queue_pop (g_postfixqueue, &g_postfixqueue_front, &g_postfixqueue_rear);
        if (isOperator (token)) {
            const char oprtr = token[0];
            const double oprnd2 = double_stack_pop (numstack, &numstack_top);
            const double oprnd1 = double_stack_pop (numstack, &numstack_top);
            const double result = operate (oprtr, oprnd1, oprnd2);
            double_stack_push (numstack, &numstack_top, result);
        } else if (isNumeric (token)) {
            const double number = atof (token);
            double_stack_push (numstack, &numstack_top, number);
        } else {
            /** @todo resolve identifiers */
        }
    }
    return double_stack_pop (numstack, &numstack_top);
}
