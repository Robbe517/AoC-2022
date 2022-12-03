#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int puzzle1(ifstream& file) {
    string line;
    int total = 0;
    while ( getline (file,line) )
    {
        int player1 = line[0] - 'A';
        int player2 = line[2] - 'X';
        total += player2 + 1;
        total += ((player2 - player1 + 4) % 3) * 3;
    }
    
    return total;
}

int puzzle2(ifstream& file) {
    string line;
    int total = 0;
    while ( getline (file,line) )
    {
        int player1 = line[0] - 'A';
        int player2 = line[2] - 'X';
        total += player2 * 3;
        total += (player1 + player2 + 2) % 3 + 1;
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