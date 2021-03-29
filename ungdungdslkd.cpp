// CREAT BY TIENDAT  
#include <iostream>
using namespace  std;
struct Donthuc{
    double heso;
    int muso;
    Donthuc *next = NULL;
};
struct Dathuc{
    Donthuc *head = NULL, *tail = NULL;
};
Dathuc L1,L2,L;
void out(Dathuc A){
    Donthuc *p = A.head;
    while(p != NULL){
       if(p->heso && p->muso >  0)cout << p->heso << "x^" << p->muso;
       else if(p->muso == 0)cout << p->heso;
       p = p->next;
       if(p != NULL){
           if(p->heso)cout << " + ";
           else cout << " ";
       }
    }
}
Donthuc *creat(int i){
    Donthuc *temp = new Donthuc;
    temp->muso = i;
    cout << "Nhap he so cua x^" << i << ": "; cin >> temp->heso;
    return temp;
}
void append(Dathuc &arg, Donthuc *arg1){
    if(arg.head == NULL)arg.head = arg.tail = arg1;
    else {
        arg.tail->next = arg1;
        arg.tail = arg1;
    }
}
void enter(Dathuc &arg){
    int n;
    cout << "Nhap bac cua da thuc: "; cin >> n;
    for(int i =  n; i >= 0; i--){
        append(arg,creat(i));
    }
}
void add(){
    Donthuc *temp1 = new Donthuc, *temp2 = new Donthuc;
    if(L1.head->muso > L2.head->muso){
        L = L1;
        temp1 = L2.head;
    }
    else {
        L = L2;
        temp1 = L1.head;
    }
    temp2 = L.head;
    while(temp2->muso > temp1->muso)temp2 = temp2->next;
    while(temp2 != NULL){
        temp2->heso += temp1->heso;
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
}
int main(){
    cout << "Nhap P(x): \n"; enter(L1);
    cout << "Nhap Q(x): \n"; enter(L2);
    cout << "\nP(x) = ";out(L1);
    cout << "\nQ(x) = ";out(L2);
    add();
    cout << "\nP(x) + Q(x) = "; out(L);
    return EXIT_SUCCESS;
}
