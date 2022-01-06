# include "stdio.h"
# include "string.h"
# include "stdlib.h"
# include "ctype.h"

# define CH_NULL (char) 0
# define STRLEN 2049
# define STRCPLEN (STRLEN - 1)

# define INVAL_TOKEN 0
# define CHAR_TOKEN 1
# define INT_TOKEN 2

typedef char *string;
typedef char byte;

const char STR_NULL[STRLEN] = { CH_NULL };
const char *OPERATORS = "^/*+-";
const char *VALID_CHARS = "0123456789( .^/*+-)";

char EXPRESSION[STRLEN] = { CH_NULL };
char STR_TOKEN[STRLEN] = { CH_NULL };

/**
 * @brief Returns type of next token and sets STR_TOKEN to that token.
 * 
 * @param posn Posn From where to look for tokens, gets updated.
 * @return byte -- Type of token
 */
byte nextToken(size_t *posn)
{
    STR_TOKEN[0] = 0;
    byte token_type = INVAL_TOKEN;
    size_t len = strlen(EXPRESSION);

    // get character
    char c = EXPRESSION[*posn];

    // if character isn't a digit
    if (!isdigit(c))
    {
        // if character is present in VALID_CHARS, ptr is non-NULL
        char *ptr = strchr(VALID_CHARS, c);
        if (ptr)
        {
            // if ptr is non-NULL, copy character to STR_TOKEN and return
            STR_TOKEN[0] = *ptr;
            STR_TOKEN[1] = 0;
            (*posn)++;
            token_type = CHAR_TOKEN;
        }
        else {
            printf("aritheval: invalid character at posn: %ld\n", *posn);
        }
    }
    else
    {
        // while *posn < len, Loop through the EXPRESSION
        for (size_t i = 0; ; i++, (*posn)++)
        {
            char c = EXPRESSION[*posn];
            if (isdigit(c))
                // if c is a digit, concatenate it to STR_TOKEN
                strncat(STR_TOKEN, &c, 1);
            else
            {
                // return INT_TOKEN code when digits are finished
                token_type = INT_TOKEN;
                STR_TOKEN[i] = 0;
                break;
            }
        }
    }
    // printf("> %s\n", STR_TOKEN);
    return token_type;
}

/**
 * @brief Returns evaluation of an expression
 * 
 * @param init Initial posn of expression
 * @param final Final posn of expression
 * @return double 
 */
double eval(const size_t init, const size_t final, byte op)
{
    double num1 = 0.0;
    double num2 = 0.0;
    double rslt = 0.0;

    size_t len = strlen(EXPRESSION);
    char *posn = EXPRESSION;

    // Loop through the entire input
    for (size_t i = 0; i < len; ) {
        size_t posn = i;
        byte token_type = nextToken(&posn);
        switch (token_type) {
            case INT_TOKEN:
                printf("N:%s\n", STR_TOKEN);
                break;
            case CHAR_TOKEN:
                printf("O:%s\n", STR_TOKEN);
                break;
            case INVAL_TOKEN:
                exit(4);
                break;
            default:
                printf("aritheval: logical error\n"
                       "token_type = %d\n"
                       "STR_TOKEN  = %s\n", token_type, STR_TOKEN);
                break;
        }
        i = posn;
    }
    return 0.0;
}

int main(const int argc, const char *const argv[])
{
    if (argc < 2)
    {
        printf("aritheval: no expression provided\n"
               "USAGE: aritheval \"[expression]\"\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("aritheval: too many arguments provided\n"
               "USAGE: aritheval \"[expression]\"\n");
        return 2;
    }
    else if (strlen(argv[1]) > STRCPLEN)
    {
        printf("aritheval: input exceeded limit of %d bytes\n", STRLEN);
        return 3;
    }
    strncpy(EXPRESSION, argv[1], STRCPLEN);
    const double result = eval(0, strlen(EXPRESSION), 3);
    printf("Result = %.5lf\n", result);
    return 0;
}
