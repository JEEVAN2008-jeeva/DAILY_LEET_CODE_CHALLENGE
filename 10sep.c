int ans;
int* dfs(struct TreeNode* node) {
    static int result[2];
    if (!node) { result[0] = 0; result[1] = 0; return result; }
    int* left = dfs(node->left);
    int ls = left[0], lc = left[1];
    int* right = dfs(node->right);
    int rs = right[0], rc = right[1];
    int sum = ls + rs + node->val;
    int cnt = lc + rc + 1;
    if (sum / cnt == node->val) ans++;
    static int res[2];
    res[0] = sum; res[1] = cnt;
    return res;
}
int averageOfSubtree(struct TreeNode* root) {
    ans = 0;
    dfs(root);
    return ans;
}