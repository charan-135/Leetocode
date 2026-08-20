/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_order;
        queue<TreeNode*> q;
        if (root == NULL) {
            return level_order;
        }

        q.push(root);

        while (q.empty() == 0) {

            int size = q.size();
            vector<int> levels;

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left != nullptr) {
                    q.push(temp->left);
                }

                if (temp->right != nullptr) {
                    q.push(temp->right);
                }

                levels.push_back(temp->val);
            }

            level_order.push_back(levels);
        }
        return level_order;
    }
};