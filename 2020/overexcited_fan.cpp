#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int y;
};

void nextMove(Point* p, char dir){
    if (dir == 'S'){
        p->y -= 1;
    } else if (dir == 'N'){
        p->y += 1;
    } else if (dir == 'E'){
        p->x += 1;
    } else {
        p->x -= 1;
    }
}

int BFS(Point dst, string moves){
    for (int i = 1; i <= moves.length(); i++){
        nextMove(&dst, moves[i-1]);

        int dist = abs(dst.x) + abs(dst.y);

        if (dist > i){
            continue;
        }

        return i;
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;
    for (int s = 1; s <= cases; s++){
        Point p;
        string str;
        cin >> p.x >> p.y >> str;
        
        int  result = BFS(p, str);
        if (result != -1){
            cout << "Case #" << s << ": " << result << "\n";
        } else {
            cout << "Case #" << s << ": IMPOSSIBLE\n";
        }
        
    }

    return 0;
}