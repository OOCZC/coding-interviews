class Solution{
public:
    int GetUglyNumber_Solution(int index){
        if(index < 1)
            return 0;
        int *UglyNum = new int[index]();
        UglyNum[0] = 1;
        int CurrIndex = 0;
        int multiple_2 = 0, multiple_3 = 0, multiple_5 = 0;
        while(CurrIndex + 1 < index){
            while(UglyNum[multiple_2] * 2 <= UglyNum[CurrIndex] && multiple_2 < index)
                multiple_2 ++;
            while(UglyNum[multiple_3] * 3 <= UglyNum[CurrIndex] && multiple_3 < index)
                multiple_3 ++;
            while(UglyNum[multiple_5] * 5 <= UglyNum[CurrIndex] && multiple_5 < index)
                multiple_5 ++;
            int MinValue = min(UglyNum[multiple_2] * 2,
                               UglyNum[multiple_3] * 3, UglyNum[multiple_5] * 5);
            UglyNum[++CurrIndex] = MinValue;
        }
        int returnValue = UglyNum[index - 1];
        delete[] UglyNum;
        return returnValue;
    }
    int min(int a, int b, int c){
        return a < b? (a < c? a:c):(b < c? b:c);
    }
};
