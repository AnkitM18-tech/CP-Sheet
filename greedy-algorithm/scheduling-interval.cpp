#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int>& bt) {
    sort(bt.begin(), bt.end());

    long long waitTime = 0;
    long long total = 0;

    int n = bt.size();

    for(int i = 0; i<n; i++) {
        waitTime += total;
        total += bt[i];
    }

    return waitTime/n; // O(N log N + N)
}

vector<int> JobScheduling(vector<vector<int>>& Jobs) {
    // sort jobs based on profit in desc order
    sort(Jobs.begin(), Jobs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    });

    int n = Jobs.size();
    int maxDeadline = -1;
    for(int i = 0; i<n; i++) maxDeadline = max(maxDeadline, Jobs[i][1]);
    vector<int> hash(maxDeadline,-1);

    int cnt = 0, totalProfit = 0;

    for(int i = 0; i<n; i++) {
        for(int j = Jobs[i][1] - 1; j>=0; j--) {
        if(hash[j] == -1) {
            cnt++;
            hash[j] = Jobs[i][0];
            totalProfit += Jobs[i][2];
            break;
        }
        }
    }

    return {cnt,totalProfit}; // O(N log N + N * maxdeadline) - TC, SC - O(maxDeadline)
}

static bool comparator(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second < b.second;
}
int maxMeetings(vector<int>& start, vector<int>& end){
    int n = start.size();

    vector<pair<int,int>> meetings;

    for(int i = 0; i<n; i++) {
        meetings.push_back({start[i],end[i]});
    }

    sort(meetings.begin(),meetings.end(),comparator);

    int limit = meetings[0].second;

    int count = 1;

    for(int i = 1; i<n; i++) {
        if(meetings[i].first > limit) {
        limit = meetings[i].second;
        count++;
        }
    }

    return count; // O(2N + N log N) = TC && SC = O(N)
}

static bool comp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
    sort(Intervals.begin(), Intervals.end(),comp);

    int n = Intervals.size();
    int count = 1;
    int lastEndTime = Intervals[0][1];

    for(int i = 1; i<n; i++) {
        if(Intervals[i][0] >= lastEndTime) {
        count++;
        lastEndTime = Intervals[i][1];
        }
    }
    return n - count; // O(N log N + N)
}

vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval){
    vector<vector<int>> ans;
    int n = Intervals.size();
    int i = 0;
    // Left Part
    while( i < n && Intervals[i][1] < newInterval[0]) {
        ans.push_back(Intervals[i]);
        i++;
    }

    // Overlapping Part
    while( i < n && Intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0],Intervals[i][0]);
        newInterval[1] = max(newInterval[1], Intervals[i][1]);
        i++;
    }

    ans.push_back(newInterval);

    // Right Part
    while(i < n) {
        ans.push_back(Intervals[i]);
        i++;
    }

    return ans; // O(N)
}

int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    /*
    // Brute Force
    int n = Arrival.size();

    int ans = 1;

    for(int i = 0; i<n; i++) {
        int cnt = 1;

        for(int j = 0; j<n; j++) {
        if(i != j) {
            if(Arrival[i] >= Arrival[j] && Departure[j] >= Arrival[i]) {
            cnt++;
            }
            ans = max(ans,cnt);
        }
        }
    }

    return ans; // O(N^2)
    */
    // Optimal
    int n = Arrival.size();
    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());

    int ans = 1;
    int cnt = 1;
    int i = 1, j = 0;

    while(i < n && j < n) {
    if(Arrival[i] <= Departure[j]) {
        cnt++;
        i++;
    } else {
        cnt--;
        j++;
    }

    ans = max(cnt,ans);
    }
    return ans; // O(2 * N log N) + O(2 * N)
}

bool checkValid(string &s,int ind, int cnt) {
    if(cnt < 0) return false;
    if(ind == s.size()) return cnt == 0;
    bool ans = false;

    if(s[ind] == '(') ans = checkValid(s,ind+1,cnt+1);
    else if(s[ind] == ')') ans = checkValid(s,ind+1,cnt-1);
    else {
        for(int i = -1; i<=1; i++) {
            ans = ans || checkValid(s,ind+1,cnt+i);
        }
    }
    return ans;
}

bool isValid(string s) {
    /*
    // Brute - O(3^N) - TC & SC - O(N)
    int n = s.size();
    return checkValid(s,0,0);
    */
    // Optimal
    int minOpen = 0, maxOpen = 0;
    for(char ch : s) {
        if(ch == '(') {
            minOpen++;
            maxOpen++;
        } else if(ch == ')') {
            minOpen--;
            maxOpen--;
        } else if(ch == '*') {
            minOpen--;
            maxOpen++;
        }
        if(maxOpen < 0) return false;
        if(minOpen < 0) minOpen = 0;
    }
    return minOpen == 0; // TC - O(N)
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