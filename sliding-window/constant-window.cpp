#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardScore , int k){
    int lSum = 0, rSum = 0, maxSum = 0;

    for(int i = 0; i < k; i++) {
        lSum += cardScore[i];
        maxSum = lSum;
    }

    int right = cardScore.size() - 1;

    for(int i = k-1; i >= 0; i--) {
        lSum -= cardScore[i];
        rSum += cardScore[right];
        right--;
        maxSum = max(maxSum, lSum + rSum);
    }

    return maxSum; // O(2*k)
}

int longestNonRepeatingSubstring(string& s){
    /*
    // Brute - TC = O(N^2), SC = O(256)
    int n = s.size();

    int maxLen = 0;

    for(int i = 0; i<n; i++) {

        vector<int>hash(256,0);

        for(int j = i; j<n; j++) {
        if(hash[s[j]] == 1) break;

        hash[s[j]] = 1;

        int len = j - i + 1;
        maxLen = max(maxLen,len);
        }
    }
    return maxLen;
    */
    // Optimal
    int n = s.size();
    int HASHLENGTH = 256;
    int hash[HASHLENGTH];

    for(int i = 0; i<HASHLENGTH; i++) {
    hash[i] = -1;
    }

    int l = 0, r = 0, maxLen = 0;

    while(r<n) {
    if(hash[s[r]] != -1) {
        if(hash[s[r]] >= l) l = max(hash[s[r]] + 1, l);
    }

    int len = r - l + 1;
    maxLen = max(maxLen,len);

    hash[s[r]] = r;
    r++;
    }

    return maxLen; // O(N)
}

int longestOnes(vector<int>& nums, int k) {
    /*
    // Brute - O(N^2)
    int n = nums.size();

    int maxLen = 0, zeros = 0;

    for(int i = 0; i<n; i++) {
        zeros = 0;

        for(int j = i; j<n; j++) {
            if(nums[j] == 0) zeros++;

            if(zeros <= k) {
                int len = j - i + 1;
                maxLen = max(maxLen, len);
            } else break;
        }
    }
    return maxLen;
    
    // Better - O(2N)
    int n = nums.size();

    int l = 0, r = 0, zeros = 0, maxLen = 0;

    while(r < n) {
        if(nums[r] == 0) zeros++;

        while(zeros > k) {
            if(nums[l] == 0) zeros--;
            l++;
        }
        int len = r - l + 1;
        maxLen = max(len,maxLen);
        r++;
    }
    return maxLen;
    */
    // Optimal - O(N)
    int n = nums.size();
    int l = 0, r = 0, zeros = 0, maxLen = 0;

    while(r < n) {
        if(nums[r] == 0) zeros++;

        if(zeros > k) {
            if(nums[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k) {
            int len = r - l + 1;
            maxLen = max(len,maxLen);
        }
        r++;
    }
    return maxLen;
}

int totalFruits(vector<int>& fruits){
    /*
    // Brute - O(N^2) , SC = O(3)
    int n = fruits.size();
    int maxLen = 0;

    for(int i = 0; i<n; i++) {
        unordered_set<int> set;
        for(int j = i; j<n; j++) {
            set.insert(fruits[j]);

            if(set.size() <= 2) {
                int len = j - i + 1;
                maxLen = max(maxLen,len);
            } else break;
        }
    }
    return maxLen;
    
    // Better - O(2n), SC = O(3)
    int n = fruits.size();
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int,int> mpp;

    while(r < n) {
        mpp[fruits[r]]++;

        if(mpp.size() > 2) {
            while(mpp.size() > 2) {
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }
        }

        if(mpp.size() <= 2) {
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
    */
    // Optimal - O(N), SC = O(3)
    int n = fruits.size();
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int,int> mpp;

    while(r < n) {
        mpp[fruits[r]]++;

        if(mpp.size() > 2) {
            mpp[fruits[l]]--;
            if(mpp[fruits[l]] == 0) {
                mpp.erase(fruits[l]);
            }
            l++;
        }

        if(mpp.size() <= 2) {
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}

int kDistinctChar(string& s, int k) {
    /*
    //Brute - TC = O(N^2), SC = O(k)
    int n = s.size();
    int maxLen = 0;

    unordered_map<char,int> mpp;

    for(int i = 0; i<n; i++) {
        mpp.clear();
        for(int j = i; j<n; j++) {
            mpp[s[j]]++;

            if(mpp.size() <= k) {
                maxLen = max(maxLen, j - i +1);
            } else break;
        }
    }

    return maxLen;
    
    // Better - TC = O(2N), SC = O(k)
    int n = s.size();
    int l = 0, r = 0, maxLen = 0;

    unordered_map<char,int> mpp;

    while(r < n) {
        mpp[s[r]]++;

        while(mpp.size() > k) {
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) {
                mpp.erase(s[l]);
            }
            l++;
        }

        if(mpp.size() <= k) {
            maxLen = max(maxLen, r-l+1);
        }

        r++;
    }
    return maxLen;
    */
    // Optimal - O(N)
    int n = s.size();
    int l = 0, r = 0, maxLen = 0;

    unordered_map<char,int> mpp;

    while(r < n) {
        mpp[s[r]]++;

        if(mpp.size() > k) {
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) {
                mpp.erase(s[l]);
            }
            l++;
        }

        if(mpp.size() <= k) {
            maxLen = max(maxLen, r - l + 1);
        }

        r++;
    }
    return maxLen;
}

int characterReplacement(string s, int k) {
    /*
    //Brute - O(N^2) - TC and SC = O(26)
    int maxLen = 0;
    int maxfreq = 0;

    for(int i = 0; i<s.size(); i++) {
        int hash[26] = {0};
        for(int j = i; j<s.size(); j++) {
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq,hash[s[j] - 'A']);

            int changes = (j - i + 1) - maxFreq;

            if(changes <= k) {
                maxlen = max(maxLen, j - i + 1);
            } else break;
        }
    }
    return maxLen;
    
    // Better - O(2N * 26), O(26)
    int maxLen = 0, l = 0, r = 0, maxFreq = 0;
    int hash[26] = {0};

    while(r < s.size()) {
        hash[s[r]-'A']++;
        maxFreq = max(maxFreq,hash[s[r]-'A']);

        while((r-l+1) - maxFreq > k) {
            hash[s[l]-'A']--;
            // max freq for the new substring step
            maxFreq = 0;
            for(int i = 0; i<26; i++) {
                maxFreq = max(maxFreq, hash[i]);
            }
            l++;
        }
        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
    */
    // Optimal - O(N) , O(26)
    int l = 0, r = 0, maxLen = 0, maxFreq = 0;
    int hash[26] = {0};

    while(r < s.size()) {
        hash[s[r]-'A']++;

        maxFreq = max(maxFreq, hash[s[r]-'A']);
        if((r - l + 1) - maxFreq > k) {
            hash[s[l]-'A']--;
            l++;
        }

        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
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