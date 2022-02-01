# include "../headers/headers.h"
# include "../headers/errcodes.h"

# include "const.h"
# include "globals.h"

/**
 * @brief Returns true if operator, else false
 *
 * @param size_t* Position of concerned character
 * @return bool
 */
bool tokenizer_isOperator (size_t *posn) {

    const char prev_char = !(*posn) ? Expression[*posn - 1] : '\0';
    const char this_char = Expression[*posn];
    const char next_char = Expression[*posn + 1];

    // check if character is valid
    if (!strchr (VALID_CHARS, this_char)) {
        printf ("aritheval: invalid character '%c' at posn: %ld\n", this_char, *posn);
        exit (E_INVCHAR);
    }

    // if character is operator
    if (strchr (OPERATORS, this_char)) {
        // preceded and followed by non-operators
        if (!strchr (OPERATORS, prev_char) && !strchr (OPERATORS, next_char)) {
            return true;
        }
        // preceded by non-operator, followed by operator
        else if (!strchr (OPERATORS, prev_char) && strchr (OPERATORS, next_char)) {
            return true;
        }
        // preceded by operator, followed by non-operator
        else if (strchr (OPERATORS, prev_char) && !strchr (OPERATORS, next_char)) {
            // only + or - is allowed to precede a digit
            if (strchr ("+-", this_char)) {
                return false;
            }
            printf ("aritheval: invalid use of operator '%c' at posn: %ld\n", this_char, *posn);
            exit (E_INVCHAR);
        }
        // preceded by operator, followed by operator
        else if (strchr (OPERATORS, prev_char) && strchr (OPERATORS, next_char)) {
            
            printf ("aritheval: multiple instances of operator '%c' found at posn: %ld\n", this_char, *posn);
            exit (E_MULOPINST);
        }
    } else if (strchr ("()", this_char)) {
        return true;
    }
    return false;
}

/**
 * @brief Returns type of next token and sets strtoken to that token.
 *
 * @param posn Posn From where to look for tokens, gets updated.
 * @param strtoken Pointer to variable that is set to the next token.
 * @return byte -- Type of token
 */
byte tokenizer_nextToken (size_t *posn, char *strtoken)
{
    byte token_type = INVAL_TOKEN;
    size_t len = strlen (Expression);

    if (tokenizer_isOperator (posn)) {
        
    } else {
        
    }

    return token_type;
}

/**
 * @brief Tokenize expression
 *
 * @param char [MAX_TOKENS][MAX_TOKEN_LEN] Writes tokens to this array
 * @return int -- The number of tokens
 */
int tokenize (char tokenizedexp [MAX_TOKENS][MAX_TOKEN_LEN])
{
    int tokens = 0;

    // Loop through the entire input
    for (size_t i = 0; i < strlen (Expression); tokens++) {

        // stores the next token
        char strtoken[MAX_TOKEN_LEN] = { CH_NULL };

        // if token count exceeded limit
        if (tokens > MAX_TOKENS) {
            printf ("aritheval: exceeded maximum token count: %d tokens found\n", tokens);
            exit (E_EXTKCOUNT);
        }

        size_t posn = i;
        byte token_type = tokenizer_nextToken (&posn, strtoken);
        switch (token_type) {
            case INT_TOKEN:
                strncpy (tokenizedexp[tokens], strtoken, strlen (strtoken));
                break;
            case CHAR_TOKEN:
                strncpy (tokenizedexp[tokens], strtoken, strlen (strtoken));
                break;
            default:
                printf ("aritheval: logical error, report this output to developer\n"
                        "    token_type = %d\n"
                        "    strtoken  = %s\n", token_type, strtoken);
                exit (E_LOGICAL);
        }
        i = posn;
    }
    tokens--;
    return tokens;
}
