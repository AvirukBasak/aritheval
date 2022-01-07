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
 * @brief Returns evaluation of an expression
 *
 * @param init Initial posn of expression
 * @param final Final posn of expression
 * @return double
 */
void evalOp(const size_t init, const size_t final, byte op)
{

}
