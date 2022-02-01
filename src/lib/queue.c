# include "../headers/headers.h"
# include "../headers/errcodes.h"

# include "const.h"

/**
 * @brief Pushes item to char * queue.
 *
 * @param queue String queue pointer
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @param str   String to push
 */
void string_queue_push (char (*queue)[MAX_QUEUE_LEN], int *front, int *rear, const char *str)
{
    if (*front == QUEUE_INIT_FRONT) {
        *front = 0;
        *rear = 0;
    }
    if (*rear == MAX_QUEUE_LEN) {
        printf ("aritheval: string queue overflow\n");
        exit (E_BQOVFLOW);
    }
    strncpy(queue[(*rear)++], str, MAX_TOKEN_LEN);
}

/**
 * @brief Peeks at the front of the queue.
 *
 * @param queue String queue pointer
 * @param front Queue front pointer
 * @return char *
 */
char *string_queue_peek (char (*queue)[MAX_QUEUE_LEN], int *front)
{
    if (*front == QUEUE_INIT_FRONT) {
        printf ("aritheval: string queue underflow\n");
        exit (E_BQPEKUND);
    }
    return queue[*front];
}

/**
 * @brief Pops front of the queue.
 *
 * @param queue String queue pointer
 * @param front Queue front pointer
 * @param rear  Queue rear pointer
 * @return char *
 */
char *string_queue_pop (char (*queue)[MAX_QUEUE_LEN], int *front, int *rear)
{
    if (*front == QUEUE_INIT_FRONT) {
        printf ("aritheval: string queue underflow\n");
        exit (E_BQPOPUND);
    }
    char *value = queue[(*front)++];
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
