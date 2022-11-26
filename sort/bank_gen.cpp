#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void clear(){

}

int main(){
    srand(time(0));
    fstream file;
    file.open("bank.txt", std::ios_base::app);
    for(int i = 1; i <= 100; i++){
        file << to_string(i) + " Bank : ";
        file << to_string(2 + 1.0/(rand() % 10 +1)) + " : ";
        file << to_string(2 + 3.0/(rand() % 10 +1)) + " : ";
        file << "Address - " + to_string(rand() % 1000) + ".1 :  \n";
    }
    file.close();
    return 0;
}