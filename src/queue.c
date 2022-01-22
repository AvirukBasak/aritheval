/**
 * @brief Pushes item to byte queue.
 *
 * @param queue Byte queue pointer
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @param ch    Character to push
 */
void Queue_Byte_push(byte *queue, int *front, int *rear, byte ch)
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
byte Queue_Byte_peek(byte *queue, int *front)
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
byte Queue_Byte_pop(byte *queue, int *front, int *rear)
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
void Queue_Double_push(double *queue, int *front, int *rear, double val)
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
double Queue_Double_peek(double *queue, int *front)
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
double Queue_Double_pop(double *queue, int *front, int *rear)
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
bool Queue_isEmpty(int *front, int *rear) {
    return *front == QUEUE_INIT_FRONT;
}

/**
 * @brief Check if stack full
 *
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @return true if full
 */
bool Queue_isFull(int *front, int *rear) {
    return *rear == QUEUE_LEN;
}
