# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

# define true                ( 1 )
# define false               ( 0 )

# define CH_NULL             ( ( char ) 0 )

# define OP_COUNT            ( 10 )

# define MAX_TOKENS          ( 1024 )
# define MAX_TOKEN_LEN       ( 1024 )
# define MAX_STRLEN          ( 2049 )
# define MAX_STRCPLEN        ( MAX_STRLEN - 1 )
# define MAX_RSLT_LEN        ( MAX_TOKEN_LEN )

# define INVAL_TOKEN         ( 0 )
# define CHAR_TOKEN          ( 1 )
# define INT_TOKEN           ( 2 )

# define RSLT_ACCURACY_FORM  ( "%.5lf" )

# define MAX_QUEUE_LEN       ( MAX_TOKENS )
# define QUEUE_INIT_FRONT    ( -1 )
# define QUEUE_INIT_REAR     ( -1 )

# define MAX_STACK_LEN       ( MAX_TOKENS )
# define STACK_INIT_TOP      ( -1 )
