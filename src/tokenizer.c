/**
 * @brief Returns type of next token and sets STR_TOKEN to that token.
 * 
 * @param posn Posn From where to look for tokens, gets updated.
 * @return byte -- Type of token
 */
byte nextToken(size_t *posn)
{
    byte token_type = INVAL_TOKEN;
    size_t len = strlen(EXPRESSION);

    // get character
    char c = EXPRESSION[*posn];

    // if character isn't a digit
    if (!isdigit(c) && c != '.')
    {
        // if character is present in VALID_CHARS, ptr is non-NULL
        char *ptr = strchr(VALID_CHARS, c);

        /* if ptr is non-NULL, increment *posn copy character to STR_TOKEN,
         * end STR_TOKEN, and set token_type.
         */
        if (ptr)
        {
            (*posn)++;
            STR_TOKEN[0] = *ptr;
            STR_TOKEN[1] = 0;
            token_type = CHAR_TOKEN;
        }
        else
        {
            printf("aritheval: invalid character at posn: %ld\n", *posn);
            exit(5);
        }
    }
    else
    {
        /* strncat() concatenates from null character of string.
         * since we wish to overwrite the STR_TOKEN with new token, we set this
         */
        STR_TOKEN[0] = 0;

        // tracks if more than 1 dot was found
        bool dot_found = false;

        // while *posn < len, Loop through the EXPRESSION
        for (size_t i = 0; ; i++, (*posn)++)
        {
            char c = EXPRESSION[*posn];
            
            // if c is a digit, concatenate it to STR_TOKEN
            if (c == '.') {
                strncat(STR_TOKEN, &c, 1);
                if (dot_found) {
                    printf("aritheval: excess dot found at: %ld\n", *posn);
                    exit(6);
                }
                else
                    dot_found = true;
            }
            else if (isdigit(c))
                strncat(STR_TOKEN, &c, 1);
            else
            {
                if (STR_TOKEN[i - 1] == '.')
                {
                    printf("aritheval: number can't end with a dot: %ld\n", *posn);
                    exit(7);
                }

                // set token_type, end STR_TOKEN with null and break loop
                token_type = INT_TOKEN;
                STR_TOKEN[i] = 0;
                break;
            }
        }
    }
    // printf("> %s\n", STR_TOKEN);
    return token_type;
}
