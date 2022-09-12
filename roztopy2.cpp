#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<long long, long long> opady;
    set<long long> wyniki;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        for(long long j = a; j < b; j++)
        {
            opady[j]++;
        }
    }
    for (const auto &kv : opady)
        wyniki.insert(kv.second);
    auto it = --wyniki.end();
    cout << *it;


    return 0;
}