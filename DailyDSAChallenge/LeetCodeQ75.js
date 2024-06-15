/**
 * LeetCode Q.75 - "Sort Colors"
 * Link: https://leetcode.com/problems/sort-colors/description/
 * Twitter Article Link: 
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
 * with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * You must solve this problem without using the library's sort function.
 */

/**
 * Simple Solution: Since we know there are only three types of colors, 
 * we can leverage this information to count the occurrences of each color using three counters.
 * By counting each number in one go and then recreating the array based on these counts,
 * we can solve this problem in O(n) time with two passes over the array.
 */
function sortColors(nums) {
    let count0 = 0,
        count1 = 0,
        count2 = 0;

    for(let val of nums) {
        if(val === 0) count0++;
        else if(val === 1) count1++;
        else count2++;
    }

    for(let i = 0; i < nums.length; i++){
      if(i < count0) nums[i] = 0;
      else if(i < count0 + count1) nums[i] = 1;
      else nums[i] = 2;
    }
}

/**
 * Efficient Approach: Given the constraint to sort the array in-place,
 * we can use the Dutch National Flag algorithm. This approach utilizes three pointers to partition the array
 * into regions for 0s, 1s, and 2s. By carefully managing these pointers and swapping elements as needed,
 * we can achieve the desired order in a single pass with O(n) time complexity and O(1) space complexity.
 */

function sortColorsUsingTwoPointers(nums) {
    let left = 0, mid = 0, high = nums.length - 1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            [nums[left], nums[mid]] = [nums[mid], nums[left]]; //using destructuring assignment to swap elements
            left++;
            mid++;
        } else if(nums[mid] == 1){
            mid++;
        } else {
            [nums[high], nums[mid]] = [nums[mid], nums[high]];
            high--;
        }
    }
}

