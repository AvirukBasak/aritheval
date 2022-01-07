# define ENOEXPR      1    // no expression provided
# define EEXCARGS     2    // too many arguments provided
# define EEXBLIM      3    // input exceeded limit of %d bytes
# define EEMPEXP      4    // expression can't be empty
# define EENDCHAR     5    // expression can't end with '%c'
# define EINVCHAR     6    // invalid character at posn: %ld
# define EUNSUPOP     7    // unsupported operation at posn: %ld
# define EEXMXTLEN    8    // exceeded maximum token length of %d bytes
# define EEXTKCOUNT   9    // exceeded maximum token count
# define EEXDOT      10    // excess dot found at posn: %ld
# define ENOENDDOT   11    // number can't end with a dot: %ld
# define ELOGICAL    12    // logical error, report output to developer
# define EUNRECOP    13    // unrecognised operator: %c
# define EBQOVFLOW   14    // byte queue overflow
# define EBQPEKUND   15    // byte queue underflow (peek)
# define EBQPOPUND   16    // byte queue underflow (pop)
# define EDQOVFLOW   17    // double queue overflow
# define EDQPEKUND   18    // double queue underflow (peek)
# define EDQPOPUND   19    // double queue underflow (pop)
