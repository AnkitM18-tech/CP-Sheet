#include<bits/stdc++.h>
using namespace std;

void explainPair(){
    pair<int,int> p = {1,4};
    cout << p.first << " " << p.second << endl;
    pair<int,pair<int,int>> p2 = {1,{2,3}};
    cout << p2.first << " " << p2.second.first << p2.second.second << endl;
    pair<int,int> arr[] = {{1,2},{2,3},{4,5}};
    cout << arr[1].first;
}

void explainVector(){
    // array size can't be modified, but vectors can have dynamic sizing. arrays are constant in size, so in that situation vectors come into picture.We can always modify the size of the vector whenever we need to. When we are not sure about the size of the container, instead of array we can use vector.
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2); // faster than push_back() - does the same thing, dynamically increases the size of the vector and adds the element to the back of the vector.

    vector<pair<int,int>> vec;
    vec.push_back({1,2}); // when we push a pair into the vector using push_back(), we need {}
    vec.emplace_back(1,2); // while using emplace_back(), we don't need {}. It will assume it as a pair and add it to the vector.
    vector<int> v(5,100); // a vector of size 5, all initialized to 100 will be created.
    vector<int> v(5); // a vector of size 5, all initialized to 0/garbage value (depends upon the compiler) will be created.
    vector<int> v1(5,20);
    vector<int> v2(v1); // we can copy a vector to another vector like this.
    // even if we declare the size of the vector, we can increase it afterwards.
    // we can access the elements in vector using the indices, same as in arrays. v[i] where i = 0,1,2,3 .. or v.at(i) generally not used.
    // another way is by using iterators.
    // syntax - data_structure<data_type>::iterator name_of_iterator - iterator it points to the memory address of the element in the vector here. We can access the element value by using *(it). using * we can access the element inside the container.
    // since vector's elements are stored in contiguous memory locations so v.begin() points to the memory address of first element and we can increase the it++ so that it points to the next element. likewise we can access the elements inside the container.
    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << endl;
    vector<int>::iterator it = v.end(); // will point to the memory address of end_element + 1, so we can get the last element by doing it--.
    // reverse iterator => think in reverse order
    // vector<int>::iterator it = v.rend(); // will start from the end of the vector and then goes towards the left. so basically it points to the left of the first element in the vector. i.e end from the right side
    // vector<int>::iterator it = v.rbegin(); // points to the end element, and if we do it++ then it will move from right to left in the container.
    cout << v.back() << endl; // the element which is at the back of the vector.

    // iterating through the vector using iterator
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *(it) << " ";
    }
    // iterating using auto keyword
    for(auto it = v.begin(); it != v.end(); it++){
        cout << *(it) << " ";
    }
    // iterating using for each
    for(auto it:v){
        cout << it << " ";
    }

    // erase {10,20,30,40}
    v.erase(v.begin() + 1); // will erase the element at that address -> 20
    // {10,20,12,23,25}
    v.erase(v.begin() + 2, v.begin() + 4); // [start,end) -> end vector = {10,20,25} -> end is not inclusive, so the required elements can be erased by giving the start address and the end address after the last element we want to erase.(end + 1)

    // insert function
    vector<int> v(2,100); // {100,100}
    v.insert(v.begin(),300); // {300,100,100}
    v.insert(v.begin() + 1,2,10); // {300,10,10,100,100}
    // insert the vector elements into another vector
    vector<int> copy(2,50); // {50,50}
    v.insert(v.begin(),copy.begin(),copy.end()); // {50,50,300,10,10,100,100}

    cout << v.size() << endl; // size of the vector
    // {10,20}
    v.pop_back(); // pops back the last element of the vector -> 20 - {10}

    // v1 = {10,20}
    // v2 = {30,40}
    v1.swap(v2); // swaps the vectors -> v1 = {30,40}, v2 = {10,20}
    v.clear(); // clears the entire vector
    cout << v.empty(); // prints True if the vector is empty
}

void explainList(){
    list<int> ls;
    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2,4}
    ls.push_front(5); // {5,2,4}
    ls.emplace_front(); // {2,4}

    // insert in vectors are very costly functions
    // rest methods are same as vector -> begin,end,rbegin,rend,size,swap,clear, insert
    // same as vector, dynamic in nature (size can be increased), also provide front operations
    // internal implementation is a doubly linked list and for vector a singly linked list is maintained, so list is faster
    // push_front() is cheaper operation than insert() in case of complexity.
}

