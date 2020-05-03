#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases;
    cin >> cases;
    getchar();

    int sample = 0;
    for (int s = 0; s < cases; s++){
        sample += 1;
        cout << "Case #" << sample << ": ";

        string num;
        getline(cin, num);
        
        int prev = 0;
        int next = 0;
        int parentheses;
        for (int i = 0; i < num.length(); i++){
            prev = next;
            next = num[i] - '0';
            parentheses = prev - next;

            if (parentheses < 0){
                while (parentheses != 0){
                    cout << '(';
                    parentheses += 1;
                }
            } else if ( parentheses > 0){
                while (parentheses != 0){
                    cout << ')';
                    parentheses -= 1;
                }
            }

            cout << num[i];
        }

        for (int i = 0; i < next; i++){
            cout << ')';
        }
        cout << endl;
    }

    return 0;
}