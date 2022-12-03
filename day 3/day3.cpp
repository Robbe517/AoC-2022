#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int puzzle1(ifstream& file) {
    string line;
    int total = 0;
    while ( getline (file,line) )
    {
        size_t partsize = line.size()/2;
        string part1 = line.substr(0, partsize);
        string part2 = line.substr(partsize, partsize);
        for (size_t i = 0; i < partsize; i++) {
            char char_i = part1[i];
            if (part2.find(char_i) != string::npos) {
                if (char_i > 'Z') {
                    total += char_i - 'a' + 1;
                } else {
                    total += char_i - 'A' + 27;
                }
                break;
            }
        }
    }
    
    return total;
}

int puzzle2(ifstream& file) {
    string elf1, elf2, elf3;
    int total = 0;
    while ( getline (file, elf1) )
    {
        getline(file, elf2);
        getline(file, elf3);
        for (size_t i = 0; i < elf1.size(); i++) {
            char char_i = elf1[i];
            if (elf2.find(char_i) != string::npos && elf3.find(char_i) != string::npos) {
                if (char_i > 'Z') {
                    total += char_i - 'a' + 1;
                } else {
                    total += char_i - 'A' + 27;
                }
                break;
            }
        }
    }

    return total;
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