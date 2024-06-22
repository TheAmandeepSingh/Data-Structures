/**
 * LeetCode Q.03 - "Longest Substring Without Repeating Characters"
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * Twitter Article with detailed explanation: https://x.com/amandeepgini/status/1804594702756577370
 * 
 * Problem Statement: Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Example 1:
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * Example 2:
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * Example 3:
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * 
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 * Constraints:
 * (a) 0 <= s.length <= 5 * 104
 * (b) s consists of English letters, digits, symbols and spaces.
 */

// Brute Force

function lengthOfLongestSubstring(s) {
    let maxLength = 0;

    for(let i =0; i < s.length; i++ ){
        let seen = new Set();
        for(let j=i; j < s.length; j++ ) {
            if(seen.has(s[j])){
                break;
            } else {
                seen.add(s[j]);
            }
        }
        maxLength = Math.max(seen.size, maxLength);
    }

    return maxLength;
}

// Using sliding window
function lengthOfLongestSubstring(s) {
    let start = 0, end = 0, maxLength = 0;
    let charSet = new Set();

    while(end < s.length) {
        if(!charSet.has(s[end])) {
            charSet.add(s[end]);
            end++;
            maxLength = Math.max(maxLength, end-start);
        } else {
            charSet.delete(s[end]);
            start++;
        }
    }

    return maxLength;
}

// More optimized
function lengthOfLongestSubstring(s) {
    let charMap = new Map();
    let left = 0;
    let maxLength = 0;

    for(let right = 0; right < s.length; right++) {
        if(charMap.has(right)) {
            left = Math.max(charMap.get(s[right]) + 1, left);
        }

        charMap.set(s[right], right);
        maxLength = Math.max(maxLength, right-left + 1);
    }

    return maxLength;
}
