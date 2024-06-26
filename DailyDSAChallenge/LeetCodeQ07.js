/**
 * LeetCode Q.07 - "Reverse the integer"
 * Link: https://leetcode.com/problems/reverse-integer/
 * Twitter Article with detailed explanation: https://x.com/amandeepgini/status/1805945927263203546
 * 
 * Given a signed 32-bit integer x, return x with its digits reversed. 
 * If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 * 
 * Example 1:
 * Input: x = 123
 * Output: 321
 * 
 * Example 2:
 * Input: x = -123
 * Output: -321
 * 
 * Example 3:
 * Input: x = 120
 * Output: 21
 * 
 * Constraints:
 * -2^31 <= x <= 2^31 - 1
 */

// Brute Force
function reverseInteger(x) {
    const reversed = parseInt(Math.abs(x).toString().split('').reverse().join(''));
    if(reversed > 2**31 - 1) return 0;

    return x < 0 ? -reversed:reversed;
}

// Mathematical Approach
function reverseInteger(x) {
    let reversed = 0;
    let digit = 0;
    const isNegative = x < 0;
    x = Math.abs(x);

    while(x > 0) {
        digit = x%10;
        reversed = reversed * 10 + digit;
        x = Math.floor(x / 10);

        if (reversed > 2**31 - 1) return 0;
    }

    return isNegative ? -reversed : reversed;
}

// Optimized Mathematical Approach
function reverseInteger(n) {
    let reversed = 0;
    const INT_MAX = 2**31 - 1;
    const INT_MIN = -(2**31);
  
    while(n !== 0) {
        const digit = n % 10;
        
        if(reversed > INT_MAX || (reversed === INT_MAX && digit > 7)) return 0;
        if(reversed < INT_MIN || (reversed === INT_MIN && digit < -8)) return 0;

        reversed = reversed * 10 + digit;
        n = n > 0 ? Math.floor(n/10) : Math.ceil(n/10);
    }

    return reversed;
}

