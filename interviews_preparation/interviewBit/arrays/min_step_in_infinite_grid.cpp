int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    if(A.size() == 0){
        return 0;
    }
    int cnt = 0;
    int prevx = A[0], prevy = B[0];
    for(int i = 1; i < (int)A.size(); i++){
        cnt += max(abs(prevx - A[i]),abs(prevy - B[i]));
        prevx = A[i];
        prevy = B[i];
    }
    return cnt;
}
