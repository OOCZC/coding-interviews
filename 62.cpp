class Solution {
public:
    // 约瑟夫环，n个节点，每m个删一次。
    int LastRemaining_Solution(int n, int m) {
        if (n < 1 || m < 1)
            return -1;
        list<int> l;
        for (int i = 0; i < n; ++i) {
            l.push_back(i);
        }
        list<int>::iterator iter = l.begin();
        int m_temp;
        while (l.size() > 1) {
            m_temp = m;
            while (-- m_temp) {
                ++ iter;
                if (iter == l.end())
                    iter = l.begin();
            }
            iter = l.erase(iter);
            if (iter == l.end())
                iter = l.begin();
        }
        return *l.begin();
    }
};
