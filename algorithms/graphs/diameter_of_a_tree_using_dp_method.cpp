#include<bits/stdc++.h>
using namespace std;
 
#define PB push_back

vector<int> g[10];
int h[10];
int n;
 
// finding height of each node.
// Argument p here is the parent of current node
int height(int curr, int p){
    for(auto it : g[curr]){
        if(it == p){
            continue;
        }
        h[curr] = max(h[curr], height(it, curr));
    }
    h[curr] +=  1;
    return h[curr];
}
 
// finding diameter
int diameter(int curr, int p){
    
    int mx1, mx2, mx_subtree;
    mx1 = mx2 = mx_subtree = INT_MIN;
    for(auto it : g[curr]){
        if(it == p){
            continue;
        }
        if(mx1 < h[it]){
            mx2 = mx1;
            mx1 = h[it];
        } else {
            mx2 = h[it];
        }
    }
    for(auto it : g[curr]){
        if(it == p){
            continue;
        }
        mx_subtree = max(mx_subtree, diameter(it, curr));
    }
 
// diameter will be max of diameter in the subtrees or if it passes
// through current node then it will be the sum of maximum heights
// of any two of its children + 1(1 for current node).
 
    return max(mx_subtree, mx1 + mx2 + 1);
}
 
int main(){
    int n = 9;
    memset(h, 0, sizeof h);
    // g.resize(n+1);
    // h.resize(n+1, 0);
    
    g[1].PB(2);
    g[1].PB(3);
    g[1].PB(4);
    g[2].PB(1);
    g[3].PB(1);
    g[4].PB(1);
    g[2].PB(5);
    g[2].PB(6);
    g[5].PB(2);
    g[6].PB(2);
    g[4].PB(7);
    g[7].PB(4);

    g[4].PB(8);
    g[8].PB(9);
    g[8].PB(4);
    g[9].PB(8);
    

// choosing root to be 1.
    height(3, -1);

    for(int i = 1; i <= 9; i++){
        cout << h[i] << " ";
    }
    cout << "\n";

    cout << diameter(3, -1) ;
    return 0;
}

