# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

# define true 1
# define false 0

# define CH_NULL (char) 0
# define STRLEN 2049
# define STRCPLEN (STRLEN - 1)

# define INVAL_TOKEN 0
# define CHAR_TOKEN 1
# define INT_TOKEN 2

# define RSLT_ACCURACY_FORM "%.5lf"

# define QUEUE_LEN STRLEN
# define QUEUE_INIT_FRONT -1
# define QUEUE_INIT_REAR -1