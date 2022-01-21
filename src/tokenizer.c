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
            exit(EINVCHAR);
        }

        bool is_op_bracket = false;
        bool is_cl_bracket = false;
        if (c == '(')
            is_op_bracket = true;
        if (c == ')')
            is_cl_bracket = true;

        // checks next index for valid characters
        c = EXPRESSION[*posn];
        ptr = strchr(VALID_CHARS, c);
        if (!ptr)
        {
            printf("aritheval: invalid character at posn: %ld\n", *posn);
            exit(EINVCHAR);
        }
        else if (is_cl_bracket) {}
        else if (!isdigit(EXPRESSION[*posn]) && EXPRESSION[*posn] != '.' && EXPRESSION[*posn] != '('
             &&  EXPRESSION[*posn] != '+'    && EXPRESSION[*posn] != '-')
        {
            printf("aritheval: unsupported operation at posn: %ld\n", *posn);
            exit(EUNSUPOP);
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
            // if token length exceeded limit
            if (i > TOKEN_LEN)
            {
                printf("aritheval: exceeded maximum token length of %d bytes\n", TOKEN_LEN);
                exit(EEXMXTLEN);
            }
            char c = EXPRESSION[*posn];

            // if c is a digit, concatenate it to STR_TOKEN
            if (c == '.')
            {
                strncat(STR_TOKEN, &c, 1);
                if (dot_found)
                {
                    printf("aritheval: excess dot found at posn: %ld\n", *posn);
                    exit(EEXDOT);
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
                    exit(ENOENDDOT);
                }

                // set token_type, end STR_TOKEN with null and break loop
                token_type = INT_TOKEN;
                STR_TOKEN[i] = 0;
                break;
            }
        }
    }
    return token_type;
}

/**
 * @brief Tokenize expression
 */
void tokenize()
{
    // Loop through the entire input
    for (size_t i = 0; i < strlen(EXPRESSION); TOKENS++)
    {
        // if token count exceeded limit
        if (TOKENS > MAX_TOKENS)
        {
            printf("aritheval: exceeded maximum token count: %ld tokens found\n", TOKENS);
            exit(EEXTKCOUNT);
        }

        size_t posn = i;
        byte token_type = nextToken(&posn);
        switch (token_type)
        {
            case INT_TOKEN:
                strncpy(STR_TOKENS[TOKENS], STR_TOKEN, strlen(STR_TOKEN));
                break;
            case CHAR_TOKEN:
                strncpy(STR_TOKENS[TOKENS], STR_TOKEN, strlen(STR_TOKEN));
                break;
            default:
                printf("aritheval: logical error, report output to developer\n"
                       "token_type = %d\n"
                       "STR_TOKEN  = %s\n", token_type, STR_TOKEN);
                exit(ELOGICAL);
        }
        i = posn;
    }
    TOKENS--;
}
