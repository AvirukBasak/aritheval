# ifndef QUEUE_H

    # define QUEUE_H

    /**
     * @brief Pushes item to char * queue.
     *
     * @param queue String queue pointer
     * @param front Queue front pointer
     * @param rear  Queue rear pointer
     * @param str   String to push
     */
    void string_queue_push (char (*queue)[MAX_QUEUE_LEN], int *front, int *rear, const char *str);
    
    /**
     * @brief Peeks at the front of the queue.
     *
     * @param queue String queue pointer
     * @param front Queue front pointer
     * @return char *
     */
    char *string_queue_peek (char (*queue)[MAX_QUEUE_LEN], int *front);
    
    /**
     * @brief Pops front of the queue.
     *
     * @param queue String queue pointer
     * @param front Queue front pointer
     * @param rear  Queue rear pointer
     * @return char *
     */
    char *string_queue_pop (char (*queue)[MAX_QUEUE_LEN], int *front, int *rear);
    
    /**
     * @brief Check if stack empty
     *
     * @param front Queue front pointer
     * @param rear  Queue rear pointer
     * @return true if empty
     */
    bool queue_isempty (int *front, int *rear);
    
    /**
     * @brief Check if stack full
     *
     * @param front Queue front pointer
     * @param rear  Queue rear pointer
     * @return true if full
     */
    bool queue_isfull (int *front, int *rear);
    
# endif
