#include<bits/stdc++.h>
using namespace std;

void countOccurenceOfElementInAnArray(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        // pre-compute
        int hash[N+1] = {0};
        for(int i=0;i<N;i++){
            hash[arr[i]] += 1;
        }

        int q;
        cin >> q;
        while(q--){
            int number;
            cin >> number;
            // fetch
            cout << hash[number] << endl;
        }
        cout << "\n";
    }
}

void characterHashing(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;

        // pre-compute
        // if we are not sure about the characters, then we can simply take the size as 256, and we don't need to - 'a' in this case.
        int hash[26] = {0};
        // int hash[256] = {0};
        for(int i=0;i<str.size();i++){
            hash[str[i]-'a']++;
            // hash[str[i]]++;
        }

        int q;
        cin >> q;
        while(q--){
            char ch;
            cin >> ch;
            // fetch
            cout << hash[ch-'a'] << endl;
            // cout << hash[ch] << endl;
        }
        cout << "\n";
    }
}

void countFrequencyViaMaps(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        // we can do the pre-computation while taking inputs as well, but not a big TC change N instead of 2N.
        // map<int,int> frequency;
        for(int i=0;i<N;i++){
            cin >> arr[i];
            // frequency[arr[i]]++;
        }

        // pre-compute
        // depending upon the number size we can define data type inside map
        map<int,int> frequency;
        for(int i=0;i<N;i++){
            frequency[arr[i]]++;
        }

        // iterate through map
        for(auto it: frequency){
            cout << it.first << "->" << it.second << endl;
        }

        int q;
        cin >> q;
        while(q--){
            int number;
            cin >> number;
            // fetch
            cout << frequency[number] << endl;
        }
        cout << "\n";
    }
}
// map stores all values in sorted order. Similarly we can do char hashing with map. map<char,int> mpp; mpp[str[i]]++;
// TC -> O(log(N))
// storing and fetching both takes log(N) logarithmic time in best,avg and worst cases. N = number of elements in map

void countFrequencyViaUnorderedMap(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin >> arr[i];
        }

        // pre-compute
        // depending upon the number size we can define data type inside map
        unordered_map<int,int> frequency;
        for(int i=0;i<N;i++){
            frequency[arr[i]]++;
        }

        // iterate through map
        for(auto it: frequency){
            cout << it.first << "->" << it.second << endl;
        }

        int q;
        cin >> q;
        while(q--){
            int number;
            cin >> number;
            // fetch
            cout << frequency[number] << endl;
        }
        cout << "\n";
    }
}
// unordered_map -> storing and fetching avg and best TC - O(1) = constant time.
// worst case is O(N) = linear time, N = number of elements in the map. -> very rare the worst case happens. First priority is unordered_map, if we get error TLE, then switch to map. Worst case happens only in case of internal collisions.

// In maps the key can be any data type and data structure - pair<int,int>, vector<int>. but in unordered_map the key can only be a single data type.(int,char,float,double,string)

void highestAndLowestFrequencyElement(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin >> arr[i];
        }

        // pre-compute
        // depending upon the number size we can define data type inside map
        unordered_map<int,int> frequency;
        for(int i=0;i<N;i++){
            frequency[arr[i]]++;
        }

        int maximumFreq = 0, minimumFreq = N,maxElement = 0, minElement = 0;
        // iterate through map
        for(auto it: frequency){
            int element = it.first;
            int count = it.second;
            if(count > maximumFreq) {
                maxElement = element;
                maximumFreq = count;
            }
            if(count < minimumFreq) {
                minElement = element;
                minimumFreq = count;
            }
        }
        cout << "Max Element: " << maxElement << " - Max Freq: " << maximumFreq << endl;
        cout << "Min Element: " << minElement << " - Min Freq: " << minimumFreq << endl;
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin >> arr[i];
        }

        // pre-compute
        // depending upon the number size we can define data type inside map
        unordered_map<int,int> frequency;
        for(int i=0;i<N;i++){
            frequency[arr[i]]++;
        }

        int maximumFreq = 0, minimumFreq = N,maxElement = 0, minElement = 0;
        // iterate through map
        for(auto it: frequency){
            int element = it.first;
            int count = it.second;

            if(count > maximumFreq) {
                maxElement = element;
                maximumFreq = count;
            } else if(count == maximumFreq) {
                if(element > maxElement) maxElement = element;
            }

            if(count < minimumFreq) {
                minElement = element;
                minimumFreq = count;
            } else if(count == minimumFreq) {
                if(element < minElement) minElement = element;
            }
        }
        cout << "Max Element: " << maxElement << " - Max Freq: " << maximumFreq << endl;
        cout << "Min Element: " << minElement << " - Min Freq: " << minimumFreq << endl;
        cout << "\n";
    }
    return 0;
}

