int Solution::longestSubsequenceLength(const vector<int> &A) {
    if(A.size() == 0)
        return 0;
    int n = A.size();
    int a[n+1], b[n+1];
    a[0] = 1;
    for(int i = 1; i < n; i++){
        a[i] = 1;
        for(int j = i-1; j >= 0; j--){
            if(A[i] > A[j])
                a[i] = max(a[i],a[j]+1);
        }
    }
    b[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        b[i] = 1;
        for(int j = i+1; j < n; j++)
            if(A[i] > A[j])
                b[i] = max(b[i],b[j]+1);
    }
    int ans = 1;
    for(int i = 0; i < n; i++){
        ans = max(ans,a[i]+b[i]-1);
    }
    return ans;
}
