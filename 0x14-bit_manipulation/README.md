Bit Manipulation

Bit manipulation refers to the act of manipulating individual bits that make up a binary data. In computer science, bitwise operations are common when dealing with binary values. Bitwise operations can be used to perform a variety of tasks, including encryption, compression, and network communication.

This README file is meant to serve as an introduction to bit manipulation and provide some examples of bitwise operations.
Bitwise Operators

Bitwise operators are used to perform bitwise operations on binary data. The following bitwise operators are commonly used:

    & (bitwise AND)
    | (bitwise OR)
    ^ (bitwise XOR)
    ~ (bitwise NOT)
    << (left shift)
    >> (right shift)

Bitwise AND (&)

The bitwise AND operator (&) returns a value where each bit is set to 1 only if the corresponding bits of both operands are 1. Otherwise, the bit is set to 0. For example:

sql

    0101 (decimal 5)
&   0011 (decimal 3)
  --------
    0001 (decimal 1)

In this example, the bitwise AND of 5 and 3 is 1.
Bitwise OR (|)

The bitwise OR operator (|) returns a value where each bit is set to 1 if either of the corresponding bits of the operands are 1. Otherwise, the bit is set to 0. For example:

sql

    0101 (decimal 5)
|   0011 (decimal 3)
  --------
    0111 (decimal 7)

In this example, the bitwise OR of 5 and 3 is 7.
Bitwise XOR (^)

The bitwise XOR operator (^) returns a value where each bit is set to 1 if the corresponding bits of the operands are different. Otherwise, the bit is set to 0. For example:

sql

    0101 (decimal 5)
^   0011 (decimal 3)
  --------
    0110 (decimal 6)

In this example, the bitwise XOR of 5 and 3 is 6.
Bitwise NOT (~)

The bitwise NOT operator (~) returns a value where each bit is inverted (i.e., 1 becomes 0, and 0 becomes 1). For example:

csharp

~0101 (decimal 5) = 1010 (decimal 10)

In this example, the bitwise NOT of 5 is 10.
Left Shift (<<)

The left shift operator (<<) shifts the bits of the first operand to the left by the number of positions specified by the second operand. For example:

sql

    0101 (decimal 5)
<<     2
  --------
    1010 (decimal 10)

In this example, the left shift of 5 by 2 positions is 10.
Right Shift (>>)

The right shift operator (>>) shifts the bits of the first operand to the right by the number of positions specified by the second operand. For example:

sql

    0101 (decimal 5)
>>     1
  --------
    0010 (decimal 2)

In this example, the right shift of 5 by 1 position is 2.
Conclusion

Bit manipulation is a powerful tool for working with binary data. Understanding the bitwise operators and how to use them can make it easier to work with binary data and perform tasks like encryption, compression, and network communication.
