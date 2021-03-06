# ArithEval
Arithmetic evaluation program in C.

## Usage
```bash
$ make
$ make run exp="[expression]"
```

### Example
```bash
$ make
$ make run exp="1+3/9*\(0-8\)p2"
```


## Operators

Following operators are supported, in the order of their precedence.

```
OPERATOR    USE     MEANING

   e       5 e 3    5 * ( 10 to the power of 3 )
   p       5 p 3    5 to the power of 3
   /       5 / 3    5 divided by 3
   %       5 % 3    remainder of 5 divided by 3
   *       5 * 3    product of 5 and 3
   +       5 + 3    sum of 5 and 3
   -       5 - 3    difference of 5 and 3
   ^       5 ^ 3    binary xor of 5 and 3
   &       5 & 3    binary and of 5 and 3
   |       5 | 3    binary or of 5 and 3

```

## Valid characters

```
0 1 2 3 4 5 6 7 8 9 ( \t \n \r \f \s . e p / % * + - ^ & | )
```
