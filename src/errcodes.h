# define ENOEXPR      1    // no expression provided
# define EEXCARGS     2    // too many arguments provided
# define EEXBLIM      3    // input exceeded limit of %d bytes
# define EEMPEXP      4    // expression can't be empty
# define EENDCHAR     5    // expression can't end with '%c'
# define ESTRTCHAR    6    // expression can't start with '%c'
# define EINVCHAR     7    // invalid character at posn: %ld
# define EUNSUPOP     8    // unsupported operation at posn: %ld
# define EEXMXTLEN    9    // exceeded maximum token length of %d bytes
# define EEXTKCOUNT  10    // exceeded maximum token count
# define EEXDOT      11    // excess dot found at posn: %ld
# define ENOENDDOT   12    // number can't end with a dot: %ld
# define ELOGICAL    13    // logical error, report output to developer
# define EUNRECOP    14    // unrecognised operator: %c
# define EBQOVFLOW   15    // byte queue overflow
# define EBQPEKUND   16    // byte queue underflow (peek)
# define EBQPOPUND   17    // byte queue underflow (pop)
# define EDQOVFLOW   18    // double queue overflow
# define EDQPEKUND   19    // double queue underflow (peek)
# define EDQPOPUND   20    // double queue underflow (pop)
