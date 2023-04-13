//Something We Need To Study 
 Two pointer algorithm 








// Points to be keep in mind
1.Inbuit Algorithms used by sort()(STL)
The algorithm used by sort() is IntroSort. Introsort being a hybrid sorting algorithm uses three sorting algorithm to minimize the running time, Quicksort, Heapsort and Insertion Sort. Simply putting, it is the best sorting algorithm around. It is a hybrid sorting algorithm, which means that it uses more than one sorting algorithms as a routine

2.use stoll instead of stoi if we get out of range error.
also Adding number to INT_MAX gives overflow error and vice versa 

3. for binary search think ans analize  for condition inside while loop perfecly 
string s1 = s.substr(s.begin(),s.begin()+2)  // wrong 
string s1 = s.substr(0,2)  //correct 

    // Deletes all characters
    str.erase();

    // Deletes all characters except first one
    str.erase(1);

    // Deletes 4 characters from index number 1
    str.erase(1, 4);
    
    // Deletes character at position 4
    str.erase(str.begin() + 4);

    // Deletes all characters between 0th index and
    // str.end() - 6
    str.erase(str.begin() + 0, str.end() - 6); 
4. set<int, greater<int>> - now lower_bound will give immediate '<=' value ,insted   >= , also changes for upper_bound ,basilly allocation order is reversed .

5.  
//General theory 
int v1 = * max_element(X.begin(), X.end()); // Returns value of max element in vector
int i1 = min_element(X.begin(), X.end())– X.begin(); // Returns index of min element in vector
int v2 = * max_element(data, data + 5); // Returns value of max element in array
int i3 = min_element(data, data + 5)– data; // Returns index of min element in array

