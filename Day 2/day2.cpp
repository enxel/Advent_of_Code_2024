#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> V){
    for(int i = 0; i < V.size(); i++)
        cout << V.at(i) << " ";
    cout << "\n";
}

int processCase(string line){
    vector<int> caso;

    string data;
    stringstream ss(line);
    
    while(getline(ss,data,' '))
        caso.push_back(stoi(data));

    //print_vector(caso);
    
    if(caso.at(0) == caso.at(1)) return 0;
    bool direction = caso.at(0) < caso.at(1); //true = ASC, false = DESC

    for(int i = 0; i < caso.size()-1; i++){
        if(caso.at(i) == caso.at(i+1)) return 0;
        if(direction)
            if(caso.at(i) < caso.at(i+1) && caso.at(i+1) <= caso.at(i)+3) continue;
            else return 0;
        else
            if(caso.at(i) > caso.at(i+1) && caso.at(i+1) >= caso.at(i)-3) continue;
            else return 0;
    }

    //print_vector(caso);

    return 1;
}

int main(void){
    string line;
    //ifstream inputFile("input.txt");
    ifstream inputFile("coso.txt");

    int cont = 0;
    while (getline(inputFile, line)){
        cont += processCase(line);
        //cout << "--------------------------\n";int n; cin >> n;
    }
    inputFile.close();

    cout << cont << "\n";

    return 0;
}
