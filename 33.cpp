bool IsSequenceOfBST(vector<int> sequence){
    if(sequence.size() == 0)
        return false;  // 样例规定空时返回false
    bool flag = true;
    int root = sequence[sequence.size() - 1];
    int i = 0, temp_i;
    for(; i < sequence.size() - 1; ++i)
        if(sequence[i] >= root)
            break;

    temp_i = i;
    if(i != 0){
        vector<int> seq1(sequence.begin(), sequence.begin() + i);
        flag = IsSequenceOfBST(seq1);
    }
    for(; i < sequence.size() - 1; ++i)
        if(sequence[i] <= root)
            break;

    if(i != sequence.size() - 1)
        return false;
    if(i != temp_i){
        vector<int> seq2(sequence.begin() + temp_i, sequence.begin() + i);
        flag = flag && IsSequenceOfBST(seq2);
    }
    return flag;
}
