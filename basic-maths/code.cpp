#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
    int count = 0;
    while(n > 0){
        n = n/10;
        count ++;
    }
    return count;
}

int countDigitsLog(int n){
    // since count depends on the number of times N is divisible by 10 -> log10(n) integer part + 1
    // num of digits in number = log10(n) + 1;
    int count = (int)log10(n) + 1;
    return count;
}

int reverseNumber(int n){
    int reverse_number = 0;
    // since we want to add the last digit to the end, we need to increase it by 10 times (number * 10) then add the last digit.
    while(n>0){
        reverse_number = (reverse_number*10)+(n % 10);
        n = n/10;
    }
    return reverse_number;
}

string checkPalindrome(int n){
    int reverse_number = 0;
    int original_number = n;
    // since we want to add the last digit to the end, we need to increase it by 10 times (number * 10) then add the last digit.
    while(n>0){
        reverse_number = (reverse_number*10)+(n % 10);
        n = n/10;
    }
    return (reverse_number == original_number ? "true" : "false");
}

string checkArmstrong(int n){
    // sum of cube of digits in number = original_number
    int cubed_sum = 0;
    int original_number = n;
    while(n>0){
        cubed_sum += pow(n % 10,3);
        n = n/10;
    }
    return (cubed_sum == original_number ? "true" : "false");
}

void printAllDivisors(int n){
    // all the divisors of a number will lie between 1 and that number itself. TC -> O(N)
    for(int i=1;i<=n;i++){
        if(n % i == 0) cout << i << " ";
    }
}

void printDivisorsBetterComplexity(int n){
    // but  we can do better than O(N)
    // 1 * 36 - 2 * 18 - 3 * 12 - 4 * 9 - 6 * 6
    // pattern -> i * n/i till sqrt(n) after that the patterns are repeating so no need to consider them again.
    // so we can consider numbers till sqrt(n), till sqrt(n) numbers are ascending.
    // sqrt is c++ stl mathematical function, so it will take some time -> we can simply do i*i <= n instead.
    // this loop takes - O(sqrt(N))
    vector<int> divisors;
     for(int i=1;i*i <= n;i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(n/i != i) divisors.push_back(n/i);
        }
    }
    // internal sorting function takes nlog(n) time. n = number of factors
    sort(divisors.begin(), divisors.end());
    // this loop takes o(n)
    for(auto div:divisors){
        cout << div << " ";
    }
    // TC -> O(sqrt(N)) + O(nlog(n)) + O(n)
}

string checkForPrime(int n){
    // number that has exactly 2 factors - 1 and that number itself
    int count = 0;
    for(int i=1;i<=n;i++){
        if(n % i == 0) count++;
    }
    if(count == 2) return "true";
    return "false";
    // brute force approach -> O(N)
}

string checkForPrimeBetterComplexity(int n){
    int count = 0;
    for(int i=1;i * i<= n; i++){
        if(n%i == 0){
            count ++;
            if(n/i != i) count++;
        }
    }
    if(count == 2) return "true";
    return "false";
    // TC - O(sqrt(N))
}

int GCD(int num1, int num2){
    // Greatest Common Divisor or Highest Common Factor
    // the largest number that divides both the numbers
    // every number is divisible by 1, so initializing the gcd with 1.
    int loopTill = min(num1, num2);
    int gcd = 1;
    for(int i=2;i<=loopTill;i++){
        if(num1 % i == 0 && num2 % i == 0){
            gcd = i;
        }
    }
    return gcd;
    // TC = O(min(num1,num2))
    // even if we run the loop backwards, the worst case scenario is still O(min(num1,num2)), in case 1 is the gcd.
}

int GCDViaEuclidianAlgorithm(int num1, int num2){
    while(num1 > 0 && num2 > 0){
        if(num1 >= num2) num1 = num1%num2;
        else num2 = num2%num1;
    }
    if(num1 == 0) return num2;
    return num1;
    // TC = O(log(min(num1,num2))) - log of phi, since num1 and num2 are changing
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N1,N2;
        cin >> N1 >> N2;
        cout << GCDViaEuclidianAlgorithm(N1,N2);
        // printDivisorsBetterComplexity(N);
        cout << "\n";
    }
    return 0;
}

/* 
Basic Maths

Digit Concept

N = 7789
Digit Extraction -> using modulo % operator with 10
N % 10 = 9
N = N / 10

likewise we proceed
while(N > 0) {
    int last_digit = N % 10;
    N = N / 10;
}

TC : O(log10(N)) - the number of times the loop runs = number of times n is divisible by 10

whenever there is division by some number, then TC will be O(log(base_number)(N)) base_number = 2,10 any number we are dividing

when we are dividing, then logarithmic TC will come into play.

 */

/* 

Euclidian Algorithm =>

If there are 2 numbers N1, N2.
GCD (N1,N2) = GCD(N1-N2,N2) given N1 > N2

proof by induction ->

N1 = 20, N2 = 15

GCD(20,15) = GCD(5,15) , since a must be > b, we switch
GCD(15,5) = GCD(10,5) = GCD(5,5) = GCD(0,5)
GCD(5,0) = 5 since the other number is 0.

If the difference between N1 and N2 is too big, then it might not improve the linear complexity.

So instead of subtracting one step by one step, we can do GCD(N1%N2,N2). It will reduce the number of steps.

so GCD(a,b) = GCD(a%b,b), where a>b.
Greater % Smaller , Smaller => we go until one of them is 0.and we get the GCD (other one remaining) in logarithmic complexity.

 */