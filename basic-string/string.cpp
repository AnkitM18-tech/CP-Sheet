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