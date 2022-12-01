#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int puzzle1(ifstream& file) {
    string line;
    int maximum = 0;
    int total = 0;
    while ( getline (file,line) )
    {
      if (line.empty()) {
        if (maximum < total) maximum = total;
        total = 0;
      } else {
        total += stoi(line);
      }
    }
    
    return maximum;
}

int puzzle2(ifstream& file) {
    string line;
    int* maxima = new int[3];
    int total = 0;
    while ( getline (file,line) )
    {
      if (line.empty()) {
        for (int i=0; i < 3; i++) {
            if (maxima[i] < total) {
                for (int j=i; j < 2; j++) {
                    maxima[j+1] = maxima[j];
                }
                maxima[i] = total;
                break;
            } 
        }
        total = 0;
      } else {
        total += stoi(line);
      }
    }
    
    return maxima[0] + maxima[1] + maxima[2];
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