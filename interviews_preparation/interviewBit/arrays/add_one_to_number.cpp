vector<int> Solution::plusOne(vector<int> &A) {
    reverse(A.begin(),A.end());
    int n = A.size();
    if(A[0] != 9){
        A[0]++;
        int cnt = 0;
        for(int i = n-1; i >= 0; i--){
            if(A[i] == 0){
                cnt++;
            }
            else
                break;
        }
        while(cnt--)
            A.pop_back();
        reverse(A.begin(),A.end());
        return A;
    }
    A[0] = 0;
    A.push_back(0);
    for(int i = 1; i < (int)A.size(); i++){
        if(A[i] != 9){
            A[i]++;
            break;
        }
        else
            A[i] = 0;
    }
    int cnt = 0;
    for(int i = (int)A.size()-1; i >= 0; i--){
        if(A[i] == 0){
            cnt++;
        }
        else
            break;
    }
    while(cnt--)
        A.pop_back();
    reverse(A.begin(),A.end());
    return A;
}
