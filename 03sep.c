#include <stdbool.h>
#include <limits.h>

bool uniformArray(int* nums, int numsSize) {
    bool allOdd = true;
    bool allEven = true;

    int minOdd = INT_MAX;
    int minEven = INT_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            allOdd = false;
            if (nums[i] < minEven)
                minEven = nums[i];
        } else {
            allEven = false;
            if (nums[i] < minOdd)
                minOdd = nums[i];
        }
    }

    return allOdd || allEven || minEven > minOdd;
}