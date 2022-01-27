/**
 * @brief Pushes item to byte queue.
 *
 * @param queue Byte queue pointer
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @param ch    Character to push
 */
void byte_queue_push (byte *queue, int *front, int *rear, byte ch)
{
    if (*front == QUEUE_INIT_FRONT) {
        *front = 0;
        *rear = 0;
    }
    if (*rear == MAX_QUEUE_LEN) {
        printf ("aritheval: byte queue overflow\n");
        exit (E_BQOVFLOW);
    }
    queue[(*rear)++] = ch;
}

/**
 * @brief Peeks at the front of the queue.
 *
 * @param queue Byte queue pointer
 * @param front Queue front pointer
 * @return byte
 */
byte byte_queue_peek (byte *queue, int *front)
{
    if (*front == QUEUE_INIT_FRONT) {
        printf ("aritheval: byte queue underflow\n");
        exit (E_BQPEKUND);
    }
    return queue[*front];
}

/**
 * @brief Pops front of the queue.
 *
 * @param queue Byte queue pointer
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @return byte
 */
byte byte_queue_pop (byte *queue, int *front, int *rear)
{
    if (*front == QUEUE_INIT_FRONT) {
        printf ("aritheval: byte queue underflow\n");
        exit (E_BQPOPUND);
    }
    byte value = queue[(*front)++];
    if (*rear == *front) {
        *front = QUEUE_INIT_FRONT;
        *rear = QUEUE_INIT_REAR;
    }
    return value;
}

/**
 * @brief Pushes item to Double queue.
 *
 * @param queue Double queue pointer
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @param val   Value to push
 */
void double_queue_push (double *queue, int *front, int *rear, double val)
{
    if (*front == QUEUE_INIT_FRONT) {
        *front = 0;
        *rear = 0;
    }
    if (*rear == MAX_QUEUE_LEN) {
        printf ("aritheval: double queue overflow\n");
        exit (E_DQOVFLOW);
    }
    queue[(*rear)++] = val;
}

/**
 * @brief Peeks at the front of the queue.
 *
 * @param queue Double queue pointer
 * @param front Queue front pointer
 * @return double
 */
double double_queue_peek (double *queue, int *front)
{
    if (*front == QUEUE_INIT_FRONT) {
        printf ("aritheval: double queue underflow\n");
        exit (E_DQPEKUND);
    }
    return queue[*front];
}

/**
 * @brief Pops front of the queue.
 *
 * @param queue Double queue pointer
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @return double
 */
double double_queue_pop (double *queue, int *front, int *rear)
{
    if (*front == QUEUE_INIT_FRONT) {
        printf ("aritheval: double queue underflow\n");
        exit (E_DQPOPUND);
    }
    double value = queue[(*front)++];
    if (*rear == *front) {
        *front = QUEUE_INIT_FRONT;
        *rear = QUEUE_INIT_REAR;
    }
    return value;
}

/**
 * @brief Check if stack empty
 *
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @return true if empty
 */
bool queue_isempty (int *front, int *rear)
{
    return *front == QUEUE_INIT_FRONT;
}

/**
 * @brief Check if stack full
 *
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @return true if full
 */
bool queue_isfull (int *front, int *rear)
{
    return *rear == MAX_QUEUE_LEN;
}
