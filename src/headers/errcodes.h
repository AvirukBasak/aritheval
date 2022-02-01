# ifndef ERRCODES_H
    # define ERRCODES_H
    # define E_NOEXPR      1    // no expression provided
    # define E_EXCARGS     2    // too many arguments provided
    # define E_EXBLIM      3    // input exceeded limit of %d bytes
    # define E_EMPEXP      4    // expression can't be empty
    # define E_ENDCHAR     5    // expression can't end with '%c'
    # define E_STRTCHAR    6    // expression can't start with '%c'
    # define E_INVCHAR     7    // invalid character at posn: %ld
    # define E_UNSUPOP     8    // unsupported operation at posn: %ld
    # define E_EXMXTLEN    9    // exceeded maximum token length of %d bytes
    # define E_EXTKCOUNT  10    // exceeded maximum token count
    # define E_EXDOT      11    // excess dot found at posn: %ld
    # define E_NOENDDOT   12    // number can't end with a dot: %ld
    # define E_LOGICAL    13    // logical error, report output to developer
    # define E_UNRECOP    14    // unrecognised operator: %c
    # define E_BQOVFLOW   15    // byte queue overflow
    # define E_BQPEKUND   16    // byte queue underflow (peek)
    # define E_BQPOPUND   17    // byte queue underflow (pop)
    # define E_DQOVFLOW   18    // double queue overflow
    # define E_DQPEKUND   19    // double queue underflow (peek)
    # define E_DQPOPUND   20    // double queue underflow (pop)
    # define E_BSOVFLOW   21    // byte stack overflow
    # define E_BSPEKUND   22    // byte stack underflow (peek)
    # define E_BSPOPUND   23    // byte stack underflow (pop)
    # define E_DSOVFLOW   24    // double stack overflow
    # define E_DSPEKUND   25    // double stack underflow (peek)
    # define E_DSPOPUND   26    // double stack underflow (pop)
# endif
