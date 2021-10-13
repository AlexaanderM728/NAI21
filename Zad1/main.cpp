#include <cstdlib>
#include <iostream>
// do make_pair
#include <utility>
int func2(int lc){
    lc = (2*(lc%2)-1)*lc/2;
    return lc;
}
int func1( int arq1){
    arq1 = 20-abs(arq1+1);
    return arq1;
}

int main(){
    auto obliczenia = []( auto  f1 ,   auto f2 , int n ){
        auto max_x = func2(0);
        auto max_y = func1(max_x);
        for (int i = 1; i < n  ; i++)
        {
            auto x = func2(i);
            auto y = func1(x);
            if (y > max_y)
            {
                max_x = x;
                max_y = y;
            }
        }
        auto para = std::make_pair(max_x , max_y);
        std::cout << para.first << " , " << para.second;
        return para;
    };
    obliczenia(6, 7, 8);
}
