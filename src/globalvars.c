const char STR_NULL[MAX_STRLEN] = { CH_NULL };
const char *OPERATORS = "pe^&|/%*+-";
const char *VALID_CHARS = "0123456789(.pe^&|/%*+-)";

bool   g_debug = false;

char   g_expression    [MAX_STRLEN] = { CH_NULL };

int    g_tokens = 0;
char   g_tokenizedexp  [MAX_TOKENS][MAX_TOKEN_LEN] = { { CH_NULL } };

byte   g_opqueue       [MAX_QUEUE_LEN] = { CH_NULL };
double g_numqueue      [MAX_QUEUE_LEN] = { 0.0 };
byte   g_opstack       [MAX_QUEUE_LEN] = { CH_NULL };
double g_numstack      [MAX_QUEUE_LEN] = { 0.0 };
