#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    int numberOfBeams(vector<string>& bank){
        int prevCount=0;
        int totalBeams=0;

        for(const string& row: bank){
            //Count devices ('1's) in current row
            int currentCount=0;
            for (char c: row){
                if (c=='1'){
                    currentCount++;
                }
            }

            //If current row has devices
            if (currentCount>0){
                //If there was a previous non-empty row, add beams
                if (prevCount>0){
                    totalBeams+=prevCount*currentCount;
                }
                //Update previous count
                prevCount=currentCount;
            }
        }
        return totalBeams;
    }
};

/*
**Key points**

1. Single pass: We iterate through each row once- O(m.n) time
2. Constant space: Only track `prevCount` and `totalBeams`- O(1) extra space
3. Skip empty rows: ROws with 0 devces are naturally ignored (they don't update `prevCount`)
4. Accumulate products: Each pair of consecutive non-empty rows contributes `prevCount x currentCount` beams
*/

int main(){
    Solution solution;

    //Text case 1
    vector<string> bank1={"011001", "000000", "010100", "001000"};
    cout<<"Test 1:"<<solution.numberOfBeams(bank1)<<" (Expected: 8)"<<endl;

    //Test case 2
    vector<string> bank2={"000", "111", "000"};
    cout<<"Test 2:"<<solution.numberOfBeams(bank2)<<" (Expected: 0)"<<endl;

    //Test case 3
    vector<string> bank3={"111", "111"};
    cout<<"Test 3:"<<solution.numberOfBeams(bank3)<<" (Expected: 9)"<<endl;

    //Test case 4
    vector<string> bank4={"10", "01", "11"};
    cout<<"Test 4:"<<solution.numberOfBeams(bank4)<<" (Expected: 3)"<<endl;

    return 0;
}