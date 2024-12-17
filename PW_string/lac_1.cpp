#include<iostream>
#include<string>
#include<limits>
#include<algorithm>
using namespace std;
int main(){
    char str[]={'a','b','c','d'};
    for(int i=0;i<4;i++)   cout<<str[i];
    char arr[]="abcd";
    cout<<endl<<arr;
    char ch='\\';//We can not directly print the back slash:
    cout<<endl<<ch<<endl;
    ch='\0';//We initialized the ch with the NULL char:
    cout<<ch;//It is going to print nothing:
    cout<<"This is the line after the NULL char:"<<endl;
    char arr2[4]={1,2,3,4};
    cout<<"Printing the NULL char"<<arr[4]<<"Yes printed"<<endl;
    //at the other hand if we print the arr[5]-->it is going to show the error:
    char arr3[10]={'1','2','3','4'};
    cout<<"before"<<(int)arr3[6]<<"After"<<endl;
    //That means the other char accept the last one is going to intialized with the NULL char:
    cout<<"before"<<(int)arr3[10]<<"After"<<endl;
    //it is going to print the garbage value and on each run it may print the different value:
    //It may crash the program;
    //It is totally depands on the compiler:

    //The use of null char at the end of the string;
    //Like when ever we are having the nth numbers of char and don't know the count of the char
    //Then the method to print the all char of the string:
    char arr4[]={'a','b','c','d','e','f'};
    cout<<"before the arr4"<<endl;
    for(int i=0;arr4[i]!='\0';i++)   cout<<arr4[i]<<" ";
    cout<<endl;
    //That means the char array is not going to include implisitly the NULL cahr at the end of the char array;
    //But in the case of the string it will include the NULL char at the end of the string:
    //And to avoid the unpredictible behaviour of we have to initialize our array like this:
    //char arr4[]={'a','b','\0'};
    for(int i=0;arr3[i]!='\0';i++)  cout<<arr3[i]<<" ";
    cout<<endl;
    //see thas why we tell that this is the unpredictable out put:
    char arr5[6]={'a','b','c','\0','d','f'};
    cout<<arr5<<endl;
    cout<<arr5[4]<<endl;
    cout<<arr5[6]<<endl;
    cout<<arr5[7]<<endl;
    cout<<arr5[8]<<endl;
    cout<<arr5[9]<<endl;
    cout<<arr5[10]<<endl;
    cout<<arr5[11]<<endl;
    cout<<arr5[12]<<endl;
    //That shows the unpredictable bwhaviour of the array: and it is not going to show the error:


    //Strings;
    //Taking the input as a string:
    string s;
    cout<<"Thaking the string with space bar:--"<<endl;
    cin>>s;
    //I have take the input as (kunj shah):
    //still It is going to print the kunj only:
    //The reason:
    //The cin works without space :
    //It understoods that if we enter the space that it is the input for the next cin or the end of current cin:
    //How to takel this thing: 
    cout<<s;
    string s2;
    cout<<"Taking the s2 which have the sapce into it:-->"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,s2);
    cout<<s2<<endl;


    //built in function in string:

    //1--->lenght/size function:

    string nstr="Kunj rajeshkumar shah";
    cout<<nstr.size()<< "or" << nstr.length()<<endl;

    //2---> push_back() function;

    string pushb="kunj";
    // pushb.push_back(' ' + 'r');--->this will show the undefine behavior of the function:
    pushb.push_back(' ');
    pushb.push_back('r');
    //We can not append multiple cahr at the end of the string:

    //3--->Pop_back() function:
    pushb.pop_back();
    cout<<pushb<<endl;


    //4---> +operator:
    
    string a="bcd";
    a= 'a' + a;
    cout<<a<<endl;
    //This operator is used to append of attach the char/string to the current string:
    a+='e';
    a+="fg";
    cout<<a<<endl;

    //We can't do like this:
    // a= a+ (any thing accept the char or string:)


    //5---> reverse() function:->

    string b="knuj r shah/shah kunj rajeshkumar";
    reverse(b.begin(),b.end());
    cout<<b<<endl;
    string c="abcdef";
    reverse(c.begin()+2,c.end()-1); //It will reverse only the char with index 2 to c.size()-2:
    cout<<c<<endl;

    //6--->substr() function:substring function:
    string d="abcdefgh";
    cout<<"Now the name of the string is d"<<d<<endl;
    cout<<d.substr(0)<<endl;
    cout<<d.substr(1)<<endl;
    cout<<d.substr(2)<<endl;
    //Now multiple arg() in the substr function:
    cout<<d.substr(1,3)<<endl;//1 thi lai ne 3 length sudhini nikadshe:
    cout<<d.substr(2,2)<<endl;//2 thi lai ne 2 length sudhni nikadshe:
    cout<<d.substr(7,3)<<endl;//jo end avi gayo to ubhi rahehshe:
    // cout<<s.substr(8,3)<<endl;// run time error:


    //7---> to_string():

    int n=12345;
    //We can't do directly type casting like this string g=(stirng)n;
    string e=to_string(n);
    cout<<e<<endl;
    return 0;
}