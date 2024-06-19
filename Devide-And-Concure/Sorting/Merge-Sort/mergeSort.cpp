#include<iostream>
#include<vector>
#include<string>
#include <sstream>


using namespace std;

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
void print(vector<int> &arr)   
{
    for(auto i: arr) cout<<i<<" ";
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
    mergeSort(input,0,input.size()-1);
    print(input);

    return 0;
}

