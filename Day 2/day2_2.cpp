#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<int> V){
    for(int i = 0; i < V.size(); i++)
        cout << V.at(i) << " ";
    cout << "\n";
}

int eval_vector(vector<int> caso){
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

    return 1;
}

int processCase(string line){
    vector<int> caso;

    string data;
    stringstream ss(line);
    
    while(getline(ss,data,' '))
        caso.push_back(stoi(data));
    
    int res = eval_vector(caso);
    if(!res)
        for(int i = 0; i < caso.size(); i++){
            vector<int> temp = caso;
            temp.erase(temp.begin() + i);
            res = eval_vector(temp);
            if(res) break;
        }

    return res;
}

int main(void){
    string line;
    ifstream inputFile("input.txt");
    //ifstream inputFile("coso.txt");

    int cont = 0;
    while (getline(inputFile, line)){
        cont += processCase(line);
        //cout << "--------------------------\n";int n; cin >> n;
    }
    inputFile.close();

    cout << cont << "\n";

    return 0;
}
