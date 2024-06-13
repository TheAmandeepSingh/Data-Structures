/**
 * LeetCode Q.36 - "Valid Sudoku"
 * Link: https://leetcode.com/problems/valid-sudoku/description/
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 *          (a) Each row must contain the digits 1-9 without repetition.
 *          (b) Each column must contain the digits 1-9 without repetition.
 *          (c) Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * Note: A Sudoku board (partially filled) could be valid but is not necessarily solvable. Only the filled cells need to be validated according to the mentioned rules.
 */

/**
 * Brute Force The simplest way is to check each row, column, and sub-box independently for duplicates. 
 * This would be a brute force approach, as we traverse each row and column three times, 
 * resulting in a time complexity of O(n^2) + O(n^2) + O(n^2) = 3 O(n^2).
 */

function validSudoku(matrix) {
    const isValidBlock = (block) => {
        const seen = new Set();
        for (let char of block) {
            if (char !== '.') {
                if (seen.has(char)) {
                    return false;
                }
                seen.add(char);
            }
        }
        return true;
    };

    // Rows
    for (let row of matrix) {
        if (!isValidBlock) {
            return false;
        }
    }

    // Cols
    for (let col = 0; col < 9; col++) {
        const column = [];
        for (let row = 0; row < 9; row++) {
            column.push(matrix[row][col]);
        }

        if (!isValidBlock(column)) {
            return false;
        }
    }

    // 3x3 Blocks
    for (let row = 0; row < 9; row += 3) {
        for (let col = 0; col < 9; col += 3) {
            const block = [];
            for (let r = row; r < row + 3; r++) {
                for (let c = col; c < col + 3; c++) {
                    block.push(matrix[r][c]);
                }
            }
            if (!isValidBlock(block)) {
                return false;
            }
        }
    }

    return true;
}

/**
 * To optimize, I considered that since we are already traversing each row and column, we might as well utilize that by using additional data structures, 
 * such as sets, for efficient duplicate checks. This reduces redundant operations and improves efficiency. O(n^2).
 */

function isValidSudoku(matrix){
    const rows = new Array(9).fill(null).map(() => new Set());
    const cols = new Array(9).fill(null).map(() => new Set());
    const boxes = new Array(9).fill(null).map(() => new Set());

    for(let row = 0; row < 9; row++) {
        for(let col = 0; col < 9; col++) {
            const val = matrix[row][col];
            if(val === '.') {
                continue;
            }

            const boxIndex = Math.floor(row/3)*3 + Math.floor(col/3);

            if(rows[row].has(val) || cols[col].has(col) || boxes[boxIndex].has(val)) {
                return false;
            }

            rows[row].add(val);
            cols[col].add(val);
            boxes[boxIndex].add(val);
        }
    }
    return true;
}

/**
 * Initially, I didn't think of this approach. However, while researching, I found that bit manipulation offers more space efficiency i.e. 
 * O(n) speed with same time complexity of O(n). This technique leverages bitwise operations for efficient duplicate checks.
 * Bit manipulation is always fun—let's dive in!
 */

function isValidSudokuUsingBitWise(matrix) {
    const rows = new Array(9).fill(0);
    const cols = new Array(9).fill(0);
    const boxes = new Array(9).fill(0);

    for(let row = 0; row < 9; row++) {
        for(let col = 0; col < 9; col++) {
            const val = matrix[row][col];
            if(val === '.') continue;

            const bitMask = 1 << (parseInt(val) - 1);
            const boxIndex = Math.floor(row/3)*3 + Math.floor(col/3);

            // Check if the bitmask already exists in the current row, column or sub-box
            if ((rows[row] & bitMask) !== 0 || (cols[col] & bitMask) !== 0 || (boxes[boxIndex] & bitMask) !== 0) {
                return false;
            }
        
            // Set the bitmask in the current row, column and sub-box
            rows[row]       |= bitMask;
            cols[col]       |= bitMask;
            boxes[boxIndex] |= bitMask;
        }
    }
    return true;
}