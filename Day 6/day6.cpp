#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> Matrix;

void simulate(Matrix& M, int f, int c){
    cout << M.at(f).at(c);
}

int main(void){
    Matrix floor;

    string line;
    //ifstream inputFile("input.txt");
    ifstream inputFile("coso.txt");

    int row = -1, column = -1;
    while (inputFile >> line){
        if(column == -1){
            int temp  = line.find("^");
            if(temp != string::npos){
                column = temp;
                row =floor.size() + 1;
            }
        }
        floor.push_back(vector<char>(line.begin(), line.end()));
    }
    inputFile.close();

    simulate(floor, row, column);

    //cout << floor.size() << " - " << floor.at(0).size();

    return 0;
}