#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<n; i++){
        if(pq.size() < 10 || arr[i] > pq.top())
            pq.push(arr[i]);
        while(pq.size() > 10)
            pq.pop();
    }
    for(int i = 0; i < 10; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
