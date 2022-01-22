const char STR_NULL[STRLEN] = { CH_NULL };
const char *OPERATORS = "pe^&|/%*+-";
const char *VALID_CHARS = "0123456789(.pe^&|/%*+-)";

bool DEBUG = false;

char EXPRESSION[STRLEN] = { CH_NULL };
char STR_TOKEN[TOKEN_LEN] = { CH_NULL };

int TOKENS = 0;
char STR_TOKENS[MAX_TOKENS][TOKEN_LEN] = { { CH_NULL } };

byte OP_QUEUE[QUEUE_LEN] = { CH_NULL };
double NUM_QUEUE[QUEUE_LEN] = { 0.0 };

byte OP_STACK[STACK_LEN] = { CH_NULL };
double NUM_STACK[STACK_LEN] = { 0.0 };
