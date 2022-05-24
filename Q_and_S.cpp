<Question> : Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

[Approach] : the number we want will range from 1 to n+1 (n=size of array).We define another array to store positive number >0 and <=n to corresponding index and transverse the array to find first missing integer.
"Solution":
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

<Question> : Given an index k, return the kth row of the Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Input : k = 3


Return : [1,3,3,1]
"Solution" : 
vector<int> Solution::getRow(int A) {
    int i,j;
    vector<int> ans;
    ans.push_back(1);
    if(A==0)
        return ans;
        ans.clear();
    ans.push_back(1);ans.push_back(1);
    if(A==1)
        return ans;
    for(i=2;i<=A;i++)
    {
        vector<int> extra;
        for(j=0;j<ans.size();j++){
            extra.push_back(ans[j]); //this step is base of solution : creating temporaray v1 every time 
        }
        ans.clear();
        for(j=0;j<=i;j++)
        {
            if(j==0 || j==i)
                ans.push_back(1);
            else
                ans.push_back(extra[j-1]+extra[j]);
        }
    }
    return ans;
}






<Question> :You have to find the smallest number that has same set of digits as A and is greater than A.

If A is the greatest possible number with its set of digits, then return -1.

[Approach] : Approach is very deep myself taken time and 4-5 test fail to find coorect solution . So give a concentrated read.

"Solution" : 
string Solution::solve(string A) {
    string b = A,c=A;
    int k=A.length();
    sort(b.begin(),b.end(),greater<char>());
    sort(c.begin(),c.end());
    if(A==b) return "-1";
    if(A==c){
        swap(A[k-2],A[k-1]);
        return A;
    }
    for(int i=k-2;i>=0;i--){
        int k1=(A[i]-'0');
        int k2=(A[i+1]-'0');
        int k3=(A[k-1]-'0');
        if(k1>k2){
            if(k1<k3){
                swap(A[i],A[k-1]);
                return A;
            }
            sort(A.begin()+i,A.end());
            continue;
        }
        else if(k1!=k2){
            swap(A[i],A[i+1]);
            return A;
        }
        else{
            if(i<k-2){
                swap(A[i],A[i+2]);
                return A;
            }
        }
    }

}





<Question> You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and 
 does not fit in a 32 bit signed integer.
 
"Solution" : 
int Solution::reverse(int A) {
    long int sol = 0;
    
    while(A != 0){
        sol = sol*10 + (A%10);    
        A = A/10;
    }
    if(sol > INT_MAX || sol < INT_MIN){
        return 0;
    }
    return sol;
}
