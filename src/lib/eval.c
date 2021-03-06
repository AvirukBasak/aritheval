# include "../headers/headers.h"
# include "../headers/errcodes.h"

# include "const.h"
# include "globals.h"
# include "stack.h"
# include "queue.h"
# include "tokenizer.h"

int    eval_tokens = 0;
char   eval_tokenizedexp [MAX_TOKENS][MAX_TOKEN_LEN]    = { { CH_NULL } };

// postfix queue
char   eval_postfixqueue [MAX_QUEUE_LEN][MAX_TOKEN_LEN] = { { CH_NULL } };
int    eval_postfixqueue_front = QUEUE_INIT_FRONT;
int    eval_postfixqueue_rear = QUEUE_INIT_REAR;

/**
 * @brief Calculate exponential
 *
 * @param oprnd1
 * @param oprnd2
 * @return long
 */
double eval_raiseToPower (long oprnd1, long oprnd2)
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
 * @brief eval_operate on two numbers based on operator passed
 *
 * @param result Pointer to result, max length = RSLT_LEN
 * @param op Operator
 * @param num1 Number 1
 * @param num2 Number 2
 * @return double
 */
double eval_operate (char op, double num1, double num2)
{
    double result = 0.0;
    switch (op) {
        case '&': result = (double) ((long) num1 & (long) num2); break;
        case '|': result = (double) ((long) num1 | (long) num2); break;
        case '^': result = (double) ((long) num1 ^ (long) num2); break;
        case '%': result = (double) ((long) num1 % (long) num2); break;
        case 'e':
            result = num1 * eval_raiseToPower (10, (long) num2);
            break;
        case 'p':
            result = eval_raiseToPower ((long) num1, (long) num2);
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
 * @brief Checks if token is a bracket
 *
 * @param char* The category of brace ("opening" or "closing")
 * @param char* The string to check
 * @return true If str is a brace and the matches category
 */
bool eval_isBrace (const char *category, const char *str)
{
    if (!strcmp (category, "opening")) {
        return strlen (str) == 1 && str[0] == '(';
    } else if (!strcmp (category, "closing")) {
        return strlen (str) == 1 && str[0] == ')';
    } else {
        printf ("aritheval: invalid category of brace: %s\n", category);
        exit (E_LOGICAL);
    }
}

/**
 * @brief Checks if passed string is an operator.
 *
 * @param str String to check
 * @return bool
 */
bool eval_isOperator (const char *str)
{
    return strlen (str) == 1 && strchr (OPERATORS, str[0]);
}

/**
 * @brief Checks if passed string is a number through and through.
 *
 * @param str String to check
 * @return bool
 */
bool eval_isNumeric (const char *str)
{
    for (size_t i = 0; i < strlen (str); i++) {
        if (i > 0 && strchr ("+-", str[i])) {
            return false;
        } else if (!isdigit (str[i]) && !strchr (".+-", str[i])) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Compares passed operators for protity
 *
 * @param op1
 * @param op2
 * @return bool
 */
bool eval_hasMorePriority (char op1, char op2)
{
    if (op1 == '(') return true;
    int indexOp1 = (int) (strchr (OPERATORS, op1) - OPERATORS);
    int indexOp2 = (int) (strchr (OPERATORS, op2) - OPERATORS);
    return indexOp1 > indexOp2;
}

/**
 * @brief Converts expression to postfix.
 */
void eval_postfix ()
{
    // operator stack
    int opstack_top = STACK_INIT_TOP;
    byte opstack [MAX_QUEUE_LEN] = { CH_NULL };

    for (size_t i = 0; i <= eval_tokens; i++) {
        const char *token = eval_tokenizedexp[i];
        if (eval_isOperator (token)) {
            const char oprtr = token[0];
            if (stack_isempty (&opstack_top) || byte_stack_peek (opstack, &opstack_top) == '(') {
                byte_stack_push (opstack, &opstack_top, oprtr);
            } else {
                const char prev_oprtr = byte_stack_peek (opstack, &opstack_top);
                if (!eval_hasMorePriority (oprtr, prev_oprtr)) {
                    byte_stack_push (opstack, &opstack_top, oprtr);
                } else {
                    const char prev_oprtr = byte_stack_pop (opstack, &opstack_top);
                    char token[MAX_TOKEN_LEN] = { CH_NULL };
                    token[0] = prev_oprtr;
                    string_queue_push (eval_postfixqueue, &eval_postfixqueue_front, &eval_postfixqueue_rear, token);
                    byte_stack_push (opstack, &opstack_top, oprtr);
                }
            }
        } else if (eval_isNumeric (token)) {
            string_queue_push (eval_postfixqueue, &eval_postfixqueue_front, &eval_postfixqueue_rear, token);
        } else if (eval_isBrace ("opening", token)) {
            const char oprtr = token[0];
            byte_stack_push (opstack, &opstack_top, oprtr);
        } else if (eval_isBrace ("closing", token)) {
            char peek_oprtr = byte_stack_peek (opstack, &opstack_top);
            while (peek_oprtr != '(' && !stack_isempty (&opstack_top)) {
                char token[MAX_TOKEN_LEN] = { CH_NULL };
                token[0] = byte_stack_pop (opstack, &opstack_top);;
                string_queue_push (eval_postfixqueue, &eval_postfixqueue_front, &eval_postfixqueue_rear, token);
                peek_oprtr = byte_stack_peek (opstack, &opstack_top);
            }
            if (peek_oprtr != '(' || stack_isempty (&opstack_top)) {
                printf ("aritheval: couldn't find closing parentheses, posn: %ld\n", i);
                exit (E_MISSPAREN);
            }
            byte_stack_pop (opstack, &opstack_top);
        } else {
            /** @todo resolve identifiers */
            printf ("aritheval: unrecognised token: %s, posn: %ld\n", token, i);
            exit (E_UNRETOK);
        }
    }
    // pop out remaining operators and push to queue
    while (!stack_isempty (&opstack_top)) {
        char token[MAX_TOKEN_LEN] = { CH_NULL };
        token[0] = byte_stack_pop (opstack, &opstack_top);
        string_queue_push (eval_postfixqueue, &eval_postfixqueue_front, &eval_postfixqueue_rear, token);
    }
}

/**
 * @brief Evaluates a postfix expression.
 *
 * @return double -- The result
 */
double eval ()
{
    // stores tokens in eval_tokenizedexp
    eval_tokens = tokenize (eval_tokenizedexp);

    // stores tokens in eval_postfixedexp
    eval_postfix ();

    // numeric stack
    int numstack_top = STACK_INIT_TOP;
    double numstack [MAX_QUEUE_LEN] = { 0.0 };

    while (!queue_isempty (&eval_postfixqueue_front, &eval_postfixqueue_rear)) {
        const char *token = string_queue_pop (eval_postfixqueue, &eval_postfixqueue_front, &eval_postfixqueue_rear);
        if (eval_isOperator (token)) {
            const char oprtr = token[0];
            const double oprnd2 = double_stack_pop (numstack, &numstack_top);
            const double oprnd1 = double_stack_pop (numstack, &numstack_top);
            const double result = eval_operate (oprtr, oprnd1, oprnd2);
            double_stack_push (numstack, &numstack_top, result);
        } else if (eval_isNumeric (token)) {
            const double number = atof (token);
            double_stack_push (numstack, &numstack_top, number);
        } else {
            /** @todo resolve identifiers */
            if (!strcmp ("(", token)) {
                printf ("aritheval: mismatched parentheses\n");
                exit (E_MISSPAREN);
            }
            printf ("aritheval: unrecognised token: %s\n", token);
            exit (E_UNRETOK);
        }
    }
    return double_stack_pop (numstack, &numstack_top);
}
