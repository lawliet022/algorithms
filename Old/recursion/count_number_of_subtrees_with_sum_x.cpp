#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]" << " ";
	err(++it, args...);
}


//https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1

int countSubtreesWithSumX(Node* root, int x)
{
	if (!root)return 0;
	if(root->left == NULL && root->right == NULL){
	    if(root->data == x){
	        return 1;
	    }
	    else
	        return 0;
	}
	else{
	    int ans = 0;
	    int val = 0;
	    if(root->left != NULL){
	        ans += countSubtreesWithSumX(root->left,x);
	        val += root->left->data;
	    }
	    if(root->right != NULL){
	        ans += countSubtreesWithSumX(root->right,x);
	        val += root->right->data;
	    }
	    root->data += val;
	    return (ans+(root->data == x));
	}
}


int32_t main(){
	

	return 0;
}

