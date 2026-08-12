// WELCOME TO THE LEETCODE SERIES.

//THIS IS TODAYS QUESTION (12-08-2026)

//https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/


/* You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 */

int maxSubarrayLength(int* nums, int numsSize, int k) {
    int freq[100001] = {0};
    int left = 0;
    int answer = 0;

    for(int right = 0; right < numsSize; right++) {
        freq[nums[right]]++;

        while (freq[nums[right]] > k){
            freq[nums[left]]--;
            left++;
        }
        int length = right - left + 1;
        if (length > answer) {
            answer = length;
        }
    }
    return answer;
}