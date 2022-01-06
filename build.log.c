./src/main.c:18:35: warning: incompatible pointer to integer conversion initializing 'const char' with an expression of type 'void *' [-Wint-conversion]
const char EXPRESSION[STRLEN] = { NULL };
                                  ^~~~
/data/data/com.termux/files/usr/lib/clang/13.0.0/include/stddef.h:89:16: note: expanded from macro 'NULL'
#  define NULL ((void*)0)
               ^~~~~~~~~~
./src/main.c:19:34: warning: incompatible pointer to integer conversion initializing 'const char' with an expression of type 'void *' [-Wint-conversion]
const char STR_TOKEN[STRLEN] = { NULL };
                                 ^~~~
/data/data/com.termux/files/usr/lib/clang/13.0.0/include/stddef.h:89:16: note: expanded from macro 'NULL'
#  define NULL ((void*)0)
               ^~~~~~~~~~
./src/main.c:32:29: warning: incompatible pointer types initializing 'const size_t *const' (aka 'const unsigned long *const') with an expression of type 'char *' [-Wincompatible-pointer-types]
        const size_t* const ptr = strchr(VALID_CHARS, c);
                            ^     ~~~~~~~~~~~~~~~~~~~~~~
./src/main.c:35:21: warning: passing 'const char [2049]' to parameter of type 'char *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
            strncpy(STR_TOKEN, ptr, 1);
                    ^~~~~~~~~
/data/data/com.termux/files/usr/include/string.h:143:21: note: passing argument to parameter '__dst' here
char* strncpy(char* __dst, const char* __src, size_t __n);
                    ^
./src/main.c:35:32: warning: incompatible pointer types passing 'const size_t *const' (aka 'const unsigned long *const') to parameter of type 'const char *' [-Wincompatible-pointer-types]
            strncpy(STR_TOKEN, ptr, 1);
                               ^~~
/data/data/com.termux/files/usr/include/string.h:143:40: note: passing argument to parameter '__src' here
char* strncpy(char* __dst, const char* __src, size_t __n);
                                       ^
./src/main.c:43:17: warning: passing 'const char [2049]' to parameter of type 'char *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
        strncpy(STR_TOKEN, STR_NULL, STRLEN);
                ^~~~~~~~~
/data/data/com.termux/files/usr/include/string.h:143:21: note: passing argument to parameter '__dst' here
char* strncpy(char* __dst, const char* __src, size_t __n);
                    ^
./src/main.c:43:28: warning: incompatible pointer types passing 'const char *const [2049]' to parameter of type 'const char *' [-Wincompatible-pointer-types]
        strncpy(STR_TOKEN, STR_NULL, STRLEN);
                           ^~~~~~~~
/data/data/com.termux/files/usr/include/string.h:143:40: note: passing argument to parameter '__src' here
char* strncpy(char* __dst, const char* __src, size_t __n);
                                       ^
./src/main.c:48:25: warning: passing 'const char [2049]' to parameter of type 'char *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
                strncat(STR_TOKEN, &c, 1);
                        ^~~~~~~~~
/data/data/com.termux/files/usr/include/string.h:135:21: note: passing argument to parameter '__dst' here
char* strncat(char* __dst, const char* __src, size_t __n);
                    ^
8 warnings generated.
