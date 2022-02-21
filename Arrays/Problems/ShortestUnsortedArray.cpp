/**
 * Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray
 * in ascending order, then the whole array will be sorted in ascending order.
 * Return the shortest such subarray and output its length.
        Example 1:
        Input: nums = [2,6,4,8,10,9,15]
        Output: 5
        Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

        Example 2:
        Input: nums = [1,2,3,4]
        Output: 0

        Example 3:
        Input: nums = [1]
        Output: 0
                                                OR

 * Given an array of integers out of order, determine the bounds of the smallest window that must be sorted
 * in order for the entire array to be sorted. For example, given [3, 7, 5, 6, 9], you should return (1, 3).
 **/
#include <iostream>
#include <vector>
using namespace std;

int leftBound(0), rightBound(0);

int findUnsortedSubarray(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;

    int i(1), j(nums.size() - 2);
    int minimum = INT_MAX;
    int maximum = INT_MIN;

    while (i < nums.size() && j >= 0)
    {
        if (nums[i] < nums[i - 1])
        {
            minimum = min(minimum, nums[i]);
        }

        if (nums[j] > nums[j + 1])
        {
            maximum = max(maximum, nums[j]);
        }
        ++i;
        --j;
    }

    int l, r;
    for (l = 0; l < nums.size(); l++)
    {
        if (minimum < nums[l])
            break;
    }
    for (r = nums.size() - 1; r >= 0; r--)
    {
        if (maximum > nums[r])
            break;
    }
    leftBound = l;
    rightBound = r;

    return r - l < 0 ? 0 : r - l + 1;
}

int main()
{
    vector<int> nums{2, 6, 4, 8, 10, 9, 15};
    cout << "Shortest Unsorted Continuous Array length: " << findUnsortedSubarray(nums) << endl;
    cout << "Bounds of smallest window needs to be sorted: (" << leftBound << "," << rightBound << ")" << endl;
}