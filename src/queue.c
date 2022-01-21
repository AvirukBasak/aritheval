/**
 * @brief Pushes item to byte queue.
 *
 * @param queue Byte queue pointer
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @param ch    Character to push
 */
void Queue_Byte_push(byte *queue, size_t *front, size_t *rear, byte ch)
{
    if (*front == QUEUE_INIT_FRONT)
    {
        *front = 0;
        *rear = 0;
    }
    if (*rear == QUEUE_LEN)
    {
        printf("aritheval: byte queue overflow\n");
        exit(EBQOVFLOW);
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
byte Queue_Byte_peek(byte *queue, size_t *front)
{
    if (*front == QUEUE_INIT_FRONT)
    {
        printf("aritheval: byte queue underflow\n");
        exit(EBQPEKUND);
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
byte Queue_Byte_pop(byte *queue, size_t *front, size_t *rear)
{
    if (*front == QUEUE_INIT_FRONT)
    {
        printf("aritheval: byte queue underflow\n");
        exit(EBQPOPUND);
    }
    byte value = queue[(*front)++];
    if (*rear == *front)
    {
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
void Queue_Double_push(double *queue, size_t *front, size_t *rear, double val)
{
    if (*front == QUEUE_INIT_FRONT)
    {
        *front = 0;
        *rear = 0;
    }
    if (*rear == QUEUE_LEN)
    {
        printf("aritheval: double queue overflow\n");
        exit(EDQOVFLOW);
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
double Queue_Double_peek(double *queue, size_t *front)
{
    if (*front == QUEUE_INIT_FRONT)
    {
        printf("aritheval: double queue underflow\n");
        exit(EDQPEKUND);
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
double Queue_Double_pop(double *queue, size_t *front, size_t *rear)
{
    if (*front == QUEUE_INIT_FRONT)
    {
        printf("aritheval: double queue underflow\n");
        exit(EDQPOPUND);
    }
    double value = queue[(*front)++];
    if (*rear == *front)
    {
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
bool Queue_isEmpty(size_t *front, size_t *rear) {
    return *front == QUEUE_INIT_FRONT;
}

/**
 * @brief Check if stack full
 *
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @return true if full
 */
bool Queue_isFull(size_t *front, size_t *rear) {
    return *rear == QUEUE_LEN;
}
