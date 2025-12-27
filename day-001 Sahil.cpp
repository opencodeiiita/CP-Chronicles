#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b,c,N;
    cout<<"Enter the value of a,b,c : ";
    cin>>a>>b>>c;

    N = 2* abs(a-b); //circle ka size kyuki a or b aamne samne h toh toh unke bich m aadhe element hi honge circle ke toh unka double sare element honge!

    //N need to be even and non zero if not even no condition will we followed

    if(N%2==0 && N!=0 && c<=N){
        //c N se choti hi honi chahiye
        
        // c ke opposite wala num bhi N/2 dur hi hona chahiye kyuki even h toh symmetry follow hogi!
        //cout<<"opposite of c is "<<c+N/2<<endl;
        
        // ab agr input a=1,b=3,c=4 kr rhe h toh output 6 aarha h jb ki N toh 4 hi h  or output 2 aana chahiye jo ki ' c - N/2 ' 

        //toh fir kuch case or bnenge!!
        if(c+N/2>=N){
            cout<<"opposite of c is "<<c-N/2<<endl;
        } else{
            cout<<"opposite of c is "<<c+N/2<<endl;
        }
    }

    else{
        cout<<"-1\n";
    }
   return 0;
}
