int largestInteger(int* nums, int n, int k) {
    int freq[51] = {0};
    for (int i = 0; i < n; i++)
            freq[nums[i]]++;

    if (k == n) {
        for (int i = 50; i >= 0; i--)
            if (freq[i] != 0)
                return i;
        return -1;
    }
    if (k == 1) {
        for (int i = 50; i >= 0; i--)
            if (freq[i] == 1)
                return i;
        return -1;
    }

    int a = nums[0], b = nums[n - 1];
    int ans = -1;
    if (freq[a] == 1)
        ans = (ans > a)? ans : a;
    if (freq[b] == 1)
        ans = (ans> b)? ans : b;
    return ans;
}