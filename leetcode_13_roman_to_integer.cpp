// My solution to LeetCode problem "13. Roman to Integer"
// https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150
// Submited to LeetCode and passed all tests with 0ms runtime (Beats 100.00% of users with C++) and 10.7MB memory (Beats 73.96% users with C++)

#include <iostream>
#include <vector>

using namespace std;

#include <map>
class Solution {
public:
  int romanToInt(string s) {
    static map <char, int> m;
    m['I']=1; m['V']=5; m['X']=10; m['L']=50; 
    m['C']=100; m['D']=500; m['M']=1000;
    int sum=0;
    int q=s.size();
    int a=m[s[0]], b;
    // #mark f#
    int i=0;
    while(i<=q-2){
      b=m[s[i+1]];
      if(a>=b){ 
        sum+=a; i++;
        a=b;
      } else { 
        sum+=b-a; i+=2; 
        a=m[s[i]];
      }
    }
    if(i==q-1){ sum+=m[s[i]]; }
    return sum;
  }
};

int main(){
  // string s="MCMXCIV";
  string s="III";
  Solution sol;
  int sum=sol.romanToInt(s);
  cout << "sum " << sum << "\n";
  // #mark w#
}