/*

Hashing ->

Suppose there is an array having elements. and query comes for the occurrence of a particular element. 

Naive approach is -> run a for loop and increase the counter by 1 for each time the element is found. but if we increase the number of queries, then it will take a long time to return the answer. we can improve this TC by hashing.

Brute force approach => O(N) for each element query

int f(number, arr[]) {
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if( arr[i] == number) cnt++;
    }
    return cnt;
}

In simple terms -> hashing is pre-storing and fetching

Hashing ->

Suppose the maximum number which can be stored in the array is 10. so we will create another array with size 10, initialized to 0. this will be our hash array. and we will be increasing the count of the corresponding index which matches with the number we encountered.

eg - 1 is encountered so we will increase the index 1's value from 0 to 1 and so on.

It's the pre-calculation phase.

Now when the queries are made, we can just return it in constant O(1) time, by using the hash array.


In case of integers => 

Inside main -> the maximum size of an array can be 10^6. More than this will throw an segmentation fault.

But globally we can assign nearly 10^7 -> outside main

for bool -> inside main -> 10^7 ; global -> 10^8

if we are defining the array size globally then it will be initialized to 0 by default instead of garbage value.

If a problem requires number hashing, we can use arrays to hash them.

*/

/*

Character Hashing using arrays

Brute force approach => O(N) for each character query

int f(char c, str) {
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if( str[i] == c) cnt++;
    }
    return cnt;
}

To hash a characters in a string, we can make an array of size 26 (indexed from 0 to 25) -> lowercase characters - 26 uppercase characters - 26

we can use ascii values.

int x = 'a'; // won't throw an error, it will typecast the 'a' to its integer ascii value.(97)

'a' = 97
'z' = 122

so what we can do is we can subtract 'a' from a character to get its index.

'f' - 'a' = 5 -> index

ch - 'a' => to get the corresponding index in the hash array.

even if we have to create an array of 256 chars and hash them all . we can create one and we don't need to subtract anything.

In characters hashing we don't need to worry about the size of the array. At max there are 256 chars, and we can store them in the array easily.

lowercase - ch - 'a' - for index
uppercase - ch - 'A' - for index
all characters - 256 array size. only ch - for index , because hash needs an index. so if we do something as hash[str[i]] -> the char will be typecasted to its ascii integer value.

*/

/*

while hashing the numbers, we came across the array size problem.

inside main - 10^6
global - 10^7

what if we need to store 10^9, 10^12 or 10^18 numbers?

there comes c++ stl map and unordered_map.

in map data structure -> we store as key:value pair.

so here the number is the key and the number of occurences - frequencies are the values.

In maps we can only store the number of elements present in the array. But in array hashing we had to make a N+1 size of array.
we don't have to store non-required elements in map like arrays. so it is beneficial wrt SC.

*/

/*

Hashing Methods->
    Division Method
    Folding Method
    Mod Square Method

{2,3,4,5,9,1}

hash using division method in array->

array size not > 10 -> restriction

whenever storing the number = we do arr[i] % 10 and then store it in corresponding index of array.

while fetching also, we do number % 10 and retrieve that index in the array.

SO the problem is there might be cases where the modulo of the number gives back the same index. so we chain the elements at that index. (generally done using LinkedList)

so data are stored ->
{2,3,5,18,28,48,139,16,28}

2 -> 2
3 -> 3
5 -> 5
6 -> 16
8 -> 18 -> 28 -> 28 -> 48 (first we point 28 -> 28 then create 28 -> 48 and then break the link between first 28 and 48)
9 -> 139

While fetching we can number % 10 and then do some search operations to get the element at that index.

since all elements are in sorted order, searching becomes easy, takes less time.

In this way we can store values in a limited memory storage by using linear chaining using division method.

Suppose all the elements in the array is being sent to the same hashing index, then the search space becomes very big and at that time we reach the worst case scenario -> O(N) collision happens in the worst case scenario. whatever hashing they are using all values are landing in the same hash space index.

*/