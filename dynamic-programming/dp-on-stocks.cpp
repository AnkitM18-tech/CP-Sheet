#include<bits/stdc++.h>
using namespace std;

class StockBuySell1{
    public:
        int stockBuySell(vector<int> arr, int n){
            int maxProfit = 0;
            int mini = arr[0];
    
            for(int i = 1; i < n; i++) {
                int curProfit = arr[i] - mini;
                maxProfit = max(maxProfit, curProfit);
                mini = min(mini, arr[i]);
            }
    
            return maxProfit;
        }
};    



int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        
    }
    return 0;
}