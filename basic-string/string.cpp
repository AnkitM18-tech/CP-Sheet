#include<bits/stdc++.h>
using namespace std;

bool bruteAnagram(string& s, string& t) {
    if(s.length() != t.length()) return false;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return s == t;
    // TC - O(N log N)
}
bool optimalAnagram(string& s, string& t) {
    if(s.length() != t.length()) return false;
    vector<int> count(26,0);

    // occurence of each character in first string
    for(char ch: s) count[ch - 'a']++;
    // decrement count from second string
    for(char ch: t) count[ch - 'a']--;

    for(int i: count) {
        // check if count is zero or not - if 
        // same number of characters present then the count
        // will get cancelled out
        if(i != 0) return false;
    }
    return true;
    // O(N), where N is the length of the string - TC
}
void bruteForceReverse(vector<char>& s) {
    stack<char> st;
    for(auto ch:s) {
        st.push(ch);
    }
    for(int i=0;i<s.size();i++) {
        s[i] = st.top();
        st.pop();
    }
}
void optimalReverse(vector<char>& s) {
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

void reverseString(vector<char>& s){
    // bruteForce(s);
    // optimal(s);
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
    // O(N * log N + M), where N is the number of strings and 
    // M is the maximum length of a string. The sorting operation 
    // takes O(N * log N) time, and the 
    // comparison of characters in the first and 
    // last strings takes O(M) time.
}

string largeOddNum(string& s){
    int index = -1;
    // find odd digit from the last
    for(int i=s.length()-1; i>=0;i--){
        if((s[i] - '0') % 2 == 1) {
            index = i;
            break;
        }
    }

    // leading zeros elimination
    int i = 0;
    while(i<=index && s[i] == '0') i++;

    return s.substr(i,index - i+1);
    // TC - O(N)
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

bool bruteRotate(string& s, string& goal) {
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

bool optimalRotate(string& s, string& goal) {
    if(s.length() != goal.length()) return false;
    string newStr = s + s;
    return newStr.find(goal) != string::npos;
    // TC - O(N) - concatenating + O(2N) - finding
}
bool rotateString(string& s, string& goal) { 
	return optimalRotate(s, goal);
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    return 0;
}