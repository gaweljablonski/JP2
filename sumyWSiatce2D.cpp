#include <bits/stdc++.h>

using namespace std;

void print2d(vector<vector<int>> &a)
{
    int wys = a.size();
    int szer = a[0].size();
    for(int i = 0; i < wys; i++)
    {
        for(int j = 0; j < szer; j++)
            cout << a[i][j] << "\n";
        cout << endl;
    }
}
void vectorIntPrint(vector<int> &vector)
{
    if(!vector.size())
        return;
    for (int element : vector)
        // cout << element << "/n";
        printf("%d\n", element);
}

int main() {

    int n, m, q;
    // cin >> n >> m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> siatka(n);
    vector<vector<int>> pref(n+1);
    for(int i = 0; i < n; i++)
    {
        siatka[i].resize(m);
        pref[i].resize(m+1);
    }
    pref[n].resize(m+1);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            // cin >> siatka[i][j];
            scanf("%d", siatka[i][j]);
    /*
    cout << endl;
    print2d(siatka);
    cout << endl;
    print2d(pref);
*/
    int licz = 1;
    for(int r = 1; r <= n; r++)
    {
        for(int c = 1; c <= m; c++)
        {
            // printf("%d %d %d\n", licz++, r, c);
            pref[r][c] = siatka[r-1][c-1]+pref[r-1][c]+pref[r][c-1]-pref[r-1][c-1];
        }
    }
    int r1, r2, c1, c2, o;
    cin >> q;
    vector<int> odp(q);
    for(int i = 0; i < q; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        o = pref[r2][c2]-pref[r2][c1-1]-pref[r1-1][c2]+pref[r1-1][c1-1];
        odp[i] = o;
    }
    vectorIntPrint(odp);
    


    return 0;
}