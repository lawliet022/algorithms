#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
long long int cost[N], solution[N];
        
int main() {
	freopen("in3.txt","r",stdin);
	freopen("out2.txt","w",stdout);
	
    int t;
    cin>>t;
    for(int tc=0; tc<t; tc++){
        long long int n, gallons_capacity;
        cin>>n>>gallons_capacity;
        for(int i=0; i<n; i++){
            cin>>cost[i];
        }
        if(n <= gallons_capacity + 1){
            cout<<"Case #"<<tc+1<<": "<< 0 <<"\n";
            continue;
		}
        deque<pair<long long,long long>> minimum_cost; 
        int i = 0;
        for(i=0; i<=gallons_capacity; i++){
            solution[i] = 0;
            if(cost[i] != 0){
                while(!minimum_cost.empty() && cost[i] <= minimum_cost.back().second)
                    minimum_cost.pop_back();
                minimum_cost.push_back({i,cost[i]});
            }
        }
        int flag = 1;
        for(; i<n; i++){
			while(!minimum_cost.empty() && minimum_cost.front().first < i-gallons_capacity)
                    minimum_cost.pop_front();
			if(minimum_cost.size() == 0){
				flag = 0;
				break;
			}
            long long int curr_min = minimum_cost.front().second;
            solution[i] = curr_min;
            if(cost[i] != 0){
				long long int val = cost[i] + curr_min;
                while(!minimum_cost.empty() && val <= minimum_cost.back().second)
                    minimum_cost.pop_back();
                minimum_cost.push_back({i,val});
            }
        }
        if(flag == 0){
			cout<<"Case #"<<tc+1<<": "<<-1<<"\n";
		}
		else{
			cout<<"Case #"<<tc+1<<": "<<solution[n-1]<<"\n";
		}
    }
}
