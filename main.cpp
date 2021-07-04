#include <iostream>
#include <stdio.h>

using namespace std;

struct tNo{
 int info;
 tNo* proximo;
};

tNo* criaNo(int item){
 tNo* no = new tNo;
 no -> info = item;
 no -> proximo = NULL;

 return no;
}


int main() {

tNo* no1;
tNo* no2;
tNo* no3;

no1 = criaNo(10);
no2 = criaNo(20);
no3 = criaNo(30);

cout << no1->info << endl;
cout << no2->info << endl;
cout << no3->info << endl;

}