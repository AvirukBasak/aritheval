./src/main.c:36:21: warning: passing 'const char [2049]' to parameter of type 'char *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
            strncpy(STR_TOKEN, ptr, 1);
                    ^~~~~~~~~
/data/data/com.termux/files/usr/include/string.h:143:21: note: passing argument to parameter '__dst' here
char* strncpy(char* __dst, const char* __src, size_t __n);
                    ^
./src/main.c:44:17: warning: passing 'const char [2049]' to parameter of type 'char *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
        strncpy(STR_TOKEN, STR_NULL, STRLEN);
                ^~~~~~~~~
/data/data/com.termux/files/usr/include/string.h:143:21: note: passing argument to parameter '__dst' here
char* strncpy(char* __dst, const char* __src, size_t __n);
                    ^
./src/main.c:49:25: warning: passing 'const char [2049]' to parameter of type 'char *' discards qualifiers [-Wincompatible-pointer-types-discards-qualifiers]
                strncat(STR_TOKEN, &c, 1);
                        ^~~~~~~~~
/data/data/com.termux/files/usr/include/string.h:135:21: note: passing argument to parameter '__dst' here
char* strncat(char* __dst, const char* __src, size_t __n);
                    ^
3 warnings generated.
