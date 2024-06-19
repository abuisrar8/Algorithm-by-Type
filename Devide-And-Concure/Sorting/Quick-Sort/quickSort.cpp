#include<iostream>
#include<vector>
#include<string>
#include <sstream>

using namespace std;

int positioningPivot(vector<int>& arr, int low,int high)
{
    int pivot = arr[high];
    int i = low-1;

    for(int j =low;j<high;++j)
    {
        if(arr[j]<=pivot)
        {
            ++i;
            swap(arr[i],arr[j]);
        }
        swap(arr[i+1],arr[high]);

        return i+1;
    }
}
void quickSort(vector<int>& arr,int low,int high)
{
    if(low<high)
    {
        int pivot = positioningPivot(arr,low,high);

        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}
void print(vector<int> &arr)
{
    for (int  i =0;i<arr.size();i++)
    {
        cout<<arr[i];
        if(i != arr.size()-1)
        {
            cout<<", ";
        }
    }
    cout<<"\n";
}
int main()
{
    string in,i;
    vector<int> input;
    
    getline(cin,in);
    stringstream str(in);
    while (getline(str,i,' ')) input.push_back(stoi(i));
    
    print(input);
    quickSort(input,0,input.size()-1);
    print(input);

    return 0;
}