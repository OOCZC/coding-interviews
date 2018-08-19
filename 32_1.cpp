struct elem {
    elem(TreeNode *val, int layer): p(val), layer(layer) {
    }
    TreeNode *p;
    int layer;
};

class Solution {
public:
    vector<vector<int>> Print(TreeNode *pRoot) {
        vector<vector<int>> ans;
        queue<elem> que;
        if (pRoot == nullptr)
            return ans;
        que.push(elem(pRoot, 1));
        while (que.size() > 0) {
            vector<int> layer;
            int layer_num = que.front().layer;
            while (que.front().layer == layer_num) {
                layer.push_back(que.front().p -> val);
                if (que.front().p -> left != nullptr) 
                    que.push(elem(que.front().p -> left, layer_num + 1));
                if (que.front().p -> right != nullptr) 
                    que.push(elem(que.front().p -> right, layer_num + 1));
                que.pop();
            }
            ans.push_back(layer);
        }
        return ans;
    }
};
