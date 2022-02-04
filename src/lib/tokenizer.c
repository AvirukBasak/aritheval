# include "../headers/headers.h"
# include "../headers/errcodes.h"

# include "const.h"
# include "globals.h"

/**
 * @brief Returns true if non number, else false
 *
 * @param size_t* Position of concerned character
 * @return bool
 */
bool tokenizer_isNonNumeric (size_t posn)
{
    const char prev_char = posn ? Expression[posn - 1] : '\0';
    const char this_char = Expression[posn];
    const char next_char = Expression[posn + 1];

    // check if character is valid
    if (!strchr (VALID_CHARS, this_char)) {
        printf ("aritheval: invalid character '%c' at posn: %ld\n", this_char, posn);
        exit (E_INVCHAR);
    }

    // spaces are treated as non numbers
    if (strchr (" \t\n\r\f", this_char)) {
        return true;
    }

    // if character is non number
    if (strchr (OPERATORS, this_char)) {
        // preceded and followed by number
        if (!strchr (OPERATORS, prev_char) && !strchr (OPERATORS, next_char)) {
            return true;
        }
        // preceded by number, followed by non numbers
        else if (!strchr (OPERATORS, prev_char) && strchr (OPERATORS, next_char)) {
            return true;
        }
        // preceded by number, followed by number
        else if (strchr (OPERATORS, prev_char) && !strchr (OPERATORS, next_char)) {
            // only + or - is allowed to precede a digit
            if (strchr ("+-", this_char)) {
                return false;
            }
            printf ("aritheval: invalid use of operator '%c' at posn: %ld\n", this_char, posn);
            exit (E_INVCHAR);
        }
        // preceded by non numbers, followed by non numbers
        else if (strchr (OPERATORS, prev_char) && strchr (OPERATORS, next_char)) {
            printf ("aritheval: multiple instances of operator '%c' found at posn: %ld\n", this_char, posn);
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
 * @return byte
- Type of token
 */
byte tokenizer_nextToken (size_t *posn, char *strtoken)
{
    byte token_type = INVAL_TOKEN;

    char c = Expression[*posn];

    // ignoring delimiters and spaces
    while (strchr (" \t\n\r\f ", c)) {
        c = Expression[++(*posn)];
    }

    if (tokenizer_isNonNumeric (*posn)) {
        (*posn)++;
        strtoken[0] = c;
        strtoken[1] = 0;
        token_type = CHAR_TOKEN;
    } else {
        // tracks if more than 1 dot was found
        bool dot_found = false;
        // while *posn < len, Loop through the EXPRESSION
        for (size_t i = 0; ; i++, (*posn)++) {
            // if token length exceeded limit
            if (i > MAX_TOKEN_LEN) {
                printf ("aritheval: exceeded maximum token length of %d bytes\n", MAX_TOKEN_LEN);
                exit (E_EXMXTLEN);
            }
            char c = Expression[*posn];
            // if c is '.', concatenate it to strtoken
            if (c == '.') {
                if (dot_found) {
                    printf ("aritheval: excess dot found at posn: %ld\n", *posn);
                    exit (E_EXDOT);
                } else {
                    dot_found = true;
                }
                /* strncat () concatenates from null character of string.
                 * since we wish to overwrite the strtoken with new token, we set this
                 */
                strncat (strtoken, &c, 1);
            }
            // if c is digit or '+' or '-', concatenate it to strtoken
            else if (isdigit (c) || !tokenizer_isNonNumeric (*posn)) {
                strncat (strtoken, &c, 1);
            }
            else {
                if (strtoken[i - 1] == '.') {
                    printf ("aritheval: number can't end with a dot: %ld\n", *posn);
                    exit (E_NOENDDOT);
                }
                // set token_type, end strtoken with null and break loop
                token_type = INT_TOKEN;
                strtoken[i] = 0;
                break;
            }
        }
    }

    return token_type;
}

/**
 * @brief Tokenize expression
 *
 * @param char [MAX_TOKENS][MAX_TOKEN_LEN] Writes tokens to this array
 * @return int
- The number of tokens
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
                if (DEBUG) printf("[ N: %s ]\n", strtoken);
                break;
            case CHAR_TOKEN:
                strncpy (tokenizedexp[tokens], strtoken, strlen (strtoken));
                if (DEBUG) printf("[ O: %s ]\n", strtoken);
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
