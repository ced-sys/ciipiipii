#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <bitset>
#include <iomanip>

using namespace std;

//Simple quantum state representation
class QuantumState{
public:
    vector<complex<double>> amplitudes;
    int numQubits;

    QuantumState(int n) : numQubits(n){
        int size=1<<n;
        amplitudes.resize(size, 0.0);
        amplitudes[0]=1.0;
    }

    //Apply Hadamard gate to a single qubit
    void hadamard(int target){
        vector<complex<double>> newAmplitudes=amplitudes;
        double factor=1.0/sqrt(2.0);

        for (int i=0; i<amplitudes.size(); i++){
            int bit=(i >> target)&1;
            int flipped=i^(1<<target);

            if (bit==0){
                newAmplitudes[i]=factor*(amplitudes[i]+amplitudes[flipped]);
            }else{
                newAmplitudes[i]=factor*(amplitudes[i-(1<<target)]-amplitudes[i]);
            }
        }
        amplitudes=newAmplitudes;
    }

    //Apply Pauli-X gate (Not Gate)
    void pauliX(int target){
        for (int i=0; i<amplitudes.size(); i++){
            int flipped=i^(1<<target);
            if (i<flipped) {
                swap(amplitudes[i], amplitudes[flipped]);
            }
        }
    }

    //Apply Pauli-Z gate
    void pauliZ(int target){
        for(int i=0; i<amplitudes.size(); i++){
            if ((i>>target)&1){
                amplitudes[i]*= -1.0;
            }
        }
    }

    //Measure all qubits and return probabilities
    void measureAll(){
        cout<<"\nMeasurement results:" <<endl;
        cout<<"State\t\tProbability"<<endl;
        cout<<"---\t\t-------------"<<endl;

        for (int i=0; i<amplitudes.size(); i++){
            double prob=norm(amplitudes[i]);
            if (prob>1e-10){
                cout<<bitset<8>(i) <<"\t" <<fixed<<setprecision(4) <<prob *100<<"%" <<endl;
            }
        }
    }

    //Print current state amplitudes
    void printState(){
        cout<<"\nQuantum State Amplitudes:"<<endl;
        for (int i=0; i<amplitudes.size(); i++){
            double prob=norm(amplitudes[i]);
            if (prob>1e-10){
                cout<<"|"<<bitset<8>(i)<<">:"
                    <<amplitudes[i]<<"(prob:"<<fixed<<setprecision(4)<<prob*100<< "%)"<<endl;
            }
        }
    }
};

int main(){
    cout <<"=== Quantum Circuit Simulator =="<<endl;

    //Create a 2-Qubits quantum system
    QuantumState qstate(2);

    cout<<"\n1. Initial state (|00>):"<<endl;
    qstate.printState();

    //Apply Hadamard to first qubit
    cout<<"\n2. After Hadamard on qubit 0:"<<endl;
    qstate.hadamard(0);
    qstate.printState();
    
    //Apply Hadamard to second qubit
    cout<<"\n3. After Hadamard on qubit 1:"<<endl;
    qstate.hadamard(1);
    qstate.printState();

    //Apply Pauli-X to first qubit
    cout<<"\n4.After Pauli-X on qubit 0:"<<endl;
    qstate.pauliX(0);
    qstate.printState();

    //Measure
    qstate.measureAll();

    cout<<"\n== Circuit Complete++"<<endl;

    return 0;
}


    




