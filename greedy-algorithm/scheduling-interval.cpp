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