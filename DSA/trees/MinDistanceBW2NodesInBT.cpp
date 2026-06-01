#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    TreeNode *findLCA(TreeNode *root, int a, int b)
    {
        if (!root)
            return NULL;
        if (root->val == a || root->val == b)
            return root;
        TreeNode *left = findLCA(root->left, a, b);
        TreeNode *right = findLCA(root->right, a, b);
        if (left && right)
            return root;
        return left == NULL ? right : left;
    }
    int findLevel(TreeNode *root, int x, int level)
    {
        if (!root)
            return -1;
        if (root->val == x)
            return level;
        int l = findLevel(root->left, x, level + 1);
        if (l != -1)
            return l;
        return findLevel(root->right, x, level + 1);
    }
    int findDist(TreeNode *root, int a, int b)
    {
        TreeNode *lca = findLCA(root, a, b);
        int d1 = findLevel(lca, a, 0);
        int d2 = findLevel(lca, b, 0);
        return d1 + d2;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << "distance -- " << sol.findDist(root, 4, 7);
    return 0;
}