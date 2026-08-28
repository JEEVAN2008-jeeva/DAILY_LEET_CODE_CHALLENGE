char* lexPalindromicPermutation(char* s, char* target) {
    int n = strlen(s);

    int freq[26] = {0};

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    char middle = '\0';

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            if (middle != '\0') {
                char* empty = malloc(1);
                empty[0] = '\0';
                return empty;
            }

            middle = 'a' + i;
        }

        freq[i] /= 2;
    }

    int halfLen = n / 2;

    char* half = malloc(halfLen + 1);
    int halfSize = 0;

    int matched = 0;

    while (matched < halfLen) {
        int c = target[matched] - 'a';

        if (freq[c] == 0) {
            break;
        }

        freq[c]--;
        half[halfSize++] = 'a' + c;
        matched++;
    }

    int pos = matched;

    while (pos >= 0) {
        if (pos < halfLen) {
            int start = target[pos] - 'a' + 1;

            for (int c = start; c < 26; c++) {
                if (freq[c] == 0) {
                    continue;
                }

                freq[c]--;

                char* left = malloc(halfLen + 1);
                int index = 0;

                for (int j = 0; j < pos; j++) {
                    left[index++] = half[j];
                }

                left[index++] = 'a' + c;

                for (int j = 0; j < 26; j++) {
                    for (int x = 0; x < freq[j]; x++) {
                        left[index++] = 'a' + j;
                    }
                }

                left[index] = '\0';

                char* result = malloc(n + 1);
                int r = 0;

                for (int j = 0; j < halfLen; j++) {
                    result[r++] = left[j];
                }

                if (middle != '\0') {
                    result[r++] = middle;
                }

                for (int j = halfLen - 1; j >= 0; j--) {
                    result[r++] = left[j];
                }

                result[r] = '\0';

                if (strcmp(result, target) > 0) {
                    free(left);
                    free(half);
                    return result;
                }

                free(left);
                free(result);

                freq[c]++;
            }
        }

        if (pos == halfLen) {
            char* result = malloc(n + 1);
            int r = 0;

            for (int j = 0; j < halfLen; j++) {
                result[r++] = half[j];
            }

            if (middle != '\0') {
                result[r++] = middle;
            }

            for (int j = halfLen - 1; j >= 0; j--) {
                result[r++] = half[j];
            }

            result[r] = '\0';

            if (strcmp(result, target) > 0) {
                free(half);
                return result;
            }

            free(result);
        }

        pos--;

        if (pos >= 0) {
            int c = half[pos] - 'a';
            freq[c]++;
            halfSize--;
        }
    }

    free(half);

    char* empty = malloc(1);
    empty[0] = '\0';

    return empty;
}