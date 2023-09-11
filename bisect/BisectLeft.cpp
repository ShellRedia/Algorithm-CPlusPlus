#include <iostream>

typedef long long ll;

struct BisectLeft{
    bool (*check)(ll);
    BisectLeft(bool (*check)(ll)):check(check){}
    ll bisect_left(ll left, ll right){
        while(left < right){
            ll mid = (left + right + 1) >> 1;
            if(!check(mid)) left = mid;
            else right = mid-1;
        }
        return left + 1;
    }
};
