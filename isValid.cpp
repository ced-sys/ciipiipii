#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution{
public:
    bool isValid(const string& s){
        if (s.length()<3)
            return false;

        int vowels=0, consonants=0;
        string vowel_set="aeiouAEIOU";

        for (char c: s){
            if (isalpha(c)){
                if (vowel_set.find(c) != string::npos)
                    vowels++;
                else
                    consonants++;
            }

            else if (isdigit(c)){
                //Invalid character (digits are not allowed)
                return false;
            }
        }

        return vowels >= 1 && consonants >=1;
    }
};

//C++ test
int main(){
    Solution sol;

    cout<<std::boolalpha;
    cout<<sol.isValid("abc")<<endl;
    cout<<sol.isValid("ae")<<endl;
    cout<<sol.isValid("b2c")<<endl;
    cout<<sol.isValid("AeX")<<endl;

    return 0;
}