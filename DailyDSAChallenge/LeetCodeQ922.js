/**
 * LeetCode Q.992 - "Subarrays with K Different Integers"
 * Link: https://leetcode.com/problems/subarrays-with-k-different-integers/description/
 * Twitter Article with detailed explanation: https://x.com/amandeepgini/status/1807051612457750854
 * 
 * 992. Subarrays with K Different Integers
 * ----------------------------------------
 * Given an integer array nums and an integer k, return the number of good subarrays of nums.
 * A good array is an array where the number of different integers in that array is exactly k.
 *          For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
 * A subarray is a contiguous part of an array.
 * 
 * Example 1:
 * Input: nums = [1,2,1,2,3], k = 2
 * Output: 7
 * Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
 * 
 * Example 2:
 * Input: nums = [1,2,1,3,4], k = 3
 * Output: 3
 * Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 * 
 * Constraints:
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i], k <= nums.length
 */

// Brute Force Solution
function subarraysWithKDistinct(nums, k) {
    let count = 0;

    for(let start = 0; start < nums.length; start++) {
        const set = new Set();
        for(let end = start; end < nums.length; end++) {
            set.add(nums[end]);

            if(set.size() === k) {
                count++;
            }
           
            if(set.size() > k) {
                break;
            }
        } 
    }

    return count;
}

// Optimized: Sliding Window approach
function subarraysWithKDistinct(nums, k) {
    const atMostK = (k) => {
        let result = 0;
        let left = 0;
        const counts = new Map();

        for(let right = 0; right < nums.length; nums++) {
            counts.set(nums[right], (counts.get(nums[right]) || 0) + 1);

            // shrink the window
            while(counts.size > k) {
                counts.set(nums[left], counts.get(nums[left]) - 1);
                if(counts.get(nums[left]) === 0) {
                    counts.delete[nums[left]];
                }
                left++;
            }

            result += right-left+1;
        }
        return result;
    }

    return atMostK(k) - atMostK(k-1);
}



}