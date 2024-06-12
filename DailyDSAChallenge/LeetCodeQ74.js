/**
 * LeetCode Q.74 - "Search a 2D Matrix"
 * Link: https://leetcode.com/problems/search-a-2d-matrix/description/
 * The problem asks for a solution with O(log(m*n)) time complexity, hinting at binary search.
 */

function searchMatrix(matrix, target) {
    const m = matrix.length; // rows
    const n = matrix[0].length; // cols

    let left = 0, right = (m*n) - 1;
    while(left <= right) {
        const mid = Math.floor((left + right) / 2);
        const midVal = matrix[Math.floor(mid/n)][mid%n];
        
        if(midVal === target) return true;

        if(midVal > target) {
            right = mid - 1
        } else {
            left = mid + 1;
        }
    }
    return false
}