# include "stdio.h"
# include "string.h"
# include "stdlib.h"
# include "ctype.h"

# define STRLEN 2049

# define INVAL_TOKEN 0
# define CHAR_TOKEN 1
# define INT_TOKEN 2

typedef char byte;

const char* const STR_NULL[STRLEN] = { NULL };
const char* const OPERATORS = "^/*+-";
const char* const VALID_CHARS = "0123456789( .^/*+-)";

const char EXPRESSION[STRLEN] = { NULL };
const char STR_TOKEN[STRLEN] = { NULL };

/**
 * @brief Returns type of next token and sets STR_TOKEN to that token.
 * 
 * @param posn Posn from where to look for token
 * @return byte -- Type of token
 */
byte nextToken(const size_t posn)
{
    char c = EXPRESSION[posn];
    if (!isdigit(c))
    {
        const size_t* const ptr = strchr(VALID_CHARS, c);
        if (ptr)
        {
            strncpy(STR_TOKEN, ptr, 1);
            return CHAR_TOKEN;
        }
        else
            return INVAL_TOKEN;
    }
    else
    {
        strncpy(STR_TOKEN, STR_NULL, STRLEN);
        for (size_t i = posn; ; i++)
        {
            char c = EXPRESSION[i];
            if (isdigit(c))
                strncat(STR_TOKEN, &c, 1);
            else
                return INT_TOKEN;
        }
    }
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
    
    return 0.0;
}

int main(const int argc, const char* const argv[])
{
    if (argc < 2)
    {
        printf("aritheval: no expression provided\n"
               "USAGE: aritheval \"[expression]\"\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("%s\n", "aritheval: too many arguments provided");
        return 2;
    }
    else if (strlen(argv[1]) > STRLEN)
    {
        printf("%s\n", "aritheval: input exceeded limit 2KB");
        return 3;
    }
    strncpy((char*)EXPRESSION, argv[1], STRLEN);
    const double result = eval(0, strlen(EXPRESSION), 3);
    printf("Result = %.5lf", result);
    return 0;
}
