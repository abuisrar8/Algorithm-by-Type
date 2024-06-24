#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
void merge(vector<int> &arr, int left,int mid,int right);
void mergeSort(vector<int> &arr,int left,int right);
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

void merge(vector<int> &arr, int left,int mid,int right)
{
    int n1 = mid-left+1;
    int n2 = right-mid;
    vector<int> l(n1),r(n2);

    for (int i = 0; i < n1; i++) l[i] = arr[left + i];
    for (int i = 0; i < n2; i++) r[i] = arr[mid + 1 + i];

    int i,j=i=0,k=left;
    while (i < n1 && j < n2)    
        if (l[i] <= r[j]) arr[k++] = l[i++];
        else arr[k++] = r[j++];
    

    while (i < n1) arr[k++] = l[i++];
    while (j < n2) arr[k++] = r[j++];
}
void mergeSort(vector<int> &arr,int left,int right)
{
    if (left>=right) return;

    int mid = left + (right - left)/2 ;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
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