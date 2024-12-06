#include <bits/stdc++.h>

using namespace std;

bool it_has_happened = false;

typedef map<int,vector<int>> Rules;

Rules info;

int processLine(string line){
    int answer = 0;
    
    if(!it_has_happened){
        //regex e(R"~(([0-9]+))~");
        regex e(R"~(([0-9]+)\|([0-9]+))~");

        smatch m;
        regex_token_iterator<string::iterator> rend;
        //cout << line << '\n';//cin >> answer;
        if(regex_search(line, m, e)){
            int key = stoi(m[1]);
            int value = stoi(m[2]);
            //cout << key << " - " << value << '\n';
            if(info.find(key) == info.end()){
                vector<int> v;
                v.push_back(value);
                Rules::iterator it = info.begin();
                info.insert (it, pair<int,vector<int>>(key,v));
            }else
                if(find(info[key].begin(), info[key].end(), value) == info[key].end())
                    info[key].push_back(value);
        }
    }else{
        regex e{R"~([0-9]+)~"};
        regex_token_iterator<string::iterator> a( line.begin(), line.end(), e);
        regex_token_iterator<string::iterator> rend;
        
        vector<int> temp;
        while (a != rend){
            string stemp(*a);
            temp.push_back(stoi(stemp));
            a++;
        }
        //cout << line << '\n';cin >> answer;

        int n = temp.size();
        bool got_fixed = false;

        for(int i = 0; i < n-1; i++)
            for(int j = i+1; j < n; j++)
                if(info.find(temp.at(j)) != info.end() && find(info[temp.at(j)].begin(), info[temp.at(j)].end(), temp.at(i)) != info[temp.at(j)].end()){
                    if(!got_fixed) got_fixed = true;
                    swap(temp.at(i),temp.at(j));
                }

        //if(got_fixed) cout << temp.at(n/2) << '\n';
        if(got_fixed) answer = temp.at(n/2);
    }

    return answer;
}

int main(void){
    string line;
    ifstream inputFile("input.txt");
    //ifstream inputFile("coso.txt");

    int acum = 0;
    while (getline(inputFile, line)){
        //cout << line.length() << '\n';
        if(line.length() <= 1){
            it_has_happened = true;//cout << "HEY!";
            continue;
        }
        acum += processLine(line);
    }
    inputFile.close();

    cout << acum << "\n";

    return 0;
}