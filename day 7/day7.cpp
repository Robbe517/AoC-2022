#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct dir {
    int size;
    dir* parent;

    dir(dir* parent): size(0), parent(parent) {}

    void add_file(int file_size) {
        dir* curr = this;
        while (curr) {
            curr->size += file_size;
            curr = curr->parent;
        }
    }
};

int puzzle1(ifstream& file) {
    string line;
    int count = 0;
    string size;
    dir* curr = new dir(NULL);
    while ( getline (file,line) )
    {
        if (line[5] == '.') {
            if (curr->size <= 100000) count += curr->size;
            curr = curr->parent;
        } else if (line.substr(0, 4) == "$ cd") 
            curr = new dir(curr);
        else if (isdigit(line[0])) {
            stringstream ss(line);
            getline(ss, size, ' ');
            curr->add_file(stoi(size));
        }
    }
    
    return count;
}

int puzzle2(ifstream& file) {
    string line;
    string size;
    dir* curr = new dir(NULL);
    while ( getline (file,line) )
    {
        if (line[5] == '.')
            curr = curr->parent;
        else if (line.substr(0, 4) == "$ cd") 
            curr = new dir(curr);
        else if (isdigit(line[0])) {
            stringstream ss(line);
            getline(ss, size, ' ');
            curr->add_file(stoi(size));
        }
    }

    while (curr->parent) curr = curr->parent;
    int needed = 30000000 + curr->size - 70000000;
    file.clear();
    file.seekg(0);

    int smallest = curr->size;
    curr = new dir(NULL);
    while ( getline (file,line) )
    {
        if (line[5] == '.') {
            if (curr->size < smallest && curr->size >= needed) smallest = curr->size;
            curr = curr->parent;
        }
        else if (line.substr(0, 4) == "$ cd") 
            curr = new dir(curr);
        else if (isdigit(line[0])) {
            stringstream ss(line);
            getline(ss, size, ' ');
            curr->add_file(stoi(size));
        }
    }

    return smallest;
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