#include <string.h>
#include <stdlib.h>

char* lexGreaterPermutation(char* s, char* target) {
    int n = strlen(s);
    int freq[26] = {0};
    for (int i = 0; i < n; i++) freq[s[i] - 'a']++;

    for (int i = n - 1; i >= 0; i--) {
        int temp[26];
        for (int k = 0; k < 26; k++) temp[k] = freq[k];
        int ok = 1;

        for (int j = 0; j < i; j++) {
            if (temp[target[j] - 'a'] == 0) {
                ok = 0;
                break;
            }
            temp[target[j] - 'a']--;
        }

        if (!ok) continue;

        int chosen = -1;
        for (int c = target[i] - 'a' + 1; c < 26; c++) {
            if (temp[c] > 0) {
                chosen = c;
                break;
            }
        }

        if (chosen == -1) continue;

        temp[chosen]--;
        char* suffix = (char*)malloc((n + 1) * sizeof(char));
        int idx = 0;
        for (int c = 0; c < 26; c++) {
            for (int k = 0; k < temp[c]; k++) {
                suffix[idx++] = 'a' + c;
            }
        }
        suffix[idx] = '\0';

        char* result = (char*)malloc((n + 1) * sizeof(char));
        int pos = 0;
        for (int j = 0; j < i; j++) result[pos++] = target[j];
        result[pos++] = 'a' + chosen;
        for (int j = 0; j < idx; j++) result[pos++] = suffix[j];
        result[pos] = '\0';

        free(suffix);
        return result;
    }

    char* empty = (char*)malloc(sizeof(char));
    empty[0] = '\0';
    return empty;
}