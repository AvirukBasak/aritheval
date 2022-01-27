/**
 * @brief Pushes item to byte stack.
 *
 * @param stack Byte stack pointer
 * @param top   Stack top pointer
 * @param ch    Character to push
 */
void byte_stack_push (byte *stack, int *top, byte ch)
{
    if (*top == MAX_STACK_LEN - 1) {
        printf ("aritheval: byte stack overflow\n");
        exit (E_BSOVFLOW);
    }
    stack[++(*top)] = ch;
}

/**
 * @brief Peeks at the front of the stack.
 *
 * @param stack Byte stack pointer
 * @param top   Stack top pointer
 * @return byte
 */
byte byte_stack_peek (byte *stack, int *top)
{
    if (*top == STACK_INIT_TOP) {
        printf ("aritheval: byte stack underflow\n");
        exit (E_BSPEKUND);
    }
    return stack[*top];
}

/**
 * @brief Pops front of the stack.
 *
 * @param stack Byte stack pointer
 * @param top   Stack top pointer
 * @return byte
 */
byte byte_stack_pop (byte *stack, int *top)
{
    if (*top == STACK_INIT_TOP) {
        printf ("aritheval: byte stack underflow\n");
        exit (E_BSPOPUND);
    }
    return stack[(*top)--];
}

/**
 * @brief Pushes item to Double stack.
 *
 * @param stack Double stack pointer
 * @param top   Stack top pointer
 * @param val   Value to push
 */
void double_stack_push (double *stack, int *top, double val)
{
    if (*top == MAX_STACK_LEN - 1) {
        printf ("aritheval: double stack overflow\n");
        exit (E_BSOVFLOW);
    }
    stack[++(*top)] = val;
}

/**
 * @brief Peeks at the front of the stack.
 *
 * @param stack Double stack pointer
 * @param top   Stack top pointer
 */
double double_stack_peek (double *stack, int *top)
{
    if (*top == STACK_INIT_TOP) {
        printf ("aritheval: double stack underflow\n");
        exit (E_DSPEKUND);
    }
    return stack[*top];
}

/**
 * @brief Pops front of the stack.
 *
 * @param stack Double stack pointer
 * @param top   Stack top pointer
 * @return double
 */
double double_stack_pop (double *stack, int *top)
{
    if (*top == STACK_INIT_TOP) {
        printf ("aritheval: double stack underflow\n");
        exit (E_DSPOPUND);
    }
    return stack[(*top)--];
}

/**
 * @brief Check if stack empty
 *
 * @param top Stack top pointer
 * @return true if empty
 */
bool stack_isempty (int *top)
{
    return *top <= STACK_INIT_TOP;
}

/**
 * @brief Check if stack full
 *
 * @param top Stack top pointer
 * @return true if full
 */
bool stack_isfull (int *top)
{
    return *top >= MAX_STACK_LEN - 1;
}
