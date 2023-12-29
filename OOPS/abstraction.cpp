Abstraction 


https://www.geeksforgeeks.org/abstraction-in-cpp/?ref=lbp


https://www.codingninjas.com/studio/guided-paths/basics-of-c/content/118817/offering/1382257?leftPanelTab=0&leftPanelTabValue=NOTE

#include <iostream>
using namespace std;
class abstraction {
    private:
        int a, b;
    public:
        // method to set values of private members 
        void set(int x, int y) {
            a = x;
            b = y;
        }
    void display() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
};
int main() {
    abstraction obj;
    obj.set(10, 20);
    obj.display();
    return 0;
}
Output:
a = 10
b = 20


Advantages Of Abstraction
Only you can make changes to your data or function, and no one else can.
It makes the application secure by not allowing anyone else to see the background details.
Increases the reusability of the code.
Avoids duplication of your code.
