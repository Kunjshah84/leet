#include<iostream>
#include<stack>
#include<string>
using namespace std;

//Here is the difference between prefix and infix operation:
//infix:v1 operator v2
//prefix:operator v1 v2
//posrfix:v1 v2 operator 

//This is the simple example that shows how we can convert the infix operation to prefix operationl;
//2+6---. + 2 6


//Now we have to convert this string into prefix:
//2+6*4/8-3 --->Infix:
//convert a small sub string according to the oprder of presidene into prefix string:
//now step 2 we got the step one is---> 2+*6 4/8-3
//And now we treat the *6 4 as a seperate entity:

//Now step 2 :2 + /* 6 4 8-3

//Now step 3 :+ 2 /* 6 4 8 - 3 
//Now step 4 : - + 2 /* 6 4 8 3--->At the end we have converted the infix to the post fix;
//Now computer able to solve the prefix exp;


//                             WHY computer converts infix to post of pre?

//pre fix eleminates the need of the peranthisis and it also does not need the presidence table to evaluate the exp
//Another reason is time and code complexity:
//Pre solve the exp into only O(n) time complexity:


int main(){

    return 0;
}