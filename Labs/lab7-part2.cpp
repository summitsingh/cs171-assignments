#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if(b==0){
        return a;
    }
    else{
        return (gcd(b, a%b));
    }
    
}

int main (int argc, char * argv [])
{
    
    int numerator, denominator;
    cout<<"Enter numerator: ";
    cin>>numerator;
    cout<<"Enter denominator: ";
    cin>>denominator;
    int g = gcd(numerator, denominator);
    cout<<(numerator/g)<<"/"<<(denominator/g)<< endl;
    
}
