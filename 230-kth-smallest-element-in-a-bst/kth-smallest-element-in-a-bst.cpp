class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        int count =0,ans=0;
        inorder(root, ans ,count,k);
        return ans; 
    }

    void inorder(TreeNode* root, int &ans,int &count,int k) {
        if (root == nullptr) {
            return; 
        }
        inorder(root->left, ans,count,k);
        count++;
        if(count== k){
            ans=root->val;
        }
        
        inorder(root->right, ans,count,k);
    }
};