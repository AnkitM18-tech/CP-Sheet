#include<bits/stdc++.h>
using namespace std;

int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
    int n = Student.size();
    int m = Cookie.size();

    int l = 0, r = 0;

    sort(Student.begin(), Student.end());
    sort(Cookie.begin(), Cookie.end());

    while(l < n && r < m) {
        if(Cookie[r] >= Student[l]) {
            l++;
        }
        r++;
    }
    return l;
    // Tc = O(N log N + M log M + M)
}

bool lemonadeChange(vector<int>& bills){
    int five = 0, ten = 0;
    for(int i = 0; i < bills.size(); i++) {
        if(bills[i] == 5) five++;
        else if(bills[i] == 10) {
        if(five) {
            five--;
            ten++;
        }
        else return false;
        } else {
        if(ten && five) {
            ten--;
            five--;
        } else if(five >= 3) {
            five -= 3;
        } else return false;
        }
    }
    return true; // O(N)
}

bool canJump(vector<int>& nums) {
    int maxIndex = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(i > maxIndex) return false;
        maxIndex = max(i + nums[i],maxIndex);
    }
    return true; // O(N)
}


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