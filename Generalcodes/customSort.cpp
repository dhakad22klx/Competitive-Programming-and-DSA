//decalring function itself

#include <iostream>
#include <queue>
#include <vector>
#include <functional>  // For std::greater and std::less

// Custom comparison function (for ascending order)
bool customCompare(int a, int b) {
    return a > b;  // Return true if a should be ordered before b (min-heap)
}

int main() {
    // Priority queue with custom comparison function (min-heap)
    std::priority_queue<int, std::vector<int>, decltype(&customCompare)> pq(customCompare);

    pq.push(10);
    pq.push(20);
    pq.push(5);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}


// declaring class or struct 
#include <iostream>
#include <queue>
#include <vector>

// Custom comparison functor (for ascending order)
struct Compare {
    bool operator()(int a, int b) {
        return a > b;  // Return true if a should be ordered before b (min-heap)
    }
};

int main() {
    // Priority queue with custom comparison functor (min-heap)
    std::priority_queue<int, std::vector<int>, Compare> pq;

    pq.push(10);
    pq.push(20);
    pq.push(5);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}




//Just to understand functor (functional object )

#include <iostream>

class Adder {
public:
    int operator()(int a, int b) {  // Define the behavior of the object when it's called
        return a + b;
    }
};

int main() {
    Adder add;  // Create an instance of the class
    std::cout << add(5, 3) << std::endl;  // Calling the object as a function
    return 0;
}