void explainDeque(){
    deque<int> dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1,2}
    dq.push_front(4); // {4,1,2}
    dq.emplace_front(3); // {3,4,1,2}
    dq.pop_back(); // {3,4,1}
    dq.pop_front(); // {4,1}
    dq.back();
    dq.front();

    // rest methods same as vectors
    // begin,end,rbegin,rend,size,swap,clear, insert
}

void explainStack(){
    // LIFO
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2,1}
    st.push(3); // {3,2,1}
    st.push(3); // {3,3,2,1}
    st.emplace(5); // {5,3,3,2,1}
    cout << st.top(); // prints 5, can't access stack using indices. st[2] -> invalid
    st.pop(); // {3,3,2,1}
    cout << st.top(); // 3
    cout << st.size(); // 4
    cout << st.empty(); // false
    stack<int> st1,st2;
    st1.swap(st2); // swaps stack elements

    // all operations are O(1)
}

void explainQueue(){
    // FIFO
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.emplace(3); // {1,2,3}
    q.back() += 5;
    // q = {1,2,8}
    cout << q.back(); // 8
    cout << q.front(); // 1
    q.pop(); // {2,8}
    cout << q.front(); // 2
    // size,swap,empty same as stack
}

void explainPriorityQueue(){
    // similar to queue
    // The maximum value stays at the top - maximum integer, maximum character, double, string (lexicographically largest string) etc
    // The internal architecture is Tree Data Structure. It is not a linear data structure.
    // also known as max heap
    priority_queue<int> pq;
    pq.push(5); // {5}
    pq.push(2); // {5,2}
    pq.push(8); // {8,5,2}
    pq.emplace(10); // {10,8,5,2}
    cout << pq.top(); // 10
    pq.pop(); // {8,5,2}
    cout << pq.top(); // 8
    pq.push(3); // {8,5,3,2}
    // size , swap, empty same as others

    // Minimum Heap - below is the syntax for it - the minimum value will be at the top
    // known as min heap
    priority_queue<int, vector<int>,greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.emplace(10); // {2,5,8,10}
    pq.emplace(3); // {2,3,5,8,10}

    cout << pq.top(); // 2

    // TC -> push -> log(N), top -> O(1), pop -> log(N)
}

void explainSet(){
    // stores in sorted order, and unique values
    // internally a tree is maintained, It is not a linear data structure
    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1,2}
    st.insert(2); // {1,2}
    st.insert(4); // {1,2,4}
    st.insert(3); // {1,2,3,4}

    // Functionality of insert in vector can be used also,that only increases efficiency.
    // begin,end,rbegin,rend,size,empty,swap are same as previous
    // {1,2,3,4,5}
    auto it = st.find(3); // returns iterator which points to 3

    auto it = st.find(6); // when the element is not in the set, it will return st.end() -> iterator pointing to the next address of the last element
    // {1,4,5}
    st.erase(5); // takes logarithmic time, erases 5 // {1,4}

    int cnt = st.count(1); // always return 1 if present, if not exists returns 0
    auto it = st.find(3);
    st.erase(it); // takes constant time

    // {1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2); // after erase -> {1,4,5} -> [first,last) -> last element not inclusive

    // lower_bound() and upper_bound() works the same way as in vectors - need to watch video
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

    // in set everything happens in log(N) complexity
}

void explainMultiset(){
    // everything same as set, but it stores duplicate elements as well
    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    ms.erase(1); // all 1's will be erased
    int cnt = ms.count(1);

    ms.erase(ms.find(1)); // only a single occurence will be erased
    ms.erase(ms.find(1), (ms.find(1)++)++); 
    // all other functions are same as set
    // erase(element) -> erases all element occurences
    // erase(iterator) -> erases only that occurence which is pointed by the iterator
}

void explainUnorderedSet() {
    unordered_set<int> us;
    // lower_bound and upper_bound functions don't work, rest are same
    // all operations are generally in constant time O(1), worst case scenario O(N)
    // doesn't store in any particular order, stores unique elements. It has a better complexity than set in most cases, except when some collision happens.
}

