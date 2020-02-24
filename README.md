# My Brainfuck
[Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) is one of the esoteric programming languages.
This uses only `>`, `<`, `+`, `-`, `.`, `,`, `[` and `]`. Other characters are ignore.

|Character|Meaning|
|:-------:|:------|
|`>`|Increment the data pointer|
|`<`|Decrement the data pointer|
|`+`|Increment (increase by one) the byte at the data pointer.|
|`-`|Decrement (decrease by one) the byte at the data pointer.|
|`.`|Output the byte at the data pointer.|
|`,`|Accept one byte of input, storing its value in the byte at the data pointer.|
|`[`|If the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching `]` command.|
|`]`|If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching `[` command.|

# Usage

Make an executable file.

```
$ make
```

From file.

```
$ echo '+++++++++[>++++++++>+++++++++++>+++>+<<<<-]>.>++.+++++++..+++.>+++++.<<+++++++++++++++.>.+++.------.--------.>+.>+.' > hello.bf
$ ./bf hello.bf
Hello World!
```

From command line.

```
$ ./bf '+++++++++[>++++++++>+++++++++++>+++>+<<<<-]>.>++.+++++++..+++.>+++++.<<+++++++++++++++.>.+++.------.--------.>+.>+.'
Hello World!
```
