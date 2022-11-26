#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct course{
    string bank;
    double buy;
    double sell;
    string address;
    double difference;
};

int main(){
    ifstream file;
    struct course arr[100];
    file.open("bank.txt", std::ios_base::app);
    if(!file.is_open()){
        cout << "File failed to open!";
        return 0;
    }
    int c = 0;
    string bank, buy, sell, address, line;
    while(getline(file, line)){
        stringstream ss(line);
        getline(ss, bank, ':');
        getline(ss, buy, ':');
        getline(ss, sell, ':');
        getline(ss, address, ':');
        arr[c].bank = bank;
        arr[c].buy = stod(buy);
        arr[c].sell = stod(sell);
        arr[c].address = address;
        arr[c].difference = stod(sell) - stod(buy);
        c++;
        cout << bank << buy << sell << address << '\n';
    }

    return 0;
}