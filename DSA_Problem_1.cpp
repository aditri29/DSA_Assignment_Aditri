#include <iostream>
using namespace std;

class Solution {
public:
    // function to find minimum of two numbers
    int minVal(int a, int b) {
        return (a < b) ? a : b;
    }

    // main logic to find the maximum area of water container
    int maxArea(int height[], int n) {
        int left = 0;             // pointer starting from left side
        int right = n - 1;        // pointer starting from right side
        int max_area = 0;         // to store the maximum area found

        while (left < right) {
            // find height and width for current pair
            int h = minVal(height[left], height[right]);
            int w = right - left;

            // calculate current area
            int area = h * w;

            // update if current area is greater than previous maximum
            if (area > max_area)
                max_area = area;

            // move the pointer which has smaller height
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return max_area;  // return the final maximum area
    }
};

int main() {
    Solution s;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int height[n];
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++)
        cin >> height[i];

    // calling the function and displaying the answer
    cout << "Maximum area: " << s.maxArea(height, n);

    return 0;
}
