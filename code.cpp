/* 

Pattern 1

No of Columns = No of Rows

for each row, we are printing N stars.
i = 1 -> * * * *
i = 2 -> * * * *

* * * *
* * * *
* * * *
* * * *

*/


/* 

Pattern 2

No of Columns = index of row

for each row number i, we are printing that number of stars.
i = 1 -> *
i = 2 -> * *

*
* *
* * *
* * * *

*/

/*

Pattern 3

No of Columns = index of row

for each row number i, we are printing till that number i.
i = 1 -> 1
i = 2 -> 1 2

1
1 2
1 2 3
1 2 3 4

*/

/*

Pattern 4

No of Columns = index of row

for each row number i, we are printing i for i number of times.
i = 1 -> 1
i = 2 -> 2 2
i = 3 -> 3 3 3

1
2 2
3 3 3
4 4 4 4

*/

/*

Pattern 5

No of Columns = (N) - index of row (0 based indexing)

for each row number i, we are printing * for N - i number of times.
i = 1 -> * * * *
i = 2 -> * * *

* * * *
* * *
* *
*

*/

/*

Pattern 6

No of columns = N - index of column (0 based indexing)
for each row number i, we are printing till N - i.

i = 1 -> 1 2 3 4
i = 2 -> 1 2 3

1 2 3 4
1 2 3
1 2
1

*/

/*

Pattern 7

Number of columns = 2 * N - 1

for each row number i, we are printing 2 * i + 1 number of *s in middle and N - i - 1 number of spaces on each side. i - 0 based indexing

i = 1 -> * in middle and 8 spaces (4 on each side) - [4,1,4]
i = 2 -> * * * in middle and 6 spaces (3 on each side) - [3,3,3]
i = 3 -> * * * * * in middle and 4 spaces (2 on each side) - [2,5,2]
i = 4 -> * * * * * * * in middle and 2 spaces (1 on each side) - [1,7,1]
i = 5 -> * * * * * * * * * and 0 spaces - [0,9,0]

spaces, stars, spaces

                *
            *   *   *
        *   *   *   *   *
    *   *   *   *   *   *   *
*   *   *   *   *   *   *   *   * 


*/

/*

Pattern 8

reverse order of the above pattern 7
spaces, stars, spaces

i = 1 -> [0,9,0]
i = 2 -> [1,7,1]
i = 3 -> [2,5,2]
i = 4 -> [3,3,3]
i = 5 -> [4,1,4]

*   *   *   *   *   *   *   *   * 
    *   *   *   *   *   *   *
        *   *   *   *   *
            *   *   *
                *

*/

/*

Pattern 9

pattern 7 + pattern 8

*/

/*

Pattern 10

i = 1 -> 1 * -> [1, N-1]
i = 2 -> 2 * -> [2, N-2]
i = 3 -> 3 * -> [3, N-3]
i = 4 -> 4 * -> [4, N-4]
i = 5 -> 3 * -> [3, N-3]
i = 6 -> 2 * -> [2, N-2]
i = 7 -> 1 * -> [1, N-1]

max number of stars = N = Number of columns

stars,spaces

*
* *
* * *
* * * *
* * *
* *
*


*/

/*

Pattern 11

i = 0 -> 1
i = 1 -> 0 1
i = 2 -> 1 0 1
i = 3 -> 0 1 0 1
i = 4 -> 1 0 1 0 1

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1


*/

/*

Pattern 12

numbers, spaces, numbers

N = 4
i = 1 -> 1,6,1
i = 2 -> 2,4,2
i = 3 -> 3,2,3
i = 4 -> 4,0,4

1      1
12    21
123  321
12344321

*/

/*

Pattern 13

N = 5
i = 1 -> 1
i = 2 -> 2 3
i = 3 -> 4 5 6
i = 4 -> 7 8 9 10
i = 5 -> 11 12 13 14 15

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15

*/

/*

Pattern 14

N = 5

i = 1 -> A
i = 2 -> A B
i = 3 -> A B C
i = 4 -> A B C D
i = 5 -> A B C D E

A
A B
A B C
A B C D
A B C D E

*/

/*

Pattern 15

N = 5

A B C D E
A B C D
A B C
A B
A

*/

/*

Pattern 16

N = 5


A
B B
C C C
D D D D
E E E E E

*/

