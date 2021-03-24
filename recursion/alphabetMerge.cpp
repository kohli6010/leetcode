#include <iostream>
#include <string>
using namespace std;

string alphabeticMerge(string one, string two) {
     if(one[0]=='\0')
     {
       if(two[0]=='\0'){
         
         return one;
       }
       return two;
     }
  
     else if (two[0]=='\0')
       return one;
   
     else if(one[0] > two[0])
          return two[0] + alphabeticMerge(one,two.substr(1));
  
     return one[0] + alphabeticMerge(one.substr(1), two);
       
   }

int main(){

  string one="abxz";
  string two="cdef";
  string answer=alphabeticMerge(one,two);
  cout<<answer<<endl;
}