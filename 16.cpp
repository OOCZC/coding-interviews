double Power(double base, int exponent){
    if(base == 0)
        return 0;
    if(exponent == 0)
        return 1;
    int unsignedExponent = exponent > 0? exponent: -exponent;
    int ans = 1;
    for(int i = 0; i < unsignedExponent; ++i){
        ans *= base;
    }
    if(exponent > 0)
        return ans;
    else
        return 1.0 / ans;
}
