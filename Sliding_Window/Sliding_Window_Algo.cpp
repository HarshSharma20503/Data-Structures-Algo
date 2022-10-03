/*  Sliding Window Technique aims to reduce the use of nested loop and replace 
    it with a single loop hence reduces the time complexity  */

/*  Here we compute the sum of first k elements out of n terms using a linear loop
    and store the sum in variable sum_of_window.Then we will traverse linearly over the
    array till it reaches the end and simultaneously keep track of maximum sum  */

/* TC : O(n) 
   Space Complexity : O(1)  */


#include <bits/stdc++.h>  //This header file consists of all standard libraries
using namespace std;

int maxSum(int arr[], int n, int k)   //This function gives maximum sum in a subarray of size k
{
    if (n < k) {    //size of array must be greater than that of subarray
        cout << "Invalid";
        return -1;
    }

    // Computing sum of first window of size k
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i];

  /* Compute sums of remaining windows by
     removing first element of previous
     window and adding last element of
     current window  */

    int sum_of_window = max_sum;
    for (int i = k; i < n; i++) {
        sum_of_window += arr[i] - arr[i - k];
        max_sum = max(max_sum, sum_of_window);
    }

    return max_sum;
}

// Execution of code starts from main function
int main()
{
    int arr[] = { 3, 5, 0, 10, 2, 3, 8, 7, 9 };
    int k = 4;    //'k' is size of subarray 
    int n = sizeof(arr) / sizeof(arr[0]);    //'n' is size of entire array
    cout << maxSum(arr, n, k);
    return 0;
}
