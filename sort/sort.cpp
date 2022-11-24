#include <ctime>
#include <iostream>
#include <string> 
using namespace std;

char criterion = 'b', sort_kind;

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

struct course *bubble_sort(struct course *arr, int size){
    struct course *a = new struct course[size];
    a = arr;
    struct course h;
    if(criterion == 'd'){
        for(int i = 0; i < size - 1; i ++){
            for(int j = 0; j < size - 1; j++){
                if(a[j].difference > a[j+1].difference){
                    h = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = h;
                }
            }
        }
    } else {
        for(int i = 0; i < size - 1; i ++){
            for(int j = 0; j < size - 1; j++){
                if(a[j].buy > a[j+1].buy){
                    h = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = h;
                }
            }
        }
    }
    return a;
}

struct course *merge(struct course *a, struct course *b, int lena, int lenb){
    struct course *c = new struct course[lena + lenb];
    // print(a, lena);
    int i = 0, k = 0, n = 0;
    if(criterion == 'd'){
    while(i < lena && k < lenb){
        if(a[i].difference > b[k].difference){
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
    }
    if(criterion == 'b'){
    while(i < lena && k < lenb){
        if(a[i].buy > b[k].buy){
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
    }
    return c;
}

struct course *sort(struct course *arr, int len){
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
    sort(l, lena);
    sort(r, lenb);
    struct course *m;
    m = merge(l, r, lena, lenb);
    for(int i = 0; i < len; i++){
        arr[i] = m[i];
    }
    return arr;
}



int main(){
    srand(time(0));
    const int size = 10;
    double arr[size];
    struct course *p;
    struct course val_arr[10];
    struct course *po;
    cout << "Enter kind of sort B-bubble, M-merge \n";
    cin >> sort_kind;
    cout << "Enter criterion (b-buy, d-difference) \n";
    cin >> criterion;

    val_arr[0].buy = 2.401;
    val_arr[1].buy = 2.4;
    val_arr[2].buy = 2.39;
    val_arr[3].buy = 2.41;
    val_arr[4].buy = 2.4102;
    val_arr[5].buy = 2.43;
    val_arr[6].buy = 2.4105;
    val_arr[7].buy = 2.402;
    val_arr[8].buy = 2.405;
    val_arr[9].buy = 2.395;

    for(int i = 0; i < size; i ++){
        val_arr[i].sell = val_arr[i].buy + 1 + 1.0 / (rand() % 10 + 1);
        val_arr[i].bank = "Bank " + to_string(i + rand() % 100);
        val_arr[i].address += to_string(i+ rand() % 100) + ".1";
        val_arr[i].difference = val_arr[i].sell - val_arr[i].buy;
    }
    if(sort_kind == 'B'){
        bubble_sort(val_arr, size);
    } else{
        sort(val_arr, size);
    }
    for(int i = 0; i < 10; i++){
        cout << val_arr[i].difference << ' ';
    }
    cout << '\n';
    for(int i = 0; i < 10; i++){
        cout << val_arr[i].buy << ' ';
    }
    cout << '\n';
    cout << '\n';

    for(int i = 0; i < 10; i++){
        if(check(val_arr[i].buy)){
            cout << val_arr[i].bank << ' ' << val_arr[i].address << ' ' << val_arr[i].buy << ' ' << val_arr[i].sell << ' ' << val_arr[i].difference << '\n';
        }
    }
    cout << '\n';

}