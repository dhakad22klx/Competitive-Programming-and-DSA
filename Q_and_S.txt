Question : Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

Approach : the number we want will range from 1 to n+1 (n=size of array).We define another array to store positive number >0 and <=n to corresponding index and transverse the array to find first missing integer.
Solution:
int Solution::firstMissingPositive(vector<int> &A) {
    int n= A.size();
    int a[n+1] ={0};
    for(int i=0;i<n;i++){
        if(A[i]>0 && A[i]<=n) a[A[i]]=A[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0) return i;
    }
    return n+1;
    

}
