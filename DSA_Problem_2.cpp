#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(int tickets[], int n, int k) {
        queue<int> q;  // queue to store people's positions in line

        // initially, everyone stands in line in the given order
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        int time = 0;  // total time counter

        // keep running the process until person k is done buying
        while (!q.empty()) {
            int i = q.front();  // person at the front of the line
            q.pop();            // they will buy one ticket
            tickets[i]--;       // reduce their ticket count
            time++;             // buying one ticket takes 1 second

            // if this is the person we are tracking (k)
            // and they just bought their last ticket, we can stop
            if (i == k && tickets[i] == 0) {
                return time;
            }

            // if this person still has more tickets to buy,
            // they go back to the end of the line
            if (tickets[i] > 0) {
                q.push(i);
            }
        }

        return time;
    }
};

int main() {
    Solution sol;
    int n, k;

    cout << "Enter number of people: ";
    cin >> n;

    int *tickets = new int[n];
    cout << "Enter number of tickets each person wants: ";
    for (int i = 0; i < n; i++) {
        cin >> tickets[i];
    }

    cout << "Enter index of the person you want to track: ";
    cin >> k;

    // call the function and display the time taken
    cout << "Total time needed: " << sol.timeRequiredToBuy(tickets, n, k);

    delete[] tickets;  // free memory
    return 0;
}
