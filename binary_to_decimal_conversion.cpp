#include<iostream>
using namespace std;
int bintodec(int n){
    int ans=0;
    int pow=1;
    while(n>0){
        int lastdigit=n%10;
        ans+=lastdigit*pow;
        pow=pow*2;
        n=n/10;
    }
    return ans;
}
int main(){
    cout<<bintodec(101);
    return 0;
}