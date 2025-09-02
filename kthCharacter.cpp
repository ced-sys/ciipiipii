#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    //Function to find the k-th charcter in the generated string
    string kthCharacter(int k){
        string sb="a"; //Start with the inital character 'a'

        //Generate characters until the string length reaches at least k
        while (sb.length()<k){
            int size=sb.length(); //Capture current size of the string

            //For each character in the current string, generate the next character
            for (int i=0; i<size; ++i){
                //Compute the next character by shifting +1 in the alphabet with wrap-aound using %26
                char next_char='a'+((sb[i]-'a'+1)%26);
                sb+=next_char; //Append to the growing string
            }
        }

        //Return the k-th character (0 based index adjustment)
        return string(1, sb[k-1]);
    }
};

int main(){
    Solution sol;
    int k=5;
    cout<<"The "<<k<<"-th character is:"<<sol.kthCharacter(k)<<endl;
    return 0;
}