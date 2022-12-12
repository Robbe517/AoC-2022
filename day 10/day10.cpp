#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int puzzle1(ifstream& file) {
    string line;
    vector<int> X = vector<int>();
    X.push_back(1);
    while ( getline (file,line) )
    {
        X.push_back(X.back());
        if (line.substr(0, 4) == "addx") X.push_back(X.back() + stoi(line.substr(5)));
    }
    int sum = 0;
    for (int i = 19; i < X.size(); i += 40) sum += X[i] * (i + 1);
    return sum;
}

void puzzle2(ifstream& file) {
    string line;
    vector<int> X = vector<int>();
    X.push_back(1);
    while ( getline (file,line) )
    {
        cout << (abs(X.back() - (int(X.size()) - 1)%40) < 2 ? '#' : '.');
        if (X.size() % 40 == 0) cout << endl    ;
        X.push_back(X.back());
        if (line.substr(0, 4) == "addx") {
            cout << (abs(X.back() - (int(X.size()) - 1)%40) < 2 ? '#' : '.');
            if (X.size() % 40 == 0) cout << endl;
            X.push_back(X.back() + stoi(line.substr(5)));
        }
    }
}

int main() {
    ifstream file;
    file.open("input.txt");
    
    cout << puzzle1(file) << endl;

    file.clear();
    file.seekg(0);

    puzzle2(file);

    file.close();
    return 0;
}