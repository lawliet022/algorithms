int Solution::maxSubArray(const vector<int> &A) {
    int ans = A[0];
    int n = A.size(), temp = A[0];
    for(int i = 1; i < n; i++){
        temp = max(A[i],temp+A[i]);
        ans = max(ans,temp);
    }
    return ans;
}
