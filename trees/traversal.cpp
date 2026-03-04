#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
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
private:
    void recur(TreeNode *root, vector<int> &ans)
    {
        if (root)
        {
            ans.push_back(root->val);
            recur(root->left, ans);
            recur(root->right, ans);
        }
    }

    int dia(TreeNode *root, int &d)
    {
        if (!root)
            return 0;
        int lh = dia(root->left, d);
        int rh = dia(root->right, d);
        d = max(d, lh + rh);
        return 1 + max(lh, rh);
    }

    int ps(TreeNode *root, int &pathSum)
    {
        if (!root)
            return 0;
        int ls = max(0, ps(root->left, pathSum));
        int rs = max(0, ps(root->right, pathSum));
        pathSum = max(pathSum, root->val + ls + rs);
        return root->val + max(ls, rs);
    }

    void check(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 || !r2)
            return (r1 == r2);
        if (r1->val != r2->val)
            return false;
        return check(r1->left, r2->right) && check(r1->right, r2->left);
    }

    bool isLeaf(TreeNode *root) { return (!root->left && !root->right); }
    void leftTraversal(TreeNode *root, vector<int> &ans)
    {
        TreeNode *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
                ans.push_back(curr->val);
            if (curr->left)
                curr = curr->left;
            if (curr->right)
                curr = curr->right;
        }
    }
    void rightTraversal(TreeNode *root, vector<int> &ans)
    {
        TreeNode *curr = root->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->val);
            if (curr->right)
                curr = curr->right;
            if (curr->left)
                curr = curr->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--)
            ans.push_back(temp[i]);
    }
    void addLeaf(TreeNode *root, vector<int> &ans)
    {
        if (isLeaf(root))
        {
            ans.push_back(root->val);
            return;
        }
        if (root->left)
            addLeaf(root->left, ans);
        if (root->right)
            addLeaf(root->right, ans);
    }

    void recur(TreeNode *root, int level, vector<int> &ans)
    {
        if (root)
        {
            if (ans.size() == level)
                ans.push_back(root->val);
            recur(root->right, level + 1, ans);
            recur(root->left, level + 1, ans);
        }
    }

    void recur(TreeNode *root, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (root)
        {
            ds.push_back(ds->val);
            if (!root->left && !root->right)
                ans.push_back(ds);
            else
            {
                recur(root->left, ds, ans);
                recur(root->right, ds, ans);
            }
            ds.pop_back();
        }
    }

public:
    vector<int> preOrder(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        // recur(root, ans);

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);
        }
        return ans;
    }

    vector<int> inOrder(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (curr || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }

    vector<int> postOrder(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *curr = s1.top();
            s1.pop();
            s2.push(curr);
            if (curr->left)
                s2.push(curr->left);
            if (curr->right)
                s2.push(curr->right);
        }
        while (!s2.empty())
        {
            TreeNode *curr = s2.top();
            s2.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }

    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return 1 + max(l, r);
    }

    int diameterOfBTree(TreeNode *root)
    {
        int d = 0;
        dia(root, d);
        return d;
    }

    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        ps(root, sum);
        return sum == INT_MIN ? 0 : sum;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return check(root->left, root->right);
    }

    vector<int> boundaryTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        if (!isLeaf(root))
            ans.push_back(root->val);
        leftTraversal(root, ans);
        leafTraversal(root, ans);
        rightTraversal(root, ans);
        return ans;
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        // queue -- node, vertical, level
        queue<pair<TreeNode *, pair<int, int>>> q;
        // map -- vertical, level, val
        map<int, map<int, multiset<int>>> mp;

        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            TreeNode *node = curr.first;
            int vertical = curr.second.first, level = curr.second.second;
            mp[vertical][level].insert(node->val);
            if (node->left)
                q.push({node->left, {vertical - 1, level + 1}});
            if (node->right)
                q.push({node->right, {vertical + 1, level + 1}});
        }
        for (auto curr : mp)
        {
            vector<int> col;
            for (auto vertical : curr.second)
                col.insert(col.end(), curr.second.begin(), curr.second.end()); // !!!!!!
            ans.push_back(col);
        }
        return ans;
    }

    vector<int> topView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        // queue -- node, vertical
        queue<map<TreeNode *, int>> q;
        // map -- vertical, val
        map<int, int> mp;
        q.push({root, 0});
        while (!q.empty())
        {
            TreeNode *curr = q.front().first;
            int vertical = q.front().second;
            q.pop();
            if (mp.count(vertical) == 0) // !!!!!!
                mp[vertical] = curr->val;
            if (curr->left)
                q.push({curr->left, vertical - 1});
            if (curr->right)
                q.push({curr->right, vertical + 1})
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }

    vector<int> rightView(TreeNode *root)
    {
        vector<int> ans;
        recur(root, 0, ans);
        return ans;
    }

    vector<vector<int>> allRootToLeaf(TreeNode *root)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        recur(root, ds, ans);
        return ans;
    }

    long long int widthOfBinaryTree(TreeNode *root)
    {
        long long int maxWidth = 0;
        if (!root)
            return maxWidth;
        queue<pair<TreeNode *, long long int>> q;
        q.push({root, 1});
        while (!q.empty())
        {
            int n = q.size(), startIndex, endIndex;
            for (int i = 0; i < n; i++)
            {
                auto &current = q.front();
                q.pop();
                if (i == 0)
                    startIndex = current.second;
                if (i == n - 1)
                    endIndex = current.second;
                if (curr.first->left)
                    q.push({curr.first->left, 2 * current.second - startIndex});
                if (curr.first->right)
                    q.push({curr.first->right, 2 * current.second + 1 - startIndex});
            }
            maxWidth = max(maxWidth, endIndex - startIndex + 1);
        }
        return maxWidth;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (!left && !right)
            return NULL;
        if (!left)
            return right;
        if (!right)
            return left;
        return root;
    }
};