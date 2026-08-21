#include<iostream>
using namespace std;
int dectobin(int n){
    int ans=0;
    int remainder=0;
    int pow=1;
    while(n>0){
        remainder=n%2;
        ans+=remainder*pow;
        n=n/2;
        pow*=10;
    }
    return ans;
}
int main(){
    cout<<dectobin(20);
    return 0;
}