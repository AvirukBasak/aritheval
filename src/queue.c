void pushByte(byte *queue, size_t *front, size_t *rear, byte ch)
{
    if (*front == QUEUE_INIT_FRONT)
    {
        *front = 0;
        *rear = 0;
    }
    if (*rear == QUEUE_LEN)
    {
        printf("aritheval: byte queue overflow\n");
        exit(11);
    }
    queue[(*rear)++] = ch;
}

byte popByte(byte *queue, size_t *front, size_t *rear)
{
    if (*front == QUEUE_INIT_REAR)
    {
        printf("aritheval: byte queue underflow\n");
        exit(12);
    }
    byte value = queue[(*front)++];
    if (*rear == *front)
    {
        *front = QUEUE_INIT_FRONT;
        *rear = QUEUE_INIT_REAR;
    }
    return value;
}

void pushDouble(double *queue, size_t *front, size_t *rear, double val)
{
    if (*front == QUEUE_INIT_FRONT)
    {
        *front = 0;
        *rear = 0;
    }
    if (*rear == QUEUE_LEN)
    {
        printf("aritheval: double queue overflow\n");
        exit(11);
    }
    queue[(*rear)++] = val;
}

double popDouble(double *queue, size_t *front, size_t *rear)
{
    if (*front == QUEUE_INIT_REAR)
    {
        printf("aritheval: double queue underflow\n");
        exit(12);
    }
    double value = queue[(*front)++];
    if (*rear == *front)
    {
        *front = QUEUE_INIT_FRONT;
        *rear = QUEUE_INIT_REAR;
    }
    return value;
}

void foo()
{
    size_t front = QUEUE_INIT_FRONT;
    size_t rear = QUEUE_INIT_REAR;
    pushDouble(NUM_QUEUE, &front, &rear, 14.56);
}
