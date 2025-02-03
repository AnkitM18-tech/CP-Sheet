#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    /*
    // Brute
    vector<int> temp;
    for(int i=0;i<n;i++) {
        if(nums[i] != 0) {
            temp.push_back(nums[i]);
        }
    }

    int nz = temp.size();

    for(int i=0;i<nz;i++){
        nums[i] = temp[i];
    }
    for(int i=nz;i<n;i++) {
        nums[i] = 0;
    }
    */
    // Optimal
    int j = -1;
    for(int i=0;i<n;i++) {
        if(nums[i] == 0) {
            j = i;
            break;
        }
    }
    
    if(j == -1) return;

    for(int i=j+1;i<n;i++) {
        if(nums[i] != 0) {
            swap(nums[i],nums[j]);
            j++;
        }
    }
}

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;
    int n = nums.size();
    /*
    // Brute
    set<int> temp;
    for(int num:nums) {
        temp.insert(num);
    }
    int k = temp.size();

    int j = 0;
    for(int num:temp) {
        nums[j] = num;
        j++;
    }
    return k;
    // TC - O(N * log N) for set + O(N) traverse array
    */
    // Optimal
    int i = 0;

    for(int j=1;j<n;j++) {
        if(nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    /*
    // Brute
    for(int i=0;i<=n;i++) {
        int flag = 0;
        for(int j=0;j<=n;j++) {
            if(nums[j] == i) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) return i;
    }
    return -1; // O(N^2)
    
    // Better
    int freq[n+1] = {0};
    for(int num:nums) {
        freq[num]++;
    }
    for(int i=0;i<=n;i++) {
        if(freq[i] == 0) return i;
    }
    return -1; // TC - O(2N) , SC - O(N+1)
    
    // Optimal
    int sumOfN = (n * (n+1)) / 2;
    int sumOfArray = 0;
    for(int num : nums) {
        sumOfArray += num;
    }
    return sumOfN - sumOfArray; // TC - O(N)
    */
    // Optimal 2
    int xor1=0,xor2=0;
    for(int i=0;i<n;i++) {
        xor1 = xor1 ^ (i+1); // XOR - 1..n
        xor2 = xor2 ^ nums[i]; // XOR of array elements
    }
    return (xor1 ^ xor2);
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