/**
 * LeetCode Q.17 - "Letter Combinations of a Phone Number"
 * Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 * Twitter Article with detailed explanation: https://x.com/compose/articles/edit/1803839835230105600
 * Problem Statement
 * Given a string containing digits from 2-9 inclusive, you need to return all possible letter combinations that the number could represent. The mapping of digits to letters is similar to those on a telephone keypad. The task is to generate all combinations of these letters for the provided digits.
 * Mapping of Digits to Letters
 * Here's the mapping similar to a telephone keypad:
 *  •	2: "abc"
 *  •	3: "def"
 *  •	4: "ghi"
 *  •	5: "jkl"
 *  •	6: "mno"
 *  •	7: "pqrs"
 *  •	8: "tuv"
 *  •	9: "wxyz"
 * Note:
 *  •	Digits 1 does not map to any letters.
 * 	•	The input string will be up to a length of 4.
 */

function letterCombinations(digits) {
    // let's take edge case
    if(!digits.length) return [];
    
    const phoneMap = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    };

    let combinations = [];

    const backtrack = (index, currentCombination) => {

        if(currentCombination.length === digits.length){
            combinations.push(currentCombination);
            return;
        }

        const letters = phoneMap[digits[index]];
        for(let i = 0; i < letters.length; i++) {
            backtrack(index + 1, currentCombination + letters[i]);
        }
    }

    backtrack(0, '');
    return combinations;
}

// DFS with Iterative Approach
function letterCombinationsDFS(digits) {
     // let's take edge case
     if(!digits.length) return [];
    
     const phoneMap = {
         '2': 'abc',
         '3': 'def',
         '4': 'ghi',
         '5': 'jkl',
         '6': 'mno',
         '7': 'pqrs',
         '8': 'tuv',
         '9': 'wxyz'
     };

     let combinations = [''];

     for(let i = 0; i < digits.length; i++) {
        const letters = phoneMap[digits[i]];
        let newCombinations = [];

        for(const combination of combinations) {
            for(const letter of letters) {
                newCombinations.push(combination + letter);
            }
        }
        combinations = newCombinations;
     }

     return combinations;
}