const char STR_NULL[MAX_STRLEN] = { CH_NULL };
const char *OPERATORS = "pe^&|/%*+-";
const char *VALID_CHARS = "0123456789(.pe^&|/%*+-)";

bool   g_debug = false;

char   g_expression    [MAX_STRLEN] = { CH_NULL };

int    g_tokens = 0;
char   g_tokenizedexp  [MAX_TOKENS][MAX_TOKEN_LEN]    = { { CH_NULL } };

// postfix stack
char   g_postfixqueue  [MAX_QUEUE_LEN][MAX_TOKEN_LEN] = { { CH_NULL } };
int    g_postfixqueue_front = QUEUE_INIT_FRONT;
int    g_postfixqueue_rear = QUEUE_INIT_REAR;
