/**
============================= Details =============================

                Custom C++ Integer List Library.
                Written By: Saleh Ibne Omar.
                Date created: 07-JULY-2019.
                Inspired by JAVA's ArrayList.
                Contains some extra features than ArrayList.
                Copyright (C) 2019, Saleh Ibne Omar.

===================================================================
*/
#include <bits/stdc++.h>
using namespace std;

class IntegerList{

private:

    int INDEX;
    int arr[1000];
    int SIZE;

public:

    IntegerList(int SIZE){
        if(SIZE>1000){
            this->SIZE=0;
            cout<<"Maximum size 1000!"<<endl;
        }
        else{
            this->SIZE=SIZE;
        }
        INDEX=-1;
    }

    IntegerList(){
        SIZE=30;
        INDEX=-1;
    }

    bool isEmpty(){
        if(INDEX<0){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(!(INDEX<SIZE)){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        if(SIZE<=0){
            return 0;
        }
        else{
            return SIZE;
        }
    }

    int getLength(){
        if(INDEX<0){
            return -1;
        }
        else{
            return INDEX;
        }
    }

    void printList(){
        for(int i=0; i<INDEX; i++){
            cout<<arr[i]<<" ";
        }
    }

    void add(int value){
        if(isFull()){
            cout<<"limit reached!"<<endl;
        }
        else if(SIZE<=0){
            cout<<"Size not set correctly!"<<endl;
        }
        else{
            if(INDEX<0){
                INDEX=0;
            }
            arr[INDEX]=value;
            INDEX++;
        }
    }

    void addToIndex(int pos, int value){
        if(INDEX<0 || pos>INDEX){
            cout<<"Index out of bounds!"<<endl;
        }
        else{
            if(isFull()){
                cout<<"limit reached!"<<endl;
            }
            else{
                for(int i=INDEX; i>pos; i--){
                    arr[i]=arr[i-1];
                }
                arr[pos]=value;
            }
            INDEX++;
        }
    }

    void update(int pos, int value){
        if(INDEX<0 || pos>INDEX){
            cout<<"Index out of bounds!"<<endl;
        }
        else{
            arr[pos]=value;
        }
    }

    int getValue(int pos){
        return arr[pos];
    }

    void sortAsc(){
        if(SIZE<=0 || (INDEX-1)<=0){
            cout<<"Noting to sort!"<<endl;
        }
        else{
            sort(arr, arr+INDEX);
        }
    }

    void sortDesc(){
        if(SIZE<=0 || (INDEX-1)<=0){
            cout<<"Noting to sort!"<<endl;
        }
        else{
            sort(arr, arr+INDEX, greater<int>());
        }
    }

    int searchValue(int value){
        bool flag=false;
        if(SIZE<=0 || isEmpty()){
            return -1;
        }
        else{
            int i=0;
            while(i<INDEX){
                if(arr[i]==value){
                    flag=true;
                    break;
                }
                i++;
            }

            if(flag!=true){
                return -1;
            }
            else{
                return i;
            }
        }
    }

    void removeByIndex(int pos){
        if(isEmpty() || SIZE<=0){
            cout<<"Empty list!"<<endl;
        }
        else{
            for(int i=pos; i<INDEX-1; i++){
                arr[i]=arr[i+1];
            }
            INDEX--;
            if(INDEX<=0){
                INDEX=-1;
            }
        }
    }

    void removeByValue(int value){
        int i=searchValue(value);
        if(i<0){
            cout<<"Empty list!"<<endl;
        }
        else{
           removeByIndex(i);
        }
    }

    void removeAll(){
        for(int i=0; i<INDEX; i++){
            arr[i]=0;
        }
        INDEX=-1;
    }

    int frequency(int value){
        if(SIZE<=0 || isEmpty()){
            return -1;
        }
        else{
            int counter=0;
            for(int i=0; i<INDEX; i++){
                if(arr[i]==value){
                    counter++;
                }
            }
            if(counter==0){
                return -1;
            }
            else{
                return counter;
            }
        }
    }

    void batchRemoveValues(int value){
        int f=frequency(value);
        if(f<2){
            cout<<"Empty list \nOr frequency less than two \nOr value might not found!"<<endl;
        }
        else{
            int pos;
            while(true){
                pos=searchValue(value);
                if(pos<0){break;}
                removeByIndex(pos);
            }
        }
    }
};

int main(){

    IntegerList obj(10);
    obj.add(2);
    obj.add(1);
    obj.add(3);
    obj.printList();
    cout<<endl;
    obj.sortAsc();
    obj.add(5);
    obj.printList();
    cout<<endl;
    obj.removeByIndex(0);
    obj.printList();
    cout<<endl;
    obj.removeByValue(5);
    obj.printList();
    cout<<endl;

return 0;

}

/**
============================= Details =============================

                Custom C++ Integer List Library.
                Written By: Saleh Ibne Omar.
                Date created: 07-JULY-2019.
                Inspired by JAVA's ArrayList.
                Contains some extra features than ArrayList.
                Copyright (C) 2019, Saleh Ibne Omar.

===================================================================
*/

