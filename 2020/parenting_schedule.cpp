#include <bits/stdc++.h>

using namespace std;

struct Event{
    int start;
    int end;
    bool parent;
};

void swap(Event** a, Event** b){  
    Event *t = *a;  
    *a = *b;  
    *b = t;  
}  
  
int partition (Event* arr[], int low, int high){  
    int pivot = arr[high]->start;  
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++){   
        if (arr[j]->start < pivot){  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;  
}  
  

void quickSort(Event* arr[], int low, int high){  
    if (low < high){  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

int main(){
    int cases;
    cin >> cases;

    int activities;
    for (int s = 1; s <= cases; s++){
        cin >> activities;
        Event events[activities];
        Event* ePtr[activities];

        for (int i = 0; i < activities; i++){
            cin >> events[i].start >> events[i].end;
            ePtr[i] = &events[i];
        }
        quickSort(ePtr, 0, activities - 1);

        bool possible = true;
        bool parent = true;
        int j = 0;
        int c = 0;
        int* tmp = &j;
        for (int i = 0; i < activities; i++){
            Event* e = ePtr[i];
            
            if (j > c){
                if (tmp != &j){
                    parent = !parent;
                }
                tmp = &j;
            } else {
                if (tmp != &c){
                    parent = !parent;
                }
                tmp = &c;
            }

            if (*tmp > e->start){
                parent = !parent;
                tmp = tmp != &c ? &c : &j;

                if (*tmp > e->start){
                    possible = false;
                    break;
                }
            }

            e->parent = parent;
            *tmp = e->end;
        }

        cout << "Case #" << s << ": ";
        if (possible){
            for (int i = 0; i < activities; i++){
                if (events[i].parent){
                    cout << 'J';
                } else {
                    cout << 'C';
                }
            }
        } else {
            cout << "IMPOSSIBLE";
        }
        cout << endl;
    }

    return 0;
}