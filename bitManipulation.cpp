/*BIT MANIPULATION LOGIC
You are given a positive number `n`. Return the 
smallest number `x` greater than or equal to `n`, such that
the binary representation of `x` contains only `set bits`.


**SOLUTION**

1. Recognize that only set bits-> numbers like 1, 3, 7, 15, 31(2^k-1)
2. Need smallest 2^k-1>=n
3. Simplify to find smallest 2^k>=n+1
4. Compute directly or simulate by bit-shifting
5. Return (1<<k)-1
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
    //Method 1: Using bit manipulation (most efficient)
    int smallestNumberWithSetBits(int n){
        //Find smallest k such that 2^k>=n+1
        //Equivalent to: find smallest k where (1<<k)>=n+1

        int k=0;
        while((1<<k)<n+1){
            k++;
        }

        //Return 2^k-1 (all bits set up to position k-1)
        return (1<<k)-1;
    }

    //Method 2: Using logarithm (alterative approach)
    int smallestNumberWithSetBitsLog(int n){
        //Find k=ceil(log2(n+1))
        int k=(int)ceil(log2(n+1));
        return (1<<k)-1;
    }

    //Method 3: Direct bit manipulation (elegant one-liner logic)
    int smallestNumberWithSetBitsDirect(int n){
        //FInd the position of the highest set bit in n
        //Then set all bits up to and including that position

        //Edge case: If n is already all set bits, return n
        if (n==0) return 1;

        //Find highest bit position
        int highestBit=0;
        int temp=n;
        while(temp>0){
            highestBit++;
            temp>>=1;
        }

        //Create number with all bits set up to highestBit
        int result=(1<<highestBit)-1;

        //If result <n, we need one more bit
        if (result<n){
            result=(1<<(highestBit+1))-1;
        }

        return result;
    }
};

int main(){
    Solution sol;

    //Test cases
    cout<<"Method (1) Bit Shifting"<<endl;
    cout<<"n=5 ->"<<sol.smallestNumberWithSetBits(5)<<"(expected: 7=111)"<<endl;
    cout<<"n=10 ->"<<sol.smallestNumberWithSetBits(10)<<"(expected 15=1111)"<<endl;
    cout<<"n=3 ->"<<sol.smallestNumberWithSetBits(3)<<"Expected: 3=11)"<<endl;
    cout<<"n=1 ->"<<sol.smallestNumberWithSetBits(1)<<"(expected: 1=1)"<<endl;
    cout<<"n=7 ->"<<sol.smallestNumberWithSetBits(7)<<"(expected: 7=111)"<<endl;
    cout<<"n=15 ->"<<sol.smallestNumberWithSetBits(15)<<"(expected: 15=1111)"<<endl;
    cout<<"n=16 ->"<<sol.smallestNumberWithSetBits(16)<<"(expected 31=11111)"<<endl;
    cout<<"n=100 ->"<<sol.smallestNumberWithSetBits(100)<<"(expected: 127=1111111)"<<endl;

    cout<<"\nMethod 2 (Logarithm):"<<endl;
    cout<<"n=5 ->"<<sol.smallestNumberWithSetBitsLog(5)<<endl;
    cout<<"n=10 ->"<<sol.smallestNumberWithSetBitsLog(10)<<endl;

    cout<<"\nMethod 3 (Direct):"<<endl;
    cout<<"n=5 ->"<<sol.smallestNumberWithSetBitsDirect(5)<<endl;
    cout<<"n=10 ->"<<sol.smallestNumberWithSetBitsDirect(10)<<endl;

    //Verify the pattern of results
    cout<<"\nPattern verification (first 20 numbers):"<<endl;
    for (int i=1; i<=20; i++){
        cout<<"n="<<i<<"->"<<sol.smallestNumberWithSetBits(i)<<endl;
    }
    
    return 0;
}