#include <bits/stdc++.h>

using namespace std;

int main(){
    int cases;
    cin >> cases;

    int n;
    int sample = 0;
    for (int i = 0; i < cases; i++){
        sample += 1;
        cin >> n;
        
        int matrix_size = n * n;
        int* ptr = (int*)malloc(matrix_size * sizeof(int));

        int k = 0;
        for (int j = 0; j < matrix_size; j++){
            cin >> *(ptr + j);

            if (j % (n + 1) == 0){
                k += *(ptr + j);
            }
        }

        bool num[n + 1];
        int r = 0;
        for (int row = 0; row < n; row++){
            memset(num, false, sizeof(num));

            int index;
            for (int col = 0; col < n; col++){
                index = *(ptr + n*row + col);

                if (num[index] == false){
                    num[index] = true;
                } else {
                    r += 1;
                    break;
                }
            }
        }

        int c = 0;
        for (int col = 0; col < n; col++){
            memset(num, false, sizeof(num));

            int index;
            for (int row = 0; row < n; row++){
                index = *(ptr + n*row + col);

                if (num[index] == false){
                    num[index] = true;
                } else {
                    c += 1;
                    break;
                }
            }
        }

        free(ptr);
        cout << "Case #" << sample << ": " << k << " " << r << " " << c << endl;
    }

    return 0;
}