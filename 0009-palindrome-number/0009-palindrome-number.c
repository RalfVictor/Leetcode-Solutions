#include<math.h>
bool isPalindrome(int x){
bool f;
if(x<0){
    f=false;
}
else{
int i,b,c;
int sum=0;
int a=0;
b=x;
int d=x;
while(b!=0){
    b/=10;
    a++;
}for(i=0;i<a;i++){
    c=x%10;
    sum = sum+(c*pow(10,(a-i-1)));
    x/=10;
}if(sum==d){
    f=true;
}else{
    f=false;
}
}
return f;}
