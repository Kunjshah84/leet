class Solution {

    string helper(string str,int k,string ans){
        int n=str.size();
        if(n==1){
            ans+=str;
            return ans;
        }
        int fact=1;
        for(int i=2;i<n;i++)
            fact*=i;
        int ind=k/fact;
        if(k%fact==0)
            ind--;
        char ch=str[ind];
        str=str.substr(0,ind)+str.substr(ind+1);
        if(k%fact==0)
            k=fact;
        else
            k=k%fact;
        return helper(str,k,ans+ch);
    }

public:
    string getPermutation(int n, int k) {
        string str="";
        int fact=1;
        for(int i=1;i<=n;i++){
            str+=to_string(i);
            fact+=i;
        }
        return helper(str,k,""); 
    }
};