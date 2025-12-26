#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for(int j=0;j<t;j++){
        int p,q,r;
        scanf("%d",&p);
        scanf("%d",&q);
        scanf("%d",&r);
        if(p>q){
            int x;
            x=p-q;
            x=x*2;
            if(r > x){
                printf("-1\n");
            }
            else if(x>p||x==p){
                x=x/2;
                if(r<=x){
                    r=r+x;
                    printf("%d\n",r);
                }else{
                    r=r-x;
                    printf("%d\n",r);
                }
            }else{
                printf("-1\n");
            }
        }
        if(q>p){
            int x;
            x=q-p;
            x=x*2;
            if(r > x){
                printf("-1\n");
            }
            else if(x>q||x==q){
                x=x/2;
                if(r<=x){
                    r=r+x;
                    printf("%d\n",r);
                }else{
                    r=r-x;
                    printf("%d\n",r);
                }
            }else{
                printf("-1\n");
            }
        }
        if(p==q){
            printf("-1\n");
        }
    }
    return 0;
}
