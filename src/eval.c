/**
 * @brief Calculate exponential
 *
 * @param oprnd1
 * @param oprnd2
 * @return long
 */
double raiseToPower(long oprnd1, long oprnd2)
{
    bool negative_power = oprnd2 < 0;

    if (oprnd2 == 0)
        return 1;
    else if (oprnd2 == 1)
        return oprnd2;

    oprnd2 = llabs(oprnd2);
    while (oprnd2 > 1)
    {
        oprnd1 *= oprnd1;
        oprnd2--;
    }
    if (negative_power)
        oprnd1 = 1 / oprnd1;
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
double operate(char op, double num1, double num2)
{
    double result = 0.0;
    switch (op)
    {
        case '&': result = (double) ((long) num1 & (long) num2); break;
        case '|': result = (double) ((long) num1 | (long) num2); break;
        case '^': result = (double) ((long) num1 ^ (long) num2); break;
        case '%': result = (double) ((long) num1 % (long) num2); break;
        case 'e':
            result = num1 * raiseToPower(10, (long) num2);
            break;
        case 'p':
            result = raiseToPower((long) num1, (long) num2);
            break;
        case '/': result = num1 / num2; break;
        case '*': result = num1 * num2; break;
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        default:
            printf("aritheval: unrecognised operator: %c\n", op);
            exit(EUNRECOP);
    }
    return result;
}

/**
 * @brief Checks if passed string is a number through and through.
 *
 * @param str String to check
 * @return bool
 */
bool isNumeric(const char *str)
{
    for (size_t i = 0; i < strlen(str); i++)
        if (!isdigit(str[i]) && str[i] != '.'
        &&  str[i] != '+'    && str[i] != '-')
            return false;
    return true;
}

/**
 * @brief Checks if passed string is an operator.
 *
 * @param str String to check
 * @return bool
 */
bool isOperator(const char *str)
{
    return strlen(str) == 1 && strchr(OPERATORS, str[0]);
}

/**
 * @brief Compares passed operators for protity
 *
 * @param op1
 * @param op2
 * @return bool
 */
bool hasMorePriority(char op1, char op2)
{
    size_t indexOp1 = (size_t) (strchr(OPERATORS, op1) - OPERATORS);
    size_t indexOp2 = (size_t) (strchr(OPERATORS, op2) - OPERATORS);
    return indexOp1 > indexOp2;
}

/**
 * @brief Evaluates an expression based on a specific operator.
 */
double eval()
{
    size_t op_stack_top = STACK_INIT_TOP;
    size_t num_stack_top = STACK_INIT_TOP;
    for (size_t i = 0; i <= TOKENS; i++)
    {
        const char *token = STR_TOKENS[i];
        if (isOperator(token))
        {
            char op = token[0];
            if (!Stack_isEmpty(&op_stack_top))
            {
                printf("OP_STACK    not empty\n");
                char peeked_op = Stack_Byte_peek(OP_STACK, &op_stack_top);
                printf("OP_STACK    peeked op: %c\n", peeked_op);
                if (hasMorePriority(op, peeked_op) || op == peeked_op)
                {
                    printf("OP          priority: %c >= %c\n", op, peeked_op);
                    double popped_oprnd = Stack_Double_pop(NUM_STACK, &num_stack_top);
                    printf("NUM_STACK   popped oprnd: %lf\n", popped_oprnd);
                    double next_oprnd = atof(STR_TOKENS[++i]);
                    printf("NUM         next oprnd: %lf\n", next_oprnd);
                    double result = operate(op, popped_oprnd, next_oprnd);
                    printf("NUM_STACK   push result: %lf\n", result);
                    Stack_Double_push(NUM_STACK, &num_stack_top, result);
                }
                else
                {
                    double popped_oprnd1 = Stack_Double_pop(NUM_STACK, &num_stack_top);
                    printf("NUM_STACK   popped oprnd1: %lf\n", popped_oprnd1);
                    double popped_oprnd2 = Stack_Double_pop(NUM_STACK, &num_stack_top);
                    printf("NUM_STACK   popped oprnd2: %lf\n", popped_oprnd2);
                    peeked_op = Stack_Byte_pop(OP_STACK, &op_stack_top);
                    printf("OP_STACK    popped op: %c\n", peeked_op);
                    double result = operate(peeked_op, popped_oprnd1, popped_oprnd2);
                    printf("NUM_STACK   push result: %lf\n", result);
                    Stack_Double_push(NUM_STACK, &num_stack_top, result);
                    printf("OP_STACK    push op: %c\n", op);
                    Stack_Byte_push(OP_STACK, &op_stack_top, op);
                }
            }
            else
            {
                printf("OP_STACK    empty\n");
                printf("OP_STACK    push op: %c\n", op);
                Stack_Byte_push(OP_STACK, &op_stack_top, op);
            }
        }
        else if (isNumeric(token))
        {
            double number = atof(token);
            printf("NUM_STACK   push number: %lf\n", number);
            Stack_Double_push(NUM_STACK, &num_stack_top, number);
        } 
        else {}
    }
    printf("NUM_STACK   pop return\n");
    return Stack_Double_pop(NUM_STACK, &num_stack_top);
}
