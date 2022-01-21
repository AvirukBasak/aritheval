/**
 * @brief Pushes item to byte stack.
 *
 * @param stack Byte stack pointer
 * @param top   Stack top pointer
 * @param ch    Character to push
 */
void Stack_Byte_push(byte *stack, size_t *top, byte ch)
{
    if (*top == STACK_LEN - 1)
    {
        printf("aritheval: byte stack overflow\n");
        exit(EBSOVFLOW);
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
byte Stack_Byte_peek(byte *stack, size_t *top)
{
    if (*top == STACK_INIT_TOP)
    {
        printf("aritheval: byte stack underflow\n");
        exit(EBSPEKUND);
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
byte Stack_Byte_pop(byte *stack, size_t *top)
{
    if (*top == STACK_INIT_TOP)
    {
        printf("aritheval: byte stack underflow\n");
        exit(EBSPOPUND);
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
void Stack_Double_push(double *stack, size_t *top, double val)
{
    if (*top == STACK_LEN - 1)
    {
        printf("aritheval: double stack overflow\n");
        exit(EBSOVFLOW);
    }
    stack[++(*top)] = val;
}

/**
 * @brief Peeks at the front of the stack.
 *
 * @param stack Double stack pointer
 * @param top   Stack top pointer
 */
double Stack_Double_peek(double *stack, size_t *top)
{
    if (*top == STACK_INIT_TOP)
    {
        printf("aritheval: double stack underflow\n");
        exit(EDSPEKUND);
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
double Stack_Double_pop(double *stack, size_t *top)
{
    if (*top == STACK_INIT_TOP)
    {
        printf("aritheval: double stack underflow\n");
        exit(EDSPOPUND);
    }
    return stack[(*top)--];
}

/**
 * @brief Check if stack empty
 *
 * @param top Stack top pointer
 * @return true if empty
 */
bool Stack_isEmpty(size_t top) {
    return top <= STACK_INIT_TOP;
}

/**
 * @brief Check if stack full
 *
 * @param top Stack top pointer
 * @return true if full
 */
bool Stack_isFull(size_t top) {
    return top >= STACK_LEN - 1;
}
