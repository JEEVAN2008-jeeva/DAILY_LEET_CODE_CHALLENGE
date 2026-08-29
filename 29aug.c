#pragma GCC optimize("O3, unroll-loops")
#define N 100000
typedef long long ll;
ll nIdx[N]={0};
int seq[N], values[N];

int cmpll(const void * a, const void * b) {
    ll diff=*(ll*)a-*(ll*)b;
    return diff==0?0:(diff>0?1:-1);
}

int cmp(const void * a, const void * b) {
    return (*(int*)a-*(int*)b);
}

static int* lexicographicallySmallestArray(int* nums, int n, int limit, int* returnSize) {
    *returnSize = n;
    for (int i=0; i<n; i++)
        nIdx[i]=((ll)nums[i]<<32)+i;
    
    qsort(nIdx, n, sizeof(ll), cmpll);
    
    for (int s=0, e=0; s<n; s=e+1) {
        int prev=nIdx[s]>>32; 
        int x;
        int i=s+1;
        while (i<n && (x=(nIdx[i]>>32))-prev<=limit) {
            prev=x;
            i++;
        }
        e=i-1;
        int sn=e-s+1;
        for (int k=s, j = 0; k<=e; k++) {
            int x=nIdx[k]>>32, idx=nIdx[k] & UINT_MAX;
            values[j]=x;
            seq[j++]=idx;
        }
        qsort(seq, sn, sizeof(int), cmp);
        for (int k=0; k<sn; k++) {
            nums[seq[k]]=values[k];
        }
    }
    return nums;
}