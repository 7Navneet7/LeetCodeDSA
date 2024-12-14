#include<math.h>
int reverse(int x){
    int xo=x;int xu=x;
    // if(x>pow(2,31)-1||x<-pow(2,31)){
    //     return 0;
    // }
    if(x<0){
        xu*=-1;
    }
    long so=1/10;
    while(xu>0){
        long nu=xu%10;
        so=so*10+nu;
        xu=xu/10;
    }
    if(so>INT_MAX||so<INT_MIN){
        return 0;
    }
    if(x<0){
        return -1*so;
    }
    return so;
}