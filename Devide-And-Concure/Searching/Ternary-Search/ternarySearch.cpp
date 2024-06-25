#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int ternarySearch(vector<int>& arr,int low,int high,int search)
{
    if(low<=high)
    {
        int mid1 = low+(high-low)/3;
        int mid2 = high-(high-low)/3;

        if(arr[mid1] == search) return mid1+1;
        if(arr[mid2] == search) return mid2+1;
        if(arr[mid1]>search) return ternarySearch(arr,low,mid1-1,search);
        else if (arr[mid2]<search) return ternarySearch(arr,mid2+1,high,search);
        else return ternarySearch(arr,mid1+1,mid2-1,search);

        return -1;
    }
}
void print(vector<int> &arr)
{
    for(auto& i:arr)
    cout<<i<<" ";
    cout<<"\n";
}
void print(int pos,int search)
{
    if (pos == -1)   cout<<search<<" not present in this array. \n";
    else    cout<<search <<" found at position :"<<pos<<".\n";
}
int main()
{
    string in,i;
    vector<int> input;
    
    getline(cin,in);
    stringstream str(in);
    while (getline(str,i,' ')) input.push_back(stoi(i));


    cout<<"enter element to search :";
    int search;
    cin>>search;

    print(input);
    cout<<" after sorting : \n";
    sort(input.begin(),input.end());
    print(input);

    print(ternarySearch(input,0,input.size(),search),search);
    return 0;
}