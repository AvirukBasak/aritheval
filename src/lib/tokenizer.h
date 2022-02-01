# ifndef TOKENIZER_H

    # define TOKENIZER_H

    /**
     * @brief Tokenize expression
     *
     * @param const bool Debug flag
     * @param char[MAX_STRLEN] Expression
     * @oaram char[MAX_TOKENS][MAX_TOKEN_LEN] Writes tokens to this array
     * @return int -- The number of tokens
     */
    int tokenize (const bool debug, char expression[MAX_STRLEN], char tokenizedexp[MAX_TOKENS][MAX_TOKEN_LEN]);

# endif
