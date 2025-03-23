//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

#include <iostream>
#include <vector>

using namespace std;

int SearchInsert(vector<int>& nums, int target) {
    int len=nums.size();
    int l=0,r=len-1;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(nums[mid]<target) l=mid+1;
        else r=mid;
    }
    if(nums[l]==target) return l;
    return -1;
}

int main()
{
    vector<int> nums={1,3,5,6};
    int target=5;
    int res=SearchInsert(nums,target);
    cout<<res<<endl;
    return 0;
}