/*

Pattern 17

N = 5

spaces, characters, spaces

i = 1 -> 4, A, 4
i = 2 -> 3, A B A, 3
i = 3 -> 2, A B C B A, 2
i = 4 -> 1, A B C D C B A, 1
i = 5 -> 0, A B C D E D C B A, 0

*/

/*

Pattern 18

N = 5

E-i to E print for each i = 0 to N-1

E
D E
C D E
B C D E
A B C D E

*/

/*

Pattern 19

Symmetry Pattern

Mirrored Symmetry Pattern from line 6 (here) -> n+1

**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********

stars, spaces, stars


*/

/*

Pattern 20

stars, spaces, stars

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *

*/

/*

Pattern 21

****
*  *
*  *
*  *
****

*/

/*

Pattern 22

at indices i = 1 or n and j = 1 or n -> print *
else " "

****
*  *
*  *
****

*/

/*

Pattern 23

N = 4

N - matrix = get the new matrix

top distance = i
left distance = j
right distance = 2n-2-j
bottom distance = 2n -2-i

then we minus from n and get the required matrix.

N = 4 -

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

=

index -> 0 1 2 3 4 5 6
|
0
1
2
3
4
5
6

0 0 0 0 0 0 0
0 1 1 1 1 1 0
0 1 2 2 2 1 0
0 1 2 3 2 1 0
0 1 2 2 2 1 0
0 1 1 1 1 1 0
0 0 0 0 0 0 0

*/


#include<bits/stdc++.h>
using namespace std;

void printPattern1(int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "* ";
        }
    cout << "\n";
    }
}

void printPattern2(int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << "* ";
        }
    cout << "\n";
    }
}

void printPattern3(int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << j+1 << " ";
        }
    cout << "\n";
    }
}

void printPattern4(int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << i+1 << " ";
        }
    cout << "\n";
    }
}

void printPattern5(int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << "* ";
        }
    cout << "\n";
    }
}

void printPattern6(int n) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << j+1 << " ";
        }
    cout << "\n";
    }
}

void printPattern7(int n) {
    for(int i=0;i<n;i++){
        // spaces
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        // stars
        for(int j=0;j<2*i+1;j++){
            cout << "*";
        }
        // spaces
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        cout << "\n";
    }
}

void printPattern8(int n) {
    for(int i=0;i<n;i++){
        // spaces
        for(int j=0;j<i;j++){
            cout << " ";
        }
        // stars
        for(int j=0;j<2*n-(2*i+1);j++){
            cout << "*";
        }
        // spaces
        for(int j=0;j<i;j++){
            cout << " ";
        }
        cout << "\n";
    }
}

void printPattern9(int n) {
    printPattern7(n);
    printPattern8(n);
}

void printPattern10(int n) {
    for(int i=1;i<=2*n-1;i++){
        int stars = i;
        if (i > n) stars = 2 * n -i;
        for(int j=0;j<stars;j++){
            cout << "* ";
        }
        cout << "\n";
    }
}

void printPattern11(int n) {
    int start = 1;
    for(int i=0;i<n;i++){
        if(i % 2 == 0) start = 1;
        else start = 0;
        for(int j=0;j<=i;j++){
            cout << start << " ";
            start = 1 - start;
        }
        cout << "\n";
    }
}

void printPattern12(int n){
    for(int i=1; i<=n;i++){
        // numbers
        for(int j=1;j<=i;j++){
            cout << j;
        }
        // spaces
        for(int j=1;j<=2*(n-i);j++){
            cout << " ";
        }
        // numbers
        for(int j=i;j>=1;j--){
            cout << j;
        }
        cout << "\n";
    }
}

void printPattern13(int n){
    int start = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << start << " ";
            start += 1;
        }
        cout << "\n";
    }
}

void printPattern14(int n){
    // char start = 'A';
    // for(int i=1;i<=n;i++){
        // for(int j=1;j<=i;j++){
        //     cout << char(start+j-1) << " ";
        // }
    // }
    for(int i=0;i<n;i++){
        for(char ch='A'; ch <= 'A' + i; ch++){
            cout << ch << " ";
        }
        cout << "\n";
    }
}

void printPattern15(int n){
    for(int i=0;i<n;i++){
        for(char ch='A'; ch < 'A'+n-i; ch++) {
            cout << ch << " ";
        }
        cout << "\n";
    }
}

