#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

string puzzle1(ifstream& file) {
    deque<char> stacks[9];
    string line;
    getline (file,line);
    while (line != "") {
        for (int i = 0; i < 9; i++) {
            char c = line[1 + 4* i];
            if (isalpha(c)) stacks[i].push_front(c);
        }
        getline(file, line);
    }
    string ignore;
    int number, stack1, stack2;
    while ( getline (file,line) )
    {
        stringstream ss(line);
        ss >> ignore >> number >> ignore >> stack1 >> ignore >> stack2;
        for (int i = 0; i < number; i++) {
            stacks[stack2 - 1].push_back(stacks[stack1 - 1].back());
            stacks[stack1 - 1].pop_back();
        }
    }

    string result;
    for (int i = 0; i < 9; i++) {
        result += stacks[i].back();
    }
    return result;
}

string puzzle2(ifstream& file) {
    deque<char> stacks[9];
    string line;
    getline (file,line);
    while (line != "") {
        for (int i = 0; i < 9; i++) {
            char c = line[1 + 4* i];
            if (isalpha(c)) stacks[i].push_front(c);
        }
        getline(file, line);
    }
    string ignore;
    int number, stack1, stack2;
    while ( getline (file,line) )
    {
        stringstream ss(line);
        ss >> ignore >> number >> ignore >> stack1 >> ignore >> stack2;
        stacks[stack2 - 1].insert(stacks[stack2 - 1].end(), stacks[stack1 - 1].end() - number, stacks[stack1 - 1].end());
        stacks[stack1 - 1].erase(stacks[stack1 - 1].end() - number, stacks[stack1 - 1].end());
    }

    string result;
    for (int i = 0; i < 9; i++) {
        result += stacks[i].back();
    }
    return result;
}

int main() {
    ifstream file;
    file.open("input.txt");
    
    cout << puzzle1(file) << endl;

    file.clear();
    file.seekg(0);

    cout << puzzle2(file) << endl;

    file.close();
    return 0;
}