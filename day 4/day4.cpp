#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int puzzle1(ifstream& file) {
    string line;
    int count;
    string elf11, elf12, elf21, elf22;
    while ( getline (file,line) )
    {
        stringstream ss(line);
        getline(ss, elf11, '-'); 
        getline(ss, elf12, ',');
        getline(ss, elf21, '-');
        getline(ss, elf22);

        if (stoi(elf11) <= stoi(elf21) && stoi(elf12) >= stoi(elf22) || stoi(elf11) >= stoi(elf21) && stoi(elf12) <= stoi(elf22))
            count++;
    }
    
    return count;
}

int puzzle2(ifstream& file) {
    string line;
    int count;
    string elf11, elf12, elf21, elf22;
    while ( getline (file,line) )
    {
        stringstream ss(line);
        getline(ss, elf11, '-'); 
        getline(ss, elf12, ',');
        getline(ss, elf21, '-');
        getline(ss, elf22);

        if (stoi(elf11) <= stoi(elf22) && stoi(elf12) >= stoi(elf21))
            count++;
    }
    
    return count;
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