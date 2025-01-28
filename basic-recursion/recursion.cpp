#include<bits/stdc++.h>
using namespace std;

int NnumbersSum(int N){
    if(N == 0) return 0;
    else return N + NnumbersSum(N-1);
}

long long int factorial(int n){
    if(n <= 1) return 1;
    else return n * factorial(n-1);
}

int sum(vector<int>& nums, int left) {
    if(left >= nums.size()) {
        return 0;
    }
    return nums[left] + sum(nums,left+1);
}

int arraySum(vector<int>& nums){
    return sum(nums,0);
}

	
vector<char> reverseString(vector<char>& s){
    int left = 0;
    int right = s.size() - 1;
    reverse(s,left,right);
    return s;
}

void reverse(vector<char>& s,int left,int right) {
    if(left >= right) return;
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    reverse(s,left+1,right-1);
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    return 0;
}