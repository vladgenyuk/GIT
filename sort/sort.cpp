#include <ctime>
#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
using namespace std;

char criterion = 'b', sort_kind = 'M';

struct course{
    string bank;
    double buy;
    double sell;
    string address = "Address:street ";
    double difference;
};

bool check(double el){
    if(el > 2.39 && el < 2.4102){
        return true;
    }
    return false;
}

bool compare_diff(struct course x, struct course y){
    if(x.difference > y.difference){
        return true;
    }
    return false;
}


bool compare_buy(struct course x, struct course y){
    if(x.buy > y.buy){
        return true;
    }
    return false;
}

struct course *bubble_sort(struct course *arr, int size, bool (*func)(struct course, struct course)){
    struct course *a = new struct course[size];
    a = arr;
    struct course h;
    for(int i = 0; i < size - 1; i ++){
        for(int j = 0; j < size - 1; j++){
            if(func(a[j], a[j+1])){
                h = a[j];
                a[j] = a[j + 1];
                a[j + 1] = h;
            }
        }
    }
    return a;
}

struct course *merge(struct course *a, struct course *b, int lena, int lenb, bool (*func)(struct course, struct course)){
    struct course *c = new struct course[lena + lenb];
    // print(a, lena);
    int i = 0, k = 0, n = 0;
    while(i < lena && k < lenb){
        if(func(a[i], b[k])){
            c[n] = a[i];
            i += 1;
            n += 1;
        } else{
            c[n] = b[k];
            k += 1;
            n += 1;
        }
    }
    while(i < lena){
        c[n] = a[i];
        i += 1;
        n += 1;
    }
    while(k < lenb){
        c[n] = b[k];
        k += 1;
        n += 1;
    }
    return c;
}

struct course *sort(struct course *arr, int len, bool (*func)(struct course, struct course)){
    if (len <= 1){
        return 0;
    }
    int lena = 0, lenb = 0;
    
    lena = len/2;
    lenb = len-lena;
    struct course l[lena];
    struct course r[lenb];
    for(int i = 0; i < lena; i++){
        l[i] = arr[i];
    }
    for(int i = lena; i < len; i++){
        r[i-lena] = arr[i];
    }
    // print(r, lenb);
    sort(l, lena, func);
    sort(r, lenb, func);
    struct course *m;
    m = merge(l, r, lena, lenb, func);
    for(int i = 0; i < len; i++){
        arr[i] = m[i];
    }
    return arr;
}



int main(){
    srand(time(0));
    const int size = 100;
    // struct course *p;
    // struct course val_arr[10];
    // struct course *po;
    cout << "Enter kind of sort B-bubble, M-merge \n";
    cin >> sort_kind;
    cout << "Enter criterion (b-buy, d-difference) \n";
    cin >> criterion;


    ifstream file;
    struct course arr[size];
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
    }


    // val_arr[0].buy = 2.401;
    // val_arr[1].buy = 2.4;
    // val_arr[2].buy = 2.39;
    // val_arr[3].buy = 2.41;
    // val_arr[4].buy = 2.4102;
    // val_arr[5].buy = 2.43;
    // val_arr[6].buy = 2.4105;
    // val_arr[7].buy = 2.402;
    // val_arr[8].buy = 2.405;
    // val_arr[9].buy = 2.395;

    // for(int i = 0; i < size; i ++){
    //     val_arr[i].sell = val_arr[i].buy + 1 + 1.0 / (rand() % 10 + 1);
    //     val_arr[i].bank = "Bank " + to_string(i + rand() % 100);
    //     val_arr[i].address += to_string(i+ rand() % 100) + ".1";
    //     val_arr[i].difference = val_arr[i].sell - val_arr[i].buy;
    // }

    if(sort_kind == 'B'){
        if(criterion == 'd'){
            bubble_sort(arr, size, compare_diff);
        }else{
            bubble_sort(arr, size, compare_buy);
        }
    } else{
        if(criterion == 'd'){
            sort(arr, size, compare_diff);
        }else{
            sort(arr, size, compare_buy);
        }
    }


    for(int i = 0; i < size; i++){
        cout << arr[i].difference << ' ';
    }
    cout << '\n';
    for(int i = 0; i < size; i++){
        cout << arr[i].buy << ' ';
    }
    cout << '\n';

}