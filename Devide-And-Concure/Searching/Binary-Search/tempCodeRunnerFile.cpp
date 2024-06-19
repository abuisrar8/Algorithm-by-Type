#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right);
void mergeSort(vector<int> &arr, int left, int right);
void print(const vector<int>& arr);
void print(const vector<int>& arr, int x);
vector<int> binarySearch(const vector<int>& arr, int low, int high, int x, vector<int>& ans);

vector<int> binarySearch(const vector<int>& arr, int low, int high, int x, vector<int>& ans)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            ans.push_back(mid + 1);
            return binarySearch(arr, low, mid - 1, x, ans);
            return binarySearch(arr, mid + 1, high, x, ans);
            return ans;
        }
        if (arr[mid] > x) return binarySearch(arr, low, mid - 1, x, ans);
        else return binarySearch(arr, mid + 1, high, x, ans);
    }
    ans.clear();