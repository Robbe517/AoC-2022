#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int puzzle1(ifstream& file) {
    string line;
    getline(file, line);
    char buffer[4] = {line[0], line[1], line[2], line[3]};
    for (int i = 4; i < line.size(); i++) {
        int found = 1;
        for (int k = 0; k < 4; k++) {
            for (int l = 0; l < k; l++) {
                if (buffer[k] == buffer[l]) found = 0;
            }
        }
        if (found) return i;
        buffer[i%4] = line[i];
    }
}

int puzzle2(ifstream& file) {
    string line;
    getline(file, line);
    char buffer[14];
    for (int i = 0; i < 14; i++) {
        buffer[i] = line[i];
    }
    for (int i = 14; i < line.size(); i++) {
        int found = 1;
        for (int k = 0; k < 14; k++) {
            for (int l = 0; l < k; l++) {
                if (buffer[k] == buffer[l]) found = 0;
            }
        }
        if (found) return i;
        buffer[i%14] = line[i];
    }
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