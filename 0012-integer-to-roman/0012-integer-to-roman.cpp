class Solution {

    string get(int &num,int cnt){
        if(cnt==4){
            int copy=num;
            num-=(num-(num%1000));
            return string(((copy-(copy%1000))/1000),'M');
        }
        else if(cnt==3 && num>=500){  
            int copy=num;
            num-=500;
            return "D";
        }
        else if(cnt==3 && num<500){
            int copy=num;
            num-=(num-(num%100));
            return string(((copy-(copy%100))/100),'C');
        }
        else if(cnt==2 && num>=50){
            int copy=num;
            num-=50;
            return "L";
        }
        else if(cnt==2 && num<50){
            int copy=num;
            num-=(num-(num%10));
            return string(((copy-(copy%10))/10),'X');
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
            num= (number==4) ? (num-40) : (num-90);
            return (number==4) ? "XL" : "XC" ;
        } 
        num= ( number==4) ? (num-400): (num-900);
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
            if(number==4 || number==9){
                ans+=get_fo(num,cnt,number);
            }
            else    ans+=get(num,cnt);
        }
        return ans;
    }
};