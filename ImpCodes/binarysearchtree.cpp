
#include <iostream>
#include <queue>
using namespace std;
vector<int> v;
class Node 
{
    public :

    int data;
    Node* left;
    Node* right;

    // Node(int value) : data(value), left(NULL), right(NULL) {}
    Node(int value)
    {
        data=(value), left=(NULL), right=(NULL);
    }
};

class BinarySearchTree 
{
    private:

    Node* root;

    Node* insertRecursive(Node* root, int value) 
    {
        if (root == nullptr) 
        {
            return new Node(value);
        }

        if (value <= root->data) 
        {
            root->left = insertRecursive(root->left, value);
        } 
        else 
        {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    void printLeftViewUtil(Node* root, int level, int& maxLevel) 
    {
        if (root == nullptr) 
        {
            return;
        }

        if (level > maxLevel) 
        {
            v.push_back(root->data);
            maxLevel = level;
        }

        printLeftViewUtil(root->left, level + 1, maxLevel);
        printLeftViewUtil(root->right, level + 1, maxLevel);
    }

    public:
        
    BinarySearchTree() {root=nullptr;}
    // BinarySearchTree() {root(nullptr);}

    void insert(int value) 
    {
        root = insertRecursive(root, value);
    }

    void printLeftView() 
    {
        int maxLevel = -1;
        printLeftViewUtil(root, 0, maxLevel);
    }
};

bool isPalindrome(const std::vector<int>& nums) 
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) 
    {
        if (nums[left] != nums[right]) 
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
}
int main() 
{
    BinarySearchTree bst;
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
    bst.insert(a);
    }
    
    bst.printLeftView();
    if(isPalindrome(v))
    {
        for(auto i:v){cout<<i<<" ";}
        return 0;
    }
    cout<<"NOT PALINDROME"<<endl;
    return 0;
}