void explainMap(){
    // data stored in key:value pairs. where keys are unique and can be of any data type. same goes for value, it need not be unique.
    // map stores unique keys in sorted order
    map<int,int> mpp;
    map<int,pair<int,int>> mpp;
    map<pair<int,int>,int> mpp;

    // mpp[1] = 2;
    // mpp.emplace({3,1});
    // mpp.insert({2,4});
    // mpp[{2,3}] = 10;
    /* {
            {1,2},
            {2,4},
            {3,1}
        }
     */
    for(auto it:mpp){
        cout<< it.first << " " << it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5]; // returns 0 if it doesn't exist

    auto it = mpp.find(3);
    // cout << *(it).second << endl;
    auto it = mpp.find(5); // returns mpp.end() if it doesn't exist.

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty are same as previous
}

void explainMultimap(){
    // same as map, only difference is it can store duplicate keys here
    // mpp[key] can't be used here.
    // equal_range(key) - returns iterator of entries with range of pairs for the key.
}

void explainUnorderedMap(){
    // same as unordered_set and set difference.
    // map works in log(N) time complexity and unordered_map works in O(1) constant time. worst case O(N)
}

bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second){
        return true;
    } else if(p1.second == p2.second) {
        if(p1.first > p2.first) return true;
    }
    return false;
}

void explainCommonAlgo(){
    // sort(a,a+n); sorting array a with size n
    // sort(v.begin(),v.end());
    // sort(a+2,a+4); // specific portion sort [first,last)
    // sort(a,a+n,greater<int>); // descending order , greater<int> is an inbuilt comparator.

    pair<int,int> a[] = {{1,2},{2,1},{4,1}};
    // sort it according to second element, if second element is same then sort it according to first element but in descending order
    sort(a,a+3,comp); // comp is a bool function that defines the logic behind our sorting
    // {{4,1},{2,1},{1,2}}

    int num = 7;
    int cnt = __builtin_popcount(num); // return the number of set bits (111 for 7 -> 3, 110 for 6 -> 2)
    // if the number is long long, then we use __builtin_popcountll(num)

    string s = "123";
    do {
        cout << s << "\n";
    } while(next_permutation(s.begin(),s.end()));
    // will print permutations in dictionary order, when all permutations are covered, then it goes to null and returns false.
    // if s="231", then it would have gone like 312, 321, null, it only finds permutations from the given string in dictionary order.
    // so if we want to get all permutations then we can sort it first using sort(s.begin(), s.end()) and then run next_permutation() on it.

    int b[] = {0,1,2,3,4,5,6};
    int maxi = *max_element(b,b+6); // similarly we have min_element as well, they return us the iterator and we get the value by using * infront of it.
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        cout << "\n";
    }
    return 0;
}

/*

C++ STL

4 parts

- Algorithms
- Containers
- Functions
- Iterators


*/

/* 

lower_bound function ->
returns first occurence of the element if it exists and if it doesn't exist, then it will return the iterator that is pointing to the immediate next greater element.

returns an iterator.
If an element is not found, then it returns the next greater element's iterator.

second scenario when we do - a (a's iterator = first element's address) we get the index 4.

Third scenario there are no greater elements than 10 ,so it returns the iterator that is after the last element. -> 6

a[] = {1,4,5,6,9,9};
int ind = lower_bound(a,a+n,4) - a; // 1
int ind = lower_bound(a,a+n,7) - a; // 4
int ind = lower_bound(a,a+n,10) - a; // 6

int ind = lower_bound(a.begin(), a.end(),4) - a.begin()

 */

/* 

Upper Bound function ->

returns an iterator pointing to the next element greater than the required element.

so first scenario, returns iterator pointing to 5

second sceanrio, returns iterator pointing to 9

third scenario, returns iterator pointing to end of the array + 1. since it doesn't exists.

a[] = {1,4,5,6,9,9};
int ind = upper_bound(a,a+n,4) - a; // 2
int ind = upper_bound(a,a+n,7) - a; // 4
int ind = upper_bound(a,a+n,10) - a; // 6

int ind = upper_bound(a.begin(), a.end(),4) - a.begin()

upper_bound and lower_bound functions work in log(N) complexity.

 */ 