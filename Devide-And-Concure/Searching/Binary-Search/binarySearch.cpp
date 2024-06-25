#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

void print(vector<int>& arr);
void print(int pos,int x);

int binarySearch(const vector<int>& arr, int low,int high,int x)
{
    if (low <= high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid] == x)   return mid+1;
        if(arr[mid]>x)  return binarySearch(arr,low,mid-1,x);
        return binarySearch(arr,mid+1,high,x);
    }
    return -1;
}

int main()
{
    string in,i;
    vector<int> input;
    
    getline(cin,in);
    stringstream str(in);
    while (getline(str,i,' ')) input.push_back(stoi(i));

    cout<<"Enter element to search : ";
    int x;
    cin>>x;
    
    //mergeSort(input,0,input.size()-1);
    sort(input.begin(),input.end());
    print(input);
    print(binarySearch(input,0,input.size()-1,x),x);

    
    
    return 0;
}

void print(vector<int>& arr)
{
    for(auto &i : arr)
    {
        cout<<i;
        if (i != arr.back())
        {
            cout<<" ,";
        }
    }
    cout<<"\n";

}
void print(int pos,int x)
{
    if(pos == -1) 
    {
        cout<<" no element as "<<x<<" .\n";
        return;
    }
    cout<<x<<" found at position "<<pos<<" .\n";
}