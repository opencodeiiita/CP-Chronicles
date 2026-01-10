/*
Problem:
theres two arrays A and B with same length. at each position we can choose value from either array and we need to count how many subarrays can form strictly increasing sequence by choosing values smartly.

Approach:
okay so first i realized at each position theres a smaller value and bigger value between the two arrays right. so i stored those separately as small and big arrays. now the main trick i used is binary lifting - basically instead of checking position by position i precompute what happens if i jump ahead by powers of 2 like 1, 2, 4, 8 positions etc. 

for each starting position and each power i store two things - what value ill end up with if i start below the small value vs if i start between small and big value. also track whether that jump is even valid or not.

then when finding answer from each start point i greedily pick the biggest jumps i can take. like first try jumping 16 positions if valid then 8 then 4 and so on. this way i quickly find how far i can extend from each starting point without checking every single element again.

Time Complexity:
O(n log n)

Space Complexity:
O(n log n)

Example:
Input:
1
3
1 2 3
2 3 4

Output:
6

Submission Link:
https://www.codechef.com/viewsolution/1223592978
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int chee;
    cin>>chee;
    
    while(chee--)
    {
        int wang;
        cin>>wang;
        
        vector<int> lee(wang);
        vector<int> mang(wang);
        
        for(int i=0;i<wang;i++)
        {
            cin>>lee[i];
        }
        
        for(int i=0;i<wang;i++)
        {
            cin>>mang[i];
        }
        
        vector<int> small(wang);
        vector<int> big(wang);
        
        for(int i=0;i<wang;i++)
        {
            if(lee[i]<mang[i])
            {
                small[i]=lee[i];
                big[i]=mang[i];
            }
            else
            {
                small[i]=mang[i];
                big[i]=lee[i];
            }
        }
        
        int maxlog=1;
        while((1<<maxlog)<=wang)
        {
            maxlog++;
        }
        
        vector<vector<int>> resSmall(maxlog,vector<int>(wang,0));
        vector<vector<int>> resBig(maxlog,vector<int>(wang,0));
        vector<vector<uint8_t>> validSmall(maxlog,vector<uint8_t>(wang,0));
        vector<vector<uint8_t>> validBig(maxlog,vector<uint8_t>(wang,0));
        
        for(int pos=0;pos<wang;pos++)
        {
            resSmall[0][pos]=small[pos];
            resBig[0][pos]=big[pos];
            validSmall[0][pos]=1;
            validBig[0][pos]=1;
        }
        
        for(int power=1;power<maxlog;power++)
        {
            int jump=1<<(power-1);
            
            for(int start=0;start<wang;start++)
            {
                int next=start+jump;
                
                if(next>=wang)
                {
                    validSmall[power][start]=0;
                    validBig[power][start]=0;
                    continue;
                }
                
                if(!validSmall[power-1][start])
                {
                    validSmall[power][start]=0;
                }
                else
                {
                    int curr=resSmall[power-1][start];
                    
                    if(curr<small[next])
                    {
                        validSmall[power][start]=validSmall[power-1][next];
                        if(validSmall[power][start])
                        {
                            resSmall[power][start]=resSmall[power-1][next];
                        }
                    }
                    else if(curr<big[next])
                    {
                        validSmall[power][start]=validBig[power-1][next];
                        if(validSmall[power][start])
                        {
                            resSmall[power][start]=resBig[power-1][next];
                        }
                    }
                    else
                    {
                        validSmall[power][start]=0;
                    }
                }
                
                if(!validBig[power-1][start])
                {
                    validBig[power][start]=0;
                }
                else
                {
                    int curr=resBig[power-1][start];
                    
                    if(curr<small[next])
                    {
                        validBig[power][start]=validSmall[power-1][next];
                        if(validBig[power][start])
                        {
                            resBig[power][start]=resSmall[power-1][next];
                        }
                    }
                    else if(curr<big[next])
                    {
                        validBig[power][start]=validBig[power-1][next];
                        if(validBig[power][start])
                        {
                            resBig[power][start]=resBig[power-1][next];
                        }
                    }
                    else
                    {
                        validBig[power][start]=0;
                    }
                }
            }
        }
        
        long long chang=0;
        
        for(int left=0;left<wang;left++)
        {
            chang+=1;
            
            int threshold=small[left];
            int reach=left+1;
            
            for(int power=maxlog-1;power>=0;power--)
            {
                int blocksize=1<<power;
                
                if(reach+blocksize-1>=wang)
                {
                    continue;
                }
                
                if(threshold<small[reach])
                {
                    if(validSmall[power][reach])
                    {
                        threshold=resSmall[power][reach];
                        reach+=blocksize;
                    }
                }
                else if(threshold<big[reach])
                {
                    if(validBig[power][reach])
                    {
                        threshold=resBig[power][reach];
                        reach+=blocksize;
                    }
                }
            }
            
            chang+=(reach-(left+1));
        }
        
        cout<<chang<<endl;
    }
    
    return 0;
}