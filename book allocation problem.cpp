/**

Problem statement
You are the Librarian of the Ninja library. There are ‘N’ books available in the library and ‘B’ ninjas want to read the books. You know the number of pages in each book and you have to allocate the books to the ‘B’ ninjas in such a way that the maximum number of pages allocated to a ninja is minimum.

Note

A book will be allocated to exactly one ninja. 
At least one book has to be allocated to a ninja.
Allotment of the books should be done in a contiguous manner. For example, a ninja can not be allocated book 2 and book 4, skipping book 3.
The task is to return the minimum of the maximum number of pages allocated to a ninja.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
1
4 2
10 20 30 40
Sample output 1:
60
Explanation of Sample output 1:
There are two ninjas and these are the following ways to allocate the books between them. 
Way 1 ⇒ Ninja 1: [10] and Ninja 2: [20, 30, 40] 
Way 2 ⇒ Ninja 2: [10, 20], and Ninja 2: [30, 40] 
Way 3 ⇒ Ninja 1: [10, 20, 30], and Ninja 2: [40] 
Among all the ways, way 3 is the best way because the maximum number of pages allocated to a ninja is 60. In way 1 and way 2, the maximum number of  pages allocated to a ninja is 90, and 70, respectively. Hence, 60 is the answer. 
Sample Input2:
1
5 6
10 20 30 40 50 
Sample Output2:
-1
Explanation of Sample output 2
Since we can not allocate at-least one book to every ninja, the answer is -1.

*/

/*
problem statement link:
https://www.codingninjas.com/studio/problems/allocate-books_1089560

*/



#include <vector>
using namespace std;

bool isPossible(vector<int>& pages, int n, int b, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++) {
        if (pageSum + pages[i] <= mid) {
            pageSum += pages[i];
        } else {
            studentCount++;
            if (studentCount > b || pages[i] > mid) {
                return false;
            }
            pageSum = pages[i];
        }
    }
    return true;
}

int allocateBooks(vector<int>& pages, int n, int b) {
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pages[i];
    }
    int e = sum;
    int ans = -1;

    if(b>n){
        return -1;
    }

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossible(pages, n, b, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}



/*

Test cases:

Test cases1
1
4 2
10 20 30 40
o/p: 60

Test cases2
1
5 6
10 20 30 40 50
o/p: -1

Test cases3
1
6 4
4 7 8 17 5 10 
o/p: 17

Test cases4
2
6 6
1 17 6 7 2 11 
6 1
2 4 7 8 16 17 
o/p: 17  54

Test cases5
3
10 20
6 6 6 6 6 6 6 6 6 6
10 1
6 6 6 6 6 6 6 6 6 6
10 10
6 6 6 6 6 6 6 6 6 6
o/p: -1 60 6

*/
