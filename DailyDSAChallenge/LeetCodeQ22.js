/**
 * LeetCode Q.22 - "Generate Parentheses"
 * Link: https://leetcode.com/problems/generate-parentheses/description/
 * Twitter Article with detailed explanation: https://x.com/amandeepgini/status/1803160405654569365
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * 
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 * 
 * Constraints:
 * 1 <= n <= 8
 */

/**
 * Brute Force
 * (1) Generate All Possible Sequences
 * (2) Check Each Sequence for Validity
 */

function generateParenthesis(n) {
    let result = [];

    const isValid = (s) => {
        let balance = 0;

        for(let char of s) {
            if(char === '(') {
                balance++
            } else {
                balance--;
            }
            if(balance < 0) return false;
        }
        return balance === 0;
    }

    const generateAll = (current, pos) => {
        if(pos === 2*n) {
            if(isValid(current)) {
                result.push(current);
            }
        } else {
            generateAll(current + '(', pos + 1);
            generateAll(current + ')', pos + 1);
        }
    }

    generateAll('', 0);

    return result;
}

/**
 * Optimized way - Backtracking
 */

function generateParenthesisBacktrack(n) {
    let result = [];
    const backtrack = (current, openCount, closeCount) => {

        if(current.length === 2*n) {
            result.push(current);
            return;
        }

        if(openCount < n) {
            backtrack(current + '(', openCount+1, closeCount);
        }

        if(closeCount < openCount) {
            backtrack(current + ')', openCount, closeCount+1);
        }
    }

    backtrack('', 0 , 0);
    return result;
}