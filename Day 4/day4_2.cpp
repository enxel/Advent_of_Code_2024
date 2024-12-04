#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> Matrix;

int X_Mas(Matrix puzzle, string S){
    int n = puzzle.size();

    int cont = 0;
    for(int i = 0; i < n-2; i++)
        for(int j = 0; j < n-2; j++)
            if(puzzle.at(i).at(j) == S[0])
                if(puzzle.at(i+1).at(j+1) == S[1])
                    if(puzzle.at(i+2).at(j+2) == S[2])
                        if((puzzle.at(i).at(j+2) == S[0] && puzzle.at(i+2).at(j) == S[2])
                            || (puzzle.at(i).at(j+2) == S[2] && puzzle.at(i+2).at(j) == S[0]))
                            cont++;

    return cont;
}

int main(void){
    Matrix puzzle;

    string line;
    ifstream inputFile("input.txt");
    //ifstream inputFile("coso.txt");

    while (inputFile >> line){
        puzzle.push_back(vector<char>(line.begin(), line.end()));
    }
    inputFile.close();

    int cont = X_Mas(puzzle,"MAS") + X_Mas(puzzle,"SAM");

    /*
    cout << puzzle.size() << "\n";
    for(int i = 0; i < puzzle.size(); i++)
        cout << puzzle.at(i).size() << "\n";
    */

    cout << cont << "\n";

    return 0;
}