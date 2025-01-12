class Solution {

    string get(int &num,int cnt){
        if(cnt==4){
            int count=num/1000;
            num-=(count*1000);
            return string(count,'M');
        }
        else if(cnt==3 && num>=500){  
            num-=500;
            return "D";
        }
        else if(cnt==3 && num<500){
            int count=num/100;
            num-=(count*100);
            return string(count,'C');
        }
        else if(cnt==2 && num>=50){
            num-=50;
            return "L";
        }
        else if(cnt==2 && num<50){
            int count=num/10;
            num-=count*10;
            return string(count,'X');
        }   
        else if(cnt==1 && num>=5){
            num-=5;
            return "V";
        }
        int copy=num;
        num=0;
        return string(copy,'I');
    }
    string get_fo(int &num,int cnt,int number){
        if(cnt==1){
            num=0;
            return (number==4) ? "IV" : "IX";
        } 
        else if(cnt==2){
            num=(number==4) ? (num-40) : (num-90);
            return (number==4) ? "XL" : "XC" ;
        } 
        num=(number==4) ? (num-400): (num-900);
        return (number==4) ? "CD" : "CM" ;
    }

public:
    string intToRoman(int num) {
        string ans="";
        while(num){
            int cnt=0,copy=num,number=0;
            while(copy){
                cnt++;
                number=copy;
                copy/=10;
            }
            if(number==4 || number==9)  ans+=get_fo(num,cnt,number);
            else    ans+=get(num,cnt);
        }
        return ans;
    }
};