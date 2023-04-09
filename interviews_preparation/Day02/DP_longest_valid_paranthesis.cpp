#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;


int findMaxLen(string str) 
{ 
    int n = str.length(); 
  
    // Create a stack and push -1 as initial index to it. 
    stack<int> stk; 
    stk.push(-1); 
  
    // Initialize result 
    int result = 0; 
  
    // Traverse all characters of given string 
    for (int i=0; i<n; i++) 
    { 
        // If opening bracket, push index of it 
        if (str[i] == '(') 
          stk.push(i); 
  
        else // If closing bracket, i.e.,str[i] = ')' 
        { 
            // Pop the previous opening bracket's index 
            stk.pop(); 
  
            // Check if this length formed with base of 
            // current valid substring is more than max  
            // so far 
            if (!stk.empty()) 
                result = max(result, i - stk.top()); 
  
            // If stack is empty. push current index as  
            // base for next valid substring (if any) 
            else stk.push(i); 
        } 
    } 
  
    return result; 
} 






int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    //cin >> t;
    t = 1000;
    while(t--){
        string s = "";
        //cin >> s;
        int n = rand()%20 + 1;
        for(int i = 0; i < n; i++){
			int c = rand() % 2;
			if(c)
				s += '(';
			else
				s += ')';
		}
        int a = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                a++;
            else{
                if(a){
                    ans += 2;
                    a--;
                }
            }
        }
        //cout << ans << endl;
        int gfg = findMaxLen(s);
        
        if(ans != gfg){
			cout<<"Failed\n";
			cout << ans << " " << gfg << " " << s << endl;
			return 0;
		}
		else{
			cout << "Passed\n";
		}
    }


	return 0;
}
