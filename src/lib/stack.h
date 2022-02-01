# ifndef STACK_H
    
    # define STACK_H

    /**
     * @brief Pushes item to byte stack.
     *
     * @param stack Byte stack pointer
     * @param top   Stack top pointer
     * @param ch    Character to push
     */
    void byte_stack_push (byte stack[MAX_STACK_LEN], int *top, byte ch);
    
    /**
     * @brief Peeks at the front of the stack.
     *
     * @param stack Byte stack pointer
     * @param top   Stack top pointer
     * @return byte
     */
    byte byte_stack_peek (byte stack[MAX_STACK_LEN], int *top);
    
    /**
     * @brief Pops front of the stack.
     *
     * @param stack Byte stack pointer
     * @param top   Stack top pointer
     * @return byte
     */
    byte byte_stack_pop (byte stack[MAX_STACK_LEN], int *top);
    
    /**
     * @brief Pushes item to Double stack.
     *
     * @param stack Double stack pointer
     * @param top   Stack top pointer
     * @param val   Value to push
     */
    void double_stack_push (double stack[MAX_STACK_LEN], int *top, double val);
    
    /**
     * @brief Peeks at the front of the stack.
     *
     * @param stack Double stack pointer
     * @param top   Stack top pointer
     */
    double double_stack_peek (double stack[MAX_STACK_LEN], int *top);
    
    /**
     * @brief Pops front of the stack.
     *
     * @param stack Double stack pointer
     * @param top   Stack top pointer
     * @return double
     */
    double double_stack_pop (double stack[MAX_STACK_LEN], int *top);
    
    /**
     * @brief Check if stack empty
     *
     * @param top Stack top pointer
     * @return true if empty
     */
    bool stack_isempty (int *top);
    
    /**
     * @brief Check if stack full
     *
     * @param top Stack top pointer
     * @return true if full
     */
    bool stack_isfull (int *top);
    
# endif
