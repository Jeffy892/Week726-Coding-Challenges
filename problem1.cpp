#include <iostream>
#include <vector>
using namespace std;


void findSubArray(vector<int>arr, int n, int sum) {

    int curr_sum, i, j;
 
    for (i = 0; i < n; i++) {
        curr_sum = arr[i];
 
        for (j = i + 1; j < n; j++) {
            if (curr_sum == sum) {
                cout << " Sum are added from indexes " << i << " and " << j - 1;
                return;
            }
            if (curr_sum > sum)
                break;
            curr_sum = curr_sum + arr[j];
        }
    }
 
    cout << "No subarray found";

}



int main() {
    int n;
    int k;
    cin >> n;
    cin >> k;
    vector<int> arr;
    for(int i = 0 ; i < n ; ++i) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    findSubArray(arr,n, k);
}