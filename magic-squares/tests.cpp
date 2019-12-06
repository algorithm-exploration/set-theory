#include "min_cost_magic_square.hpp"

int main()
{
    cout << "\nThese are the possible magic squares for this size square:\n";

    // ofstream fout(getenv("OUTPUT_PATH"));
    ifstream fin("input.txt");

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            fin >> s[i][j];
        }
    }

    int result = formingMagicSquare(s);

    cout << "The test square is: \n";
    for(int j=0; j<s.size()*s.size(); j++) {
        if(j!=0 && j%3==0) cout << endl;
            cout << s[j/3][j%3] << ' ';
        } cout << endl << endl;

    // fout << result << "\n";
    cout << "The minimum error is: " << result << "\n";
    cout << "if [input.txt] then expect: 9.\n\n";

    // fout.close();
    fin.close();

    return 0;
}