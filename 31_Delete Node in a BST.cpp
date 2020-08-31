/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool isLeaf(TreeNode * root){
    return ((root->left == NULL) && (root->right==NULL));
}

int findMaxInLeftSubTree(TreeNode * root){
    while(root->right){
        root=root->right;
    }
    return root->val;
}

TreeNode * deletehelp(TreeNode * root,int key){
    if(!root){
        return root;
    }
    if(root->val==key){
        if(isLeaf(root)){
            return NULL;
        }
        if(root->left && root->right){
            root->val=findMaxInLeftSubTree(root->left);
            root->left=deletehelp(root->left,root->val);
            return root;
        }
        root=(root->left)?root->left:root->right;
        return root;
    }
    
    root->left=deletehelp(root->left,key);
    root->right=deletehelp(root->right,key);
    return root;
}
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deletehelp(root,key);
        // return root;
    }
};
