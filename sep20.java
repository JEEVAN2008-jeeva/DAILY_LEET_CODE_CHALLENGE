class Solution {

    public int reverseDegree(String s) {

        int ans = 0;
        int idx = 1;

        for (char ch : s.toCharArray()) {

            // 123 - ch gives the reverse
            // alphabetical position:
            // a -> 26, b -> 25, ..., z -> 1
            ans += (123 - (int) ch) * idx;

            idx++;
        }

        return ans;
    }
}