#include <iostream>
#include <vector>
using namespace std;

bool isvalid(int A, int B, int C, int D, const vector<int> IJ) {
    
    bool nosame = (A == B) || (A == C) || (A == D) || (B == C) || (B == D) || (C == D);
    bool valida = ((B == IJ[1]) && ( C != IJ[5])) || ((B != IJ[1]) && ( C == IJ[5]));
    bool validb = ((C == IJ[2]) && ( D != IJ[6])) || ((C != IJ[2]) && ( D == IJ[6]));
    bool validc = ((D == IJ[3]) && ( A != IJ[7])) || ((D != IJ[3]) && ( A == IJ[7]));
    bool validd = ((A == IJ[4]) && ( B != IJ[8])) || ((A != IJ[4]) && ( B == IJ[8]));
    return (!nosame) && valida && validb && validc && validd;
}
int main() {
    int hasresult = 0;
    int i1, i2, i3, i4, j1, j2, j3, j4;
    cin >> i1 >> i2 >> i3 >> i4;
    cin >> j1 >> j2 >> j3 >> j4;
    vector<int> IJ(9, 0);
    IJ = {0, i1, i2, i3, i4, j1, j2, j3, j4};
    for(int A = 1; A <= 4; A++) {
        for(int B = 1; B <= 4; B++) {
            for(int C = 1; C <= 4; C++) {
                for(int D = 1; D <= 4; D++) {
                    if(isvalid(A,B,C,D, IJ)){
                        cout << A <<" "<< B <<" " << C <<" " << D << endl;
                        hasresult = 1;
                    }
                }
            }
        }
    }
    if(hasresult == 0)
        cout << -1 << endl;
    return 0;
}