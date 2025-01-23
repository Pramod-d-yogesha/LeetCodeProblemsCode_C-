/*
191. Number of 1 Bits

Given a positive integer n, write a function that returns the number of  set bits in its binary representation (also known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3

Explanation:
The input binary string 1011 has a total of three set bits.

Example 2:
Input: n = 128
Output: 1

Explanation:
The input binary string 10000000 has a total of one set bit.

Example 3:
Input: n = 2147483645
Output: 30

Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.
==========================================================================================================================================
### 1. Bitwise AND (&) Operator:
- The bitwise AND operator (&) compares corresponding bits of two numbers and returns 1 if both bits are 1; otherwise, it returns 0.
- In this case, you're comparing the binary representation of the number n with 1. This means you're checking the least significant bit (LSB) of n, because 1 in binary is 000...001, which has only the rightmost bit set to 1.

### 2. Effect of n & 1:
- If n is odd:
    - The LSB is 1, so n & 1 will return 1.
- If n is even:
    - The LSB is 0, so n & 1 will return 0.

### 3. Counting the 1 Bits:
- The goal of the function is to count the number of 1 bits (also known as the Hamming weight or population count).

Here's how it works:
- If the LSB of n is 1 (i.e., the number is odd), it adds 1 to the count.
- If the LSB of n is 0 (i.e., the number is even), it adds 0 to the count.
- After checking the current LSB, you shift n to the right by one bit (n >>= 1) to examine the next bit.

### Example Walkthrough:
Let’s say n = 11, which in binary is 1011.

**First check:**
- n & 1 → 1011 & 0001 → 0001, which is 1.
- So, count += 1 (count becomes 1).
- Then, shift n: n >>= 1 → n = 5 (binary 0101).

**Second check:**
- n & 1 → 0101 & 0001 → 0001, which is 1.
- So, count += 1 (count becomes 2).
- Then, shift n: n >>= 1 → n = 2 (binary 0010).

**Third check:**
- n & 1 → 0010 & 0001 → 0000, which is 0.
- So, count += 0 (count remains 2).
- Then, shift n: n >>= 1 → n = 1 (binary 0001).

**Fourth check:**
- n & 1 → 0001 & 0001 → 0001, which is 1.
- So, count += 1 (count becomes 3).
- Then, shift n: n >>= 1 → n = 0 (binary 0000).

The loop ends because n becomes 0, and the final count is 3, which is the number of 1 bits in 11.
====================================================================================================================*/


class Solution {
public:
    int hammingWeight(int n) {

        // Minimal approach
        int count=0;
        while(n>0)
        {
            count+=(n & 1);
            n>>=1;
        }
        // this is the brute force approach
        // while(n>0){
        //     if(n%2==1){
        //         count++;
        //         n/=2;
        //     }
        //     else{
        //         n/=2;
        //     }
        // }
        return count;
    }
};
