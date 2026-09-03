int maximumLengthSubstring(char* s) {
    int count[26] = {0};
    int left = 0;
    int maxLen = 0;

    for(int right = 0; s[right] != '\0'; right++) {
        count[s[right] - 'a']++;
        while (count[s[right] - 'a'] > 2) {
            count[s[left] - 'a']--;
            left++;
        }
        int len = right - left + 1;

        if(len > maxLen) {
            maxLen = len;
        }
    }
    return maxLen;    
}