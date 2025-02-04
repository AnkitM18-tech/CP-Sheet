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

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    /*
    // Brute
    set<int> s;
    vector<int> unionArr;
    for(int num:nums1) {
        s.insert(num);
    }
    for(int num:nums2) {
        s.insert(num);
    }
    for(int num:s) {
        unionArr.push_back(num);
    }
    return unionArr;
    // O( (M+N)log(M+N) ), at max set can store M+N elements 
    // {when there are no common elements and elements in nums1 , 
    // nums2 are distntict}. 
    // So Inserting M+N th element takes log(M+N) time.
    */
    // Optimal
    vector<int> Union;
    int i = 0, j = 0;
    int n = nums1.size();
    int m = nums2.size();

    while(i < n && j < m) {
        if(nums1[i] <= nums2[j]) {
            if(Union.size() == 0 || Union.back() != nums1[i]) {
                Union.push_back(nums1[i]);
            }
            i++;
        } else {
            if(Union.size() == 0 || Union.back() != nums2[j]) {
                Union.push_back(nums2[j]);
            }
            j++;
        }
    }

    while(i < n) {
        if(Union.back() != nums1[i]) {
            Union.push_back(nums1[i]);
        }
        i++;
    }

    while(j < m) {
        if(Union.back() != nums2[j]) {
            Union.push_back(nums2[j]);
        }
        j++;
    }

    return Union;
}

vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    /* // Brute
    vector<int> visited(nums2.size(),0);
    for(int i = 0; i < nums1.size(); i++) {
        for(int j = 0; j < nums2.size(); j++) {
            if(nums1[i] == nums2[j] && visited[j] == 0) {
                ans.push_back(nums2[j]);
                visited[j] = 1;
                break;
            } else if(nums2[j] > nums1[i]) break;
        }
    }
    return ans; // O(MxN)
    */
    // Optimal
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();
    while(i < n && j < m) {
        if(nums1[i] < nums2[j]) {
            i++;
        } else if(nums2[j] < nums1[i]) {
            j++;
        } else {
            ans.push_back(nums1[i]);
            i++; j++;
        }
    }
    return ans;
    // O(M), 
    // where M is the length of that array which has less elements.
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