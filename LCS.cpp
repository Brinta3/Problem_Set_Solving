#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char x[] = "GXTXATB";
    char y[] = "AGGTAB";
    int m = strlen(x);
    int n = strlen(y);

    cout << m << " " << n << endl;

    int lcs[m+1][n+1];
    char dir[m+1][n+1];

    for(int i=1; i<=m; i++){
        lcs[i][0] = 0;
    }

    for(int j=0; j<=n; j++){
        lcs[0][j] = 0;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1] == y[j-1]){
                lcs[i][j] = lcs[i-1][j-1]+1;
                dir[i][j] = 'D';
            } else if(lcs[i-1][j] >= lcs[i][j-1]){
                lcs[i][j] = lcs[i-1][j];
                dir[i][j] = 'U';
            } else {
                lcs[i][j] = lcs[i][j-1];
                dir[i][j] = 'L';
            }
        }
    }

    cout << "LCS Table:" << endl;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout << lcs[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "DIR Table:" << endl;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cout << dir[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "\LCS Length: " << lcs[m][n] << endl;

    cout << "LCS String: ";
    int i=m, j=n;

    while(i!=0 || j!=0){
        if(dir[i][j] == 'D'){
            cout << x[i-1];
            i--;
            j--;
        } else if(dir[i][j] == 'U'){
            i--;
        } else {
            j--;
        }
    }

    return 0;
}
