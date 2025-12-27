
//Time: O(t)

//Space: O(1)

#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
    cin >> t;
while(t--){
 long long a, b, c;
        cin >>  a >> b >> c;
long long dist=llabs(a - b);
long long n=2*dist;
if(dist==0 || c>n){
cout << -1 << '\n';
continue;
}
long long half=n/2;
if(c+half<=n){
  cout << c+half << '\n';
}
else{
  cout << c-half << '\n';

}
}
 return 0;
}

