#include <bits/stdc++.h>
#define LIMIT 25000

using namespace std;

enum move {UP,DOWN,LEFT,RIGHT};
typedef vector<vector<char>> Matrix;

void show_floor(Matrix M){
    int n = M.size(), m = M.at(0).size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << M.at(i).at(j);
        cout << '\n';
    }
}

int simulate(Matrix& M, int f, int c){
    int limit_checker = 0;
    enum move direction = UP;
    
    int n = M.size(), m = M.at(0).size();
    while(0 <= f && f < n && 0 <= c && c < m && limit_checker < LIMIT){
        //cout << f << " - " << c << '\n';// cin >> cont;
        M.at(f).at(c) = 'X';
        switch(direction){
            case UP:
                if(f-1 >= 0 && M.at(f-1).at(c) == '#') direction = RIGHT;
                else f--;
                break;
            case RIGHT:
                if(c+1 < m && M.at(f).at(c+1) == '#') direction = DOWN;
                else c++;
                break;
            case DOWN:
                if(f+1 < n && M.at(f+1).at(c) == '#') direction = LEFT;
                else f++;
                break;
            case LEFT:
                if(c-1 >= 0 && M.at(f).at(c-1) == '#') direction = UP;
                else c--;
                break;
        }

        limit_checker++;
    }

    return limit_checker >= LIMIT;
}

int main(void){
    Matrix floor;

    string line;
    ifstream inputFile("input.txt");
    //ifstream inputFile("coso.txt");

    int row = -1, column = -1;
    while (inputFile >> line){
        if(column == -1){
            int temp  = line.find("^");
            if(temp != string::npos){
                column = temp;
                row = floor.size();
            }
        }
        floor.push_back(vector<char>(line.begin(), line.end()));
    }
    inputFile.close();

    int cont = 0;
    int n = floor.size(), m = floor.at(0).size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(floor.at(i).at(j) == '.'){
                Matrix copy = floor;
                copy.at(i).at(j) = '#';
                cont += simulate(copy, row, column);
                //show_floor(copy);
            }

    cout << cont << '\n';

    return 0;
}