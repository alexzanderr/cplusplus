
#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int __value) {
        value = __value;
        left = nullptr;
        right = nullptr;
    }
};

// the height of the tree is given by
// the total number of nodes from root to
// the deepest leaf ((total edges from root to deepest leaf) + 1)
int GetHeightOfTree(BinaryTreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftHeight = GetHeightOfTree(root->left);
        int rightHeight = GetHeightOfTree(root->right);
        
        if (leftHeight > rightHeight) {
            return leftHeight + 1; 
        } else {
            return rightHeight + 1;
        }
    }
}