public class Solution {

    public double Power(double base, int exponent) {
        
       // int flag = base > 0? 1: -1;
        if (exponent == 1)
            return base;
        else if (exponent % 2 == 1)
            return Power(base, exponent - 1) * base;
        else
            return Power(base * base, exponent >> 1);
    }
}
