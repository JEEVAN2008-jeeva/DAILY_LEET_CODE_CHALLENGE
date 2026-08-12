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