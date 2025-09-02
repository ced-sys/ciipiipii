#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int countGoodArrays(int n, int m, int k){
        const int MOD=1e9+7;
        int d =n-1; //Number of adjacent pairs

        if (k>d) return 0; //Can't have more matching pairs than total adjacent pairs

        int r =min(k, d-k); //Use smaller side of combination for efficiency
        long long C=1; //will hold the value of  C(d, k)

        if (r>0){
            vector<int> inv (r+1);
            inv[1]=1;

            //Build modular inverse for 1..r
            for (int i=1; i<=r; ++i){
                C=C*(d-r+i)%MOD; //Multiply by numerator terms
                C=C* inv[i] % MOD; //Divide by i via modular inverse
            }
        }

        //Compute m* C(d, k)*(m-1)^(d-k)%MOD
        long long res=m*C % MOD*power(m-1, d-k, MOD)%MOD;
        return res;
    }
private:
    //Fast modular exponentiation
    long long power(long long base, long long exp, int mod){
        long long result=1;
        base%=mod;
        while(exp>0){
            if (exp%2==1){
                result=result*base%mod;
            }
            base=base*base%mod;
            exp /=2;
        }
        return result;
    }
};

void runTests(){
    Solution sol;

    //Example 1
    int res1=sol.countGoodArrays(3, 2, 1);
    cout<<"Test 1 (Expected 4):"<<res1<<endl;

    //Example 2
    int res2=sol.countGoodArrays(4, 2, 2);
    cout<<"Test 2 (Expected 6):"<<res2<<endl;

    //Edge case: Too many matches
    int res3=sol.countGoodArrays(3, 2, 5);
    cout<<"Test 3 (Expected 0):"<<res3<<endl;

    //Large case: no matching pairs
    int res4=sol.countGoodArrays(100000, 2, 0);
    cout<<"Test 4 (Large case, no expected value given):"<<res4<<endl;
}

int main(){
    runTests();
    return 0;
}