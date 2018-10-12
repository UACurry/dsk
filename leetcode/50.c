double myPow(double x, int n) {
    double ret = 1;
    if (n < 0) {
        x = 1 / x;
        n = -n;
    }
    while (n--) {
        ret *= x;
    }
    return ret;
}