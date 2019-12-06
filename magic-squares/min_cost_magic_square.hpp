#include <bits/stdc++.h>

using namespace std;
int factorial(int num) {
    int total = num;
    for(int i=1; i<num; i++) {
        total*=i;
    } return total;
}

bool check_magic(vector<int> square) {
    int sideLen = sqrt(square.size());
    vector<int> sums((sideLen*2)+2, 0);
    for(int i=0; i<sideLen; i++) {
        for(int j=0; j<sideLen; j++) {
            sums[i] += square[(i*sideLen)+j];
            sums[sideLen+j] += square[(i*sideLen)+j];
            if(i==j) sums[sideLen*2] += square[i*(sideLen+1)];
            if((i+j+1)==sideLen) sums[(sideLen*2)+1] += square[(sideLen-1)+(i*(sideLen-1))];
        }
    }
    int test=sums[0];
    for(int k=1; k<sums.size(); k++) {
        if(test != sums[k]) return false;
    }
    return true;
}

vector<vector<int>> generate_all_magic_squares(int rows) {
    int columns = rows;
    vector<int> permutation;
    vector<vector<int>> squares;
    for(int i=1; i<=rows*rows; i++) {
        permutation.push_back(i);
    }
    for(int i=0; i<(factorial(rows*rows)); i++) {
        next_permutation(permutation.begin(), permutation.end());
        if(check_magic(permutation)) {
            for(int j=0; j<permutation.size(); j++) {
                if(j!=0 && j%3==0) cout << endl;
                cout << permutation[j] << ' ';
            }
            cout << endl << endl;
            squares.push_back(permutation);
        }
    }
    return squares;
}

int get_min_adjustment(vector<vector<int>> magic_squares, vector<vector<int>> s) {
    int error=0, min=1000;
    for(vector<int> square: magic_squares) {
        error=0;
        for(int i=0; i<square.size(); i++) {
            error += abs(s[i/3][i%3] - square[i]);
        }
        if(error<min) min=error;
    } return min;
}

int formingMagicSquare(vector<vector<int>> s) {
    vector<vector<int>> magic_squares = generate_all_magic_squares(s.size());
    int min_adjustment = get_min_adjustment(magic_squares, s);
    return min_adjustment;
}
