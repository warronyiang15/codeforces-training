#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <assert.h>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <set>
 
#define INT_MAX 2147483647
#define INT_MIN -2147483648
 
using namespace std;
 
typedef long long int ll;
const int modulo = 1e9+7;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin >> n;
    ll a[n];
    ll min_ = -1;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        if(min_ == -1 || a[i] < a[min_]){
            min_ = i;
        }
    }
    ll arr[n];
    int nextMin = min_;
    int count = 0;
    for(int i = n - 1;i>=0;i--){
        if(a[i] == a[min_]){
            arr[i] = 0;
        }
        else if(a[i] != a[min_] && i == n - 1){
            arr[i] = n - i + nextMin;
        }
        else if(a[i] != a[min_]){
            if(a[i + 1] == a[min_]){
                arr[i] = 1;
            }else arr[i] = arr[i + 1] + 1;
        }
    }
    ll ans = 0;
    for(int i = 0;i<n;i++){
        ans = max(ans,a[min_] * n + arr[i]);
    }
    cout << ans << endl;
    return 0;
}

/*
    the first minimum must be the break points of the *turn*.
    which means we could instantly know that we can run though how many turn (which is a[min] * n times)
    and for each element where a[i] != min , the break point of last turn must be at the next minimum(where same as min). { Could be prove by example }
    So for this question find out first min, construct nextMin for all elements for fast checking,
    then the answer will be max{ans,a[min] * n + nextMin[i]}
*/

