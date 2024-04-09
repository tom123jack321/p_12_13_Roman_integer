// My solution to LeetCode problem "12. Integer to Roman"
// https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150
// Submited to LeetCode and passed all tests with 3ms runtime (Beats 87.21% of users with C++) and 9.88MB memory (Beats 81.28% of users with C++)

#include <iostream>
#include <vector>

using namespace std;

#include <map>
class Solution {
public:
  string intToRoman(int num) {
    // #mark f#
    static vector<int> v={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static map <int, string> m;
    m[1000]="M"; m[900]="CM"; m[500]="D"; m[400]="CD"; m[100]="C"; 
    m[90]="XC"; m[50]="L"; m[40]="XL"; m[10]="X"; 
    m[9]="IX";  m[5]="V";  m[4]="IV";  m[1]="I";
    auto r=div(num,1000);
    string s="";
    for(int i=0;i<13;i++){
      r=div(num, v[i]);
      if(r.quot>0){
        for(int j=0;j<r.quot;j++){
          s+=m[v[i]];
        }
      }
      num=r.rem;
    }
    // #mark g#
    return s;
  }
};

int main(){
  int num=1994;
  Solution sol;
  string s=sol.intToRoman(num);
  cout << "s " << s << "\n";
}
