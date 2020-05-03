#include <bits/stdc++.h>

using namespace std;

struct Idol {
    int index;
    int value;
};

struct Char{
    bool value = false;
    int twin = -1;
};

int getBit(int index){
    int bit;
    cout << (index + 1) << endl;
    cin >> bit;
    return bit;
}

void printChar(bool* bits, int length){
    for (int i = 0; i < length; i++){
        cout << bits[i];
    }
    cout << endl;
}

bool loadChar(bool* bits, int length, int* bitsLoaded, Idol* twin, Idol* diff, int* index, bool* odd){
    bits[*index] = getBit(*index);
    *bitsLoaded += 1;

    if (*odd == true){
        *index = length - 1 - *index;
    } else {
        int tmp = length - 1 - *index;

        if (bits[tmp] == bits[*index]){
            if (twin->index == -1){
                twin->index = tmp;
                twin->value = bits[tmp];
            }
        } else {
            if (diff->index == -1){
                diff->index = tmp;
                diff->value = bits[tmp];
            }
        }

        *index = length - *index;
    }
    *odd = !(*odd);

    if ((*bitsLoaded) >= length){
        return true;
    }

    return false;
}

void traverse(bool* bits, int length, int* query, int* bitsLoaded, Idol* twin, Idol* diff, int* index, bool* odd){
    int tValue = twin->value;
    int dValue = diff->value;
    if (twin->index != -1){
        twin->value = getBit(twin->index);
        *query += 1;
    }
    if (diff->index != -1){
        diff->value = getBit(diff->index);
        *query += 1;
    }

    bool tChange = tValue != twin->value;
    bool dChange = dValue != diff->value;
    if (tChange || dChange){
        if (((*bitsLoaded) % 2) == 1){
            *bitsLoaded -= 1;
            *index = length - 1 - *index;
            *odd = !(*odd);
        }

        for (int i = 0; i < ((*bitsLoaded) / 2); i++){
            int opp = length - 1 - i;

            if (bits[i] == bits[opp]){
                if (tChange == true){
                    bits[i] = !bits[i];
                    bits[opp] = !bits[opp];
                }
            } else {
                if (dChange == true){
                    bits[i] = !bits[i];
                    bits[opp] = !bits[opp];
                }
            }
        }
    }

}

int main(){
    int cases, length;
    cin >> cases >> length;
    
    for (int s = 0; s < cases; s++){
        Idol twin = {-1, -1};
        Idol diff = {-1, -1};
        bool arr[length];

        int index = 0;
        bool odd = true;
        int query = 0;
        int bitsLoaded = 0;
        while (query < 150){
            if (query % 10 == 0){
                traverse(arr, length, &query, &bitsLoaded, &twin, &diff, &index, &odd);
            }

            if (loadChar(arr, length, &bitsLoaded, &twin, &diff, &index, &odd)){
                break;
            }

            query++;
        }

        printChar(arr, length);
        char answer;
        cin >> answer;
        if (answer == 'N'){
            exit(1);
        }
    }

    return 0;
}