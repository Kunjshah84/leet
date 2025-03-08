class Solution {

    void get(int num1,int bitcnt,int &num2cnt,int &ans){
        if(!num1)   return ;
        else if(num1==1){
            if(num2cnt)    ans+=(1<<bitcnt);
            num2cnt--;
            return ;
        }
        int bit=num1%2;
        get(num1/2,bitcnt+1,num2cnt,ans);
        if(bit && num2cnt){
            ans+=(1<<bitcnt);
            num2cnt--;
        } 
    }

    void get2(int &ans,int num1,int bitcnt,int &num2cnt){
        if(!num1 || num2cnt==0)   return ;
        if(num1%2==0 && num2cnt>0){
            cout<<bitcnt<<endl;
            ans+=(1<<bitcnt);
            num2cnt--;
        }
        get2(ans,num1/2,bitcnt+1,num2cnt);
    }

public:
    int minimizeXor(int num1, int num2) {
        int num1cnt=__builtin_popcount(num1);
        int num2cnt=__builtin_popcount(num2);
        if(num1cnt==num2cnt)  return num1;
        int ans=0;
        get(num1,0,num2cnt,ans);
        if(num2cnt) get2(ans,num1,0,num2cnt);
        if(num2cnt) ans=(1<<(num2cnt+__builtin_popcount(ans)))-1;
        return ans;
    }
};