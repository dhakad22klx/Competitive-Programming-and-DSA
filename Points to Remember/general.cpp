1.isdigit() function in C/C++
Header File:

#include <ctype.h>
Syntax:

std::isdigit(int arg)

Return type: This function returns an integer value on the basis of the argument passed to it, if the argument is a numeric character then it returns a non-zero value(true value), otherwise it returns zero(false value).



2. FOR SET : set count() function in C++ STL
The set::count() is a built-in function in C++ STL which returns the number of times an element occurs in the set. It can only return 1 or 0 as the set container contains unique elements only. 
Syntax: 

set_name.count(element).
O(log(n)) time complexity.
3. General : std::count() in C++ STL
std::count() returns number of occurrences of an element in a given range. Returns the number of elements in the range [first,last) that compare equal to val.
vector :     vector<int> vect{ 3, 2, 1, 3, 3, 5, 3 };
    cout << "Number of times 3 appears : "
         << count(vect.begin(), vect.end(), 3);

array :     int arr[] = { 3, 2, 1, 3, 3, 5, 3 };
            int n = sizeof(arr) / sizeof(arr[0]);
            cout << "Number of times 3 appears : "
            << count(arr, arr + n, 3);

string :     string str = "geeksforgeeks";
            cout << "Number of times 'e' appears : " 
            << count(str.begin(), str.end(), 'e');
            
4. If we need to map same element for different value prefer to use pair and maniculate accordingly 1614 B codeforces

5. (s[i]-'0'-64)  wont work to convert uppercase (A-1,B-2 etc) if s[i] is not a digit , because s[i]-'0' converts character '0' to '9' to int
for upper case letter use s[i]-'A';

6.find function : 1)in case of stl container map,set,stack  -syntax : auto it = set_name.find(element) // returns an iterator 
                  2) in case of array- vector auto it = std::find (v.begin(), v.end(), x);// return iterator 
                                              int it =   std:: find(a,a+n,x) // return index of arary
                                              
7. next_permutation(all(v)) ,prev_permutation(all(v)) // true : if the function could rearrange  the object as a lexicographically greater permutation and vice versa.

8. is_sorted(all(v)) return true if sorted else return false;

9. in case of memory limits -consider contraints sharply

10. for map , use "(m.find(key) !=m.end())" instead of "m[key]!=0" becuase m[key] initializes key to value=0; memory limit exit with incrase in map size;
11. When ever we compare some differce = k*x; //remember x should be non zero 382 C

12. Iterating set gives TLE is more slow than vector ..codeforces 986 A.
13. When calling comparator function in leetcode use static bool ,
 comment from someone -" make the "Compare" function as static, as sort() function takes static function pointer as an argument ".
14. we can use  bound on set<pair<ll,ll>> with respect to first element.Example below : 
    set<pair<ll,ll>> s; s.insert({5,6}); s.insert({5,5}); s.insert({5,4}); s.insert({5,3}); s.insert({5,2});
    auto it=s.lower_bound({5,0});cout<<(*it).second;
    //it will output '2'.
15. Comparator function 
    set : https://stackoverflow.com/questions/2620862/using-custom-stdset-comparator 
    or https://www.geeksforgeeks.org/how-to-declare-comparator-for-set-of-pair-in-cpp/
    call - "cmp"
    example :
    bool cmp(int a, int b) {
    return ...;
    }
    set<int, decltype(&cmp)> s(&cmp);
    
    Priority Queue< : https://www.geeksforgeeks.org/custom-comparator-in-priority_queue-in-cpp-stl/
    
    call - "Compare"

    class Compare {
    public:
    bool operator()(DT a,DT b)
    {
         return .....;
    }
};
16. When dealing at border cases 2D vector with long long might give errors,use int in that case.//CSES Dynamic Programming coin combinations II 
17. Some time integer overflow may give wrong ans.//https://codeforces.com/contest/614/problem/A
18. When deadling with large range 1e9 and points are limited 1e5 ,then we should compress range to coordinates.
19. lower bound in vector<pair<ll,ll>> v :-
    ll idx = lower_bound(all(v),{a,b}) - v.begin() ;//will throw error 
    pair<ll,ll> p ={a,b};
    ll idx = lower_bound(all(v),p) - v.begin() ; // will run fine 
20. If vector of length n , we need subsequence such that sum of element is divisible by m.Then for n>m answer is always true.
    (if we take prefix sum % m then maximum m distinct element can be there.So,atleast (n-m) repeated.That is somewhere sum % m == 0.
    
21.  Then parity of inversion count of the resulting permutation will change if you applied odd number of swaps.

22. There is a fact that the distance between adjacent prime numbers isn't big. For n = 1e9 maximal distanse is 282.








