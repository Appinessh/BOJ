#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
vector <int> arr;
vector <vector<int>> lst;
vector <int> ans;
int n;
int index;
void update(int new_number)
{
    if(lst[0].empty())
    {
        lst[0].push_back(new_number);
        index=0;
        return ;
    }
    int left=0;
    int right=index;
    int mid;
    while(left!=right-1&&left!=right)
    {
        mid=(left+right)/2;
        if(lst[mid][lst[mid].size()-1]>new_number)
        {
            right=mid;
        }
        else if(lst[mid][lst[mid].size()-1]==new_number)
        {
            break;
        }
        else
        {
            left=mid;
        }
    }
    if(lst[mid][lst[mid].size()-1]==new_number)
    {
        
    }
    else if(lst[right][lst[right].size()-1]==new_number)
    {
        
    }
    else if(lst[left][lst[left].size()-1]==new_number)
    {
        
    }
    else if(lst[right][lst[right].size()-1]<new_number)
    {
        index++;
        lst[index].push_back(new_number);
    }
    else if(lst[left][lst[left].size()-1]>new_number)
    {
        lst[0].push_back(new_number);
    }
    else
    {
        lst[right].push_back(new_number);;
    }
    return ;
}
void answer(void)
{
    int limit=INT_MAX;
    ans.resize(index+1);
    for(int i=index;i>=0;i--)
    {
        for(int j=0;j<lst[i].size();j++)
        {
            if(limit>lst[i][j])
            {
                limit=lst[i][j];
                ans[i]=lst[i][j];
                break;
            }
        }
    }
    cout<<index+1<<"\n";
    for(int i=0;i<=index;i++)
    {
        cout<<ans[i]<<" ";
    }
    return ;
}
int main()
{
    cin>>n;
    arr.resize(n);
    lst.resize(n);
    index=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        update(arr[i]);
    }
    answer();
    return 0;
}