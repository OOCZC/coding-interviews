class Solution {
public:
    vector<int> multiply(const vector<int> &A) {
        vector<int> B;
        if (A.size() <= 1)
            return B;
        int *C = new int[A.size()];
        int *D = new int[A.size()];
        int product = 1;
        for (int i = 0; i < A.size(); ++i) {
            product *= A[i];
            C[i] = product;
        }
        product = 1;
        for (int i = A.size() - 1; i >= 0; --i) {
            product *= A[i];
            D[i] = product;
        }
        for (int i = 0; i < A.size(); ++i) {
            product = 1;
            if (i - 1 >= 0)
                product *= C[i - 1];
            if (i + 1 < A.size())
                product *= D[i + 1];
            B.push_back(product);
        }
        delete[] C;
        delete[] D;
        return B;
    }
};
