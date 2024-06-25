class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumLeftLeaves(root, false);
    }

private:
    int sumLeftLeaves(TreeNode* node, bool isLeft) {
        if (node == nullptr) {
            return 0;
        }

        if (isLeft && node->left == nullptr && node->right == nullptr) {
            return node->val;
        }

        int leftSum = sumLeftLeaves(node->left, true);
        int rightSum = sumLeftLeaves(node->right, false);

        int totalSum = leftSum + rightSum;
        return totalSum;
    }
};
