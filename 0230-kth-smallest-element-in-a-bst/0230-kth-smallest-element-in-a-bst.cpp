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
class Solution {
public:
void f(TreeNode* root, int k, int& x, int& nk){
    if(root==NULL){
        return;
    }
    f(root->left,k,x,nk);
    nk++;
    if(nk==k){
        x=root->val;
        return;
    }
    f(root->right,k,x,nk);
}
    int kthSmallest(TreeNode* root, int k) {
        int x=0;
        int nk=0;
        f(root,k,x,nk);
        return x;

        
    }
};