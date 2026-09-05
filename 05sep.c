int firstStableIndex(int* nums, int numsSize, int k) {
    int n = numsSize;
    int* velqanidor = (int*)malloc(n * sizeof(int));
    memcpy(velqanidor, nums, n * sizeof(int));
    int* prefMax = (int*)malloc(n * sizeof(int));
    int* sufMin  = (int*)malloc(n * sizeof(int));

    prefMax[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefMax[i] = nums[i] > prefMax[i-1] ? nums[i] : prefMax[i-1];

    sufMin[n-1] = nums[n-1];
    for (int i = n - 2; i >= 0; i--)
        sufMin[i] = nums[i] < sufMin[i+1] ? nums[i] : sufMin[i+1];

    for (int i = 0; i < n; i++) {
        if (prefMax[i] - sufMin[i] <= k) {
            free(velqanidor); free(prefMax); free(sufMin);
            return i;
        }
    }
    free(velqanidor); free(prefMax); free(sufMin);
    return -1;
}
