// 给定一个非负整数数组和一个整数 m，
// 你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。
#include<iostream>
#include<vector>
using namespace std;

int minSum(vector<int> nums,int m){
	int left=0;
	int right=0;
	for(int n:nums){
		left=max(left,n);
		right+=n;
	}
	while(left<right){
		int mid=left+right/2;
		int need=1;
		int cur=0;
		for(int i=0;i<nums.size();i++){
			if(cur+nums[i]>mid){
				cur=0;
				need++;
			}
			cur+=nums[i];
		}
		if(need>m){
			left=mid+1;
		}
		else{
			right=mid;
		}
	}
	return left;
}