void printPattern16(int n){
    // char ch='A';
    for(int i=0;i<n;i++){
        char ch='A'+ i;
        for(int j=0;j<=i;j++){
            cout << ch << " ";
        }
        cout << "\n";
    }
}

void printPattern17(int n){
    for(int i=0;i<n;i++){
        // spaces
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        // alphabets
        char ch = 'A';
        int breakpoint = i;
        for(int j=0;j<2*i+1;j++){
            cout << ch;
            if(j < breakpoint) ch++;
            else ch--;
        }
        // spaces
        for(int j=0;j<n-i-1;j++){
            cout << " ";
        }
        cout << "\n";
    }
}

void printPattern18(int n){
    for(int i=0;i<n;i++){
        /*
        char ch = 'E'-i;
        for(int j=0;j<=i;j++){
            cout << ch << " ";
            ch++;
        }
        */
        for(char ch='E'-i; ch<='E'; ch++){
            cout << ch << " ";
        }
        cout << "\n";
    }
}

void printPattern19(int n){
    /*
    for(int i=1;i<=2*n;i++){
        int breakpoint = n+1;
        int stars = n-i+1;
        int spaces = 2*(i-1);
        if(i >= breakpoint){
            stars = i-n;
            spaces = 2*(2*n - i);
        }    
        // stars
        for(int j=1;j<=stars;j++){
            cout << "*";
        }
        // spaces
        for(int j=1;j<=spaces;j++){
            cout << " ";
        }
        // stars
        for(int j=1;j<=stars;j++){
            cout << "*";
        }
        cout << "\n";
    }
    */
    for(int i=0;i<n;i++){
        // stars
        for(int j=0;j<n-i;j++){
            cout << "*";
        }
        // spaces
        for(int j=0;j<2*i;j++){
            cout << " ";
        }
        // stars
        for(int j=0;j<n-i;j++){
            cout << "*";
        }
        cout << "\n";
   }

   for(int i=0;i<n;i++){
        // stars
        for(int j=0;j<=i;j++){
            cout << "*";
        }
        // spaces
        for(int j=0;j<2*(n-i-1);j++){
            cout << " ";
        }
        // stars
        for(int j=0;j<=i;j++){
            cout << "*";
        }
        cout << "\n";
   }
}

void printPattern20(int n){
    /*
    for(int i=0;i<2*n-1;i++){
        int breakpoint = (2*n-1)/2;
        int stars = i;
        int spaces = 2*(n-i-1);
        if(i>breakpoint) {
            stars = 2*n-i-2;
            spaces = 2*(i-n+1);
        }
        // stars
        for(int j=0;j<=stars;j++){
            cout << "*";
        }
        // spaces
        for(int j=0;j<spaces;j++){
            cout << " ";
        }
        // stars
        for(int j=0;j<=stars;j++){
            cout << "*";
        }
        cout << "\n";
    }
    */
    for(int i=1;i<=2*n-1;i++){
        int stars = i;
        int spaces = 2*(n-i);
        if(i>n) {
            stars = 2*n-i;
            spaces = 2*(i-n);
        }
        // stars
        for(int j=1;j<=stars;j++){
            cout << "*";
        }
        // spaces
        for(int j=1;j<=spaces;j++){
            cout << " ";
        }
        // stars
        for(int j=1;j<=stars;j++){
            cout << "*";
        }
        cout << "\n";
    }
}

void printPattern21(int n){
    for(int i=1;i<=n;i++){
        int stars = 1;
        int spaces = n-3;
        if(i == 1 || i == n){
            stars = n-1;
            spaces = 0;
        }
        // stars
        for(int j=1;j<=stars;j++){
            cout << "*";
        }
        // spaces
        for(int j=1;j<=spaces;j++){
            cout << " ";
        }
        // stars
        for(int j=1;j<=stars;j++){
            if(i == 1 || i == n) continue;
            cout << "*";
        }
        cout << "\n";
    }
}

void printPattern22(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == 1 || i == n || j == 1 || j == n) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}

void printPattern23(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top = i;
            int left = j;
            int bottom = 2*n-2-i;
            int right = 2*n-2-j;
            cout << n-(min(min(top,bottom),min(left,right)));
        }
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
        printPattern23(N);
        cout << "\n";
    }
    return 0;
}