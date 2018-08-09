class Solution{
public:
    int FirstNotRepeatingChar(const string &str){
        int *pos = new int[52]();
        for(int i = 0; i < 52; ++i)
            pos[i] = -1;
        for(int i = 0; i < str.length(); ++i){
            if(pos[GetPos(str[i])] == -1)
                pos[GetPos(str[i])] = i;
            else
                pos[GetPos(str[i])] = -2;
        }
        int MinPos = str.length();
        for(int i = 0; i < 52; ++i){
            if(pos[i] != -1 && pos[i] != -2 && pos[i] < MinPos)
                MinPos = pos[i];
        }
        if(MinPos == str.length())
            MinPos = -1;
        delete[] pos;
        return MinPos;
    }
    int GetPos(char ch){
        if(ch >= 'a' && ch <= 'z')
            return ch - 'a';
        else if(ch >= 'A' && ch <= 'Z')
            return 26 + ch - 'A';
        return -1;
    }
};

/*
int main(){
    Solution a;
    cout << a.FirstNotRepeatingChar(string("google"));
}
*/
