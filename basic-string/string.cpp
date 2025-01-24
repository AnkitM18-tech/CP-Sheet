#include<bits/stdc++.h>
using namespace std;

void bruteForce(vector<char>& s) {
    stack<char> st;
    for(auto ch:s) {
        st.push(ch);
    }
    for(int i=0;i<s.size();i++) {
        s[i] = st.top();
        st.pop();
    }
}
void optimal(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    while(left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

bool palindromeCheck(string& s){
    int left = 0;
    int right = s.length() - 1;
    while(left < right) {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
void reverseString(vector<char>& s){
    // bruteForce(s);
    // optimal(s);
}

string longestCommonPrefix(vector<string>& str){
    if(str.empty()) return "";

    // strings will get sorted lexicographically, 
    // so we can compare the first and last string 
    // for max similarity
    sort(str.begin(),str.end());

    string first = str[0];
    string last = str[str.size()-1];

    int minLength = min(first.size(),last.size());
    string ans = "";

    for(int i=0;i<minLength;i++) {
        // if character doesn't match return
        if(first[i] != last[i]) {
            return ans;
        }
        ans += first[i];
    }
    return ans;
}

bool isomorphicString(string s, string t) {
    int map_s[256] = {0};
    int map_t[256] = {0};

    int n = s.size();

    for(int i=0;i<n;i++) {
        if(map_s[s[i]] != map_t[t[i]]) return false;
        map_s[s[i]] = i+1;
        map_t[t[i]] = i+1;
    }
    return true;
}

bool brute(string& s, string& goal) {
    if (s.length() != goal.length()) return false;

    for (int i = 0; i < s.length(); i++) {
        string rotated = s.substr(i) + s.substr(0, i);
        if (rotated == goal) return true;
    }
    return false;
    /*
    Time Complexity O(N^2) Generate N rotations
    and each comparison takes O(N) time.
    Space Complexity O(N) for the space needed
    to store each rotated string.
    */
}

bool optimal(string& s, string& goal) {
    if(s.length() != goal.length()) return false;
    string newStr = s + s;
    return newStr.find(goal) != string::npos;
    // TC - O(N) - concatenating + O(2N) - finding
}
bool rotateString(string& s, string& goal) { 
	return optimal(s, goal);
}
// O(N * log N + M), where N is the number of strings and 
// M is the maximum length of a string. The sorting operation 
// takes O(N * log N) time, and the 
// comparison of characters in the first and 
// last strings takes O(M) time.
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    return 0;
}