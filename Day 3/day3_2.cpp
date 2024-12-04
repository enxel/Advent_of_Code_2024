#include <bits/stdc++.h>

using namespace std;

bool enabled = true;

int processLine(string line){
    regex f{R"~(mul\(([0-9][0-9]?[0-9]?),([0-9][0-9]?[0-9]?)\)|do\(\)|don't\(\))~"};
    regex e{R"~(mul\(([0-9][0-9]?[0-9]?),([0-9][0-9]?[0-9]?)\))~"};
    regex y{R"~(do\(\))~"};
    regex n{R"~(don't\(\))~"};

    smatch m;
    regex_token_iterator<string::iterator> rend;
    regex_token_iterator<string::iterator> a( line.begin(), line.end(), f );

    int acum = 0;
    while (a != rend){
        string temp(*a);
        //cout << temp << "\n";
        if(regex_match(temp, m, y)) enabled = true;
        if(regex_match(temp, m, n)) enabled = false;
        if(regex_match(temp, m, e)) if(enabled) acum += stoi(m[1]) * stoi(m[2]);
        a++;
    }

    return acum;
}

int main(void){
    string line;
    ifstream inputFile("input.txt");
    //ifstream inputFile("coso2.txt");

    int acum = 0;
    while (getline(inputFile, line)){
        //cout << line << "\n";
        acum += processLine(line);
    }
    inputFile.close();

    cout << acum << "\n";

    return 0;
}