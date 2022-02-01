# include "../headers/headers.h"
# include "../headers/errcodes.h"

# include "const.h"
# include "globals.h"

/**
 * @brief Returns type of next token and sets strtoken to that token.
 *
 * @param posn Posn From where to look for tokens, gets updated.
 * @param strtoken Pointer to variable that is set to the next token.
 * @return byte -- Type of token
 */
byte nextToken (size_t *posn, char *strtoken)
{
    byte token_type = INVAL_TOKEN;
    size_t len = strlen (Expression);

    // get character
    char c = Expression[*posn];

    if (!isdigit (c) && c != '.') {

        // if character is present in VALID_CHARS, ptr is non-NULL
        char *ptr = strchr (VALID_CHARS, c);

        /* if ptr is non-NULL, increment *posn copy character to strtoken,
         * end strtoken, and set token_type.
         */
        if (ptr) {
            (*posn)++;
            strtoken[0] = *ptr;
            strtoken[1] = 0;
            token_type = CHAR_TOKEN;
        } else {
            printf ("aritheval: invalid character at posn: %ld\n", *posn);
            exit (E_INVCHAR);
        }

        bool is_op_bracket = false;
        bool is_cl_bracket = false;
        if (c == '(') {
            is_op_bracket = true;
        }
        if (c == ')') {
            is_cl_bracket = true;
        }

        // checks next index for valid characters
        c = Expression[*posn];
        ptr = strchr (VALID_CHARS, c);
        if (!ptr) {
            printf ("aritheval: invalid character at posn: %ld\n", *posn);
            exit (E_INVCHAR);
        } else if (is_cl_bracket) {
        } else if (!isdigit (Expression[*posn]) && Expression[*posn] != '.' && Expression[*posn] != '('
                                                  && Expression[*posn] != '+' && Expression[*posn] != '-') {
            printf ("aritheval: unsupported operation at posn: %ld\n", *posn);
            exit (E_UNSUPOP);
        }
    }
    else {

        strtoken[0] = 0;

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

            // if c is a digit, concatenate it to strtoken
            if (c == '.') {
                /* strncat () concatenates from null character of string.
                 * since we wish to overwrite the strtoken with new token, we set this
                 */
                strncat (strtoken, &c, 1);
                if (dot_found) {
                    printf ("aritheval: excess dot found at posn: %ld\n", *posn);
                    exit (E_EXDOT);
                } else {
                    dot_found = true;
                }
            } else if (isdigit (c)) {
                strncat (strtoken, &c, 1);
            } else {
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
