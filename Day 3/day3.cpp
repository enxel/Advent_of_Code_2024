#include <bits/stdc++.h>

using namespace std;

int processLine(string line){
    regex e{R"~(mul\(([0-9][0-9]?[0-9]?),([0-9][0-9]?[0-9]?)\))~"};

    smatch m;
    regex_token_iterator<string::iterator> rend;
    regex_token_iterator<string::iterator> a( line.begin(), line.end(), e );

    int acum = 0;
    while (a != rend){
        string temp(*a);
        if(regex_match(temp, m, e)){
            acum += stoi(m[1]) * stoi(m[2]);
        }
        a++;
    }

    return acum;
}

int main(void){
    string line;
    ifstream inputFile("input.txt");
    //ifstream inputFile("coso.txt");

    int acum = 0;
    while (getline(inputFile, line)){
        //cout << line << "\n";
        acum += processLine(line);
    }
    inputFile.close();

    cout << acum << "\n";

    return 0;
}