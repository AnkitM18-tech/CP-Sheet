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

void reverseString(vector<char>& s){
    // bruteForce(s);
    // optimal(s);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    return 0;
}