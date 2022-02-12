/**
 *  Problem Statement:
 * 
 * Given a non-negative integer represented as a linked list of digits, plus one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list. 
 * 
 * Let's look at cases:
 * Case 1
 * Input: head = [1,2,3]   1 --> 2 --> 3  => 1 --> 2 --> 4
 * Output: [1,2,4]
 * 
 * Case 2
 * Input: head = [1,2,9]   1 --> 2 --> 9  => 1 --> 3 --> 0
 * Output: [1,3,0]
 * 
 * Case 3
 * Input: head = [9,9,9]   9 --> 9 --> 9  => 1 --> 0 --> 0 --> 0
 * Output: [1,0,0,0]
 * 
 Constraints:
    1) The number of nodes in the linked list is in the range [1, 100].
    2) 0 <= Node.val <= 9
    3) The number represented by the linked list does not contain leading zeros except for the zero itself. 
 **/