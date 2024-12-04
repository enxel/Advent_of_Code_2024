#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> Matrix;

int horizontal(Matrix puzzle, string S){
    int n = puzzle.size();

    int cont = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n-3; j++)
            if(puzzle.at(i).at(j) == S[0])
                if(puzzle.at(i).at(j+1) == S[1])
                    if(puzzle.at(i).at(j+2) == S[2])
                        if(puzzle.at(i).at(j+3) == S[3])
                            cont++;

    return cont;
}

int vertical(Matrix puzzle, string S){
    int n = puzzle.size();

    int cont = 0;
    for(int i = 0; i < n-3; i++)
        for(int j = 0; j < n; j++)
            if(puzzle.at(i).at(j) == S[0])
                if(puzzle.at(i+1).at(j) == S[1])
                    if(puzzle.at(i+2).at(j) == S[2])
                        if(puzzle.at(i+3).at(j) == S[3])
                            cont++;

    return cont;
}

int diagonal1(Matrix puzzle, string S){
    int n = puzzle.size();

    int cont = 0;
    for(int i = 0; i < n-3; i++)
        for(int j = 0; j < n-3; j++)
            if(puzzle.at(i).at(j) == S[0])
                if(puzzle.at(i+1).at(j+1) == S[1])
                    if(puzzle.at(i+2).at(j+2) == S[2])
                        if(puzzle.at(i+3).at(j+3) == S[3])
                            cont++;

    return cont;
}

int diagonal2(Matrix puzzle, string S){
    int n = puzzle.size();

    int cont = 0;
    for(int i = 0; i < n-3; i++)
        for(int j = 3; j < n; j++)
            if(puzzle.at(i).at(j) == S[0])
                if(puzzle.at(i+1).at(j-1) == S[1])
                    if(puzzle.at(i+2).at(j-2) == S[2])
                        if(puzzle.at(i+3).at(j-3) == S[3])
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

    int cont = horizontal(puzzle,"XMAS") + horizontal(puzzle,"SAMX")
            + vertical(puzzle,"XMAS") + vertical(puzzle,"SAMX")
            + diagonal1(puzzle,"XMAS") + diagonal1(puzzle,"SAMX")
            + diagonal2(puzzle,"XMAS") + diagonal2(puzzle,"SAMX");

    /*
    cout << puzzle.size() << "\n";
    for(int i = 0; i < puzzle.size(); i++)
        cout << puzzle.at(i).size() << "\n";
    */

    cout << cont << "\n";

    return 0;
}