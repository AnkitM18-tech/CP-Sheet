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