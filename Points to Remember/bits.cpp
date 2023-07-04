//Brian Kernighan’s Algorithm: 

 #Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit. 
for example : 
10 in binary is 00001010 
9 in binary is 00001001 
8 in binary is 00001000 
7 in binary is 00000111 
so,(x&(~(x-1)) is lowest set bit number 
// 
int SetBit (int n, int X) { return n | (1 << X); }
int ClearBit (int n, int X) { return n & ~(1 << X); }
int ToggleBit (int n, int X) { return n ^ (1 << X); }
bool CheckBit (int n, int X) { return (bool)(n & (1 << X)); }

// to check power of 2 
if(x & (x - 1)){
      not power of 2
}
else power of 2

// theory point 
1.The & and | operators have lower precedence than comparison operators. That means that x & 3 == 1 is interpreted as x & (3 == 1), which is probably not what you want.

2. If you want to write completely portable C/C++ code, be sure to use unsigned types, particularly if you plan to use the top-most bit

3. " __lg(x)" //__lg(x) which returns the index of the highest set bit.

4. __builtin_ctz(x): Counts the trailing number of zeros of the integer(long/long long).
If x is of long type,we can use __builtin_ctzl(x) If x is of long long type,we can use __builtin_ctzll(x)
Ex- int x=16;       // 00000000 00000000 00000000 00010000 (32 bits)
    cout<<__builtin_ctz(x)<<endl;   //returns 4.
 

5. __builtin_popcount(x): Counts the number of one’s(set bits) in an integer(long/long long).

6. __builtin_parity(x): Checks the Parity of a number.Returns true(1) if the number has odd parity(odd number of set bits) else it returns false(0) for even parity(even number of set bits).

7. __builtin_clz(x): Counts the leading number of zeros of the integer(long/long long).
If x is of long type,we can use __builtin_clzl(x) If x is of long long type,we can use __builtin_clzll(x)
  Ex- long x=16;       // 00000000 00000000 00000000 00010000 (32 bits)
      cout<<__builtin_clzl(x)<<endl;   //returns 27.
      
8. 1 ) Printing the binary representation of any Number.
void pr_binary(int num){
    for(int i=10;i>=0;i--) cout<<((num>>i)&1);
    cout<<endl;
}
9. //Update :You can also represent any number in its binary form as;
cout<<bitset<const_length>(number); ex- cout<<bitset<10>(128) 0010000000

10. It is stated that the number of subsequences in which the i-th bit enters an odd number of times is equal to 2^(n-1). 

11. It is easy to prove if (a^b gives  minimum xor ) then no 'c' exits such that a<c<b in the subarray.Basically minimum xor among all pairs in array occurs on consecutive elements. So sort tha array and take mimimum among all consecutive pairs.

12.  (a & b ) ^ ( a | b )  is same as a^b.

13. It is stated that the number of subsequences in which the i-th bit enters an odd number of times is equal to (1<<(n-1))....n is array size. CF : 1614-C

14.'x|y - y' is same as 'x-(x&y)'. (x+y-(x&y)) is same as (x|y).
 
      

