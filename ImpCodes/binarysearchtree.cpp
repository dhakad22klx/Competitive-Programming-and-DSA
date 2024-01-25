

//1st 
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







///2nd 


// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 

#include<iostream>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
    int data; 
    BstNode* left;
    BstNode* right;
};

// Function to create a new Node in heap

BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {
    if(root == NULL) { // empty tree
        root = GetNewNode(data);
    }
    // if data to be inserted is lesser, insert in left subtree. 
    else if(data <= root->data) {
        root->left = Insert(root->left,data);
    }
    // else, insert in right subtree. 
    else {
        root->right = Insert(root->right,data);
    }
    return root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
    if(root == NULL) {
        return false;
    }
    else if(root->data == data) {
        return true;
    }
    else if(data <= root->data) {
        return Search(root->left,data);
    }
    else {
        return Search(root->right,data);
    }
}
int main() {
    BstNode* root = NULL;  // Creating an empty tree
    /*Code to test the logic*/
    root = Insert(root,15); 
    root = Insert(root,10); 
    root = Insert(root,20);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    // Ask user to enter a number.  
    int number;
    cout<<"Enter number be searched\n";
    cin>>number;
    //If number is found, print "FOUND"
    if(Search(root,number) == true) cout<<"Found\n";
    else cout<<"Not Found\n";
}



///3rd 

/* C++ program to find Inorder successor in a BST */
#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

//Function to find some data in the tree
Node* Find(Node*root, int data) {
    if(root == NULL) return NULL;
    else if(root->data == data) return root;
    else if(root->data < data) return Find(root->right,data);
    else return Find(root->left,data);
}

//Function to find Node with minimum value in a BST
struct Node* FindMin(struct Node* root) {
    if(root == NULL) return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}

//Function to find Inorder Successor in a BST
struct Node* Getsuccessor(struct Node* root,int data) {
    // Search the Node - O(h)
    struct Node* current = Find(root,data);
    if(current == NULL) return NULL;
    if(current->right != NULL) {  //Case 1: Node has right subtree
        return FindMin(current->right); // O(h)
    }
    else {   //Case 2: No right subtree  - O(h)
        struct Node* successor = NULL;
        struct Node* ancestor = root;
        while(ancestor != current) {
            if(current->data < ancestor->data) {
                successor = ancestor; // so far this is the deepest node for which current node is in left
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}
 
//Function to visit nodes in Inorder
void Inorder(Node *root) {
    if(root == NULL) return;
 
    Inorder(root->left);       //Visit left subtree
    printf("%d ",root->data);  //Print data
    Inorder(root->right);      // Visit right subtree
}
 
// Function to Insert Node in a Binary Search Tree

Node* Insert(Node *root,char data) {
    if(root == NULL) {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data <= root->data)
        root->left = Insert(root->left,data);
    else 
        root->right = Insert(root->right,data);
    return root;
}
 
int main() 
{
    /*Code To Test the logic
      Creating an example tree
                        5
               / \
              3   10
             / \   \
            1   4   11
    */
    Node* root = NULL;
    root = Insert(root,5); root = Insert(root,10);
    root = Insert(root,3); root = Insert(root,4); 
    root = Insert(root,1); root = Insert(root,11);

    //Print Nodes in Inorder

    cout<<"Inorder Traversal: ";

    Inorder(root);

    cout<<"\n";

    // Find Inorder successor of some node. 
    struct Node* successor = Getsuccessor(root,1);
    if(successor == NULL) cout<<"No successor Found\n";
    else
    cout<<"Successor is "<<successor->data<<"\n";
}
