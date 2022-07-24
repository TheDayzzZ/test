#include<iostream>
#include<vector> 
using namespace std;
void display(vector<int> nums)
{
 	for(int num:nums)
  {
    cout<<num<<" ";
  }
  cout<<endl;
} 
void chooseSort(vector<int>& nums)
{
  int n = nums.size();
  for(int i=0;i<n;i++)
  {
     int minValue = nums[i];
     int minIndex = i;
     for(int j=i;j<n;j++)
    {

      if(nums[j]<minValue)
      {
        minValue = nums[j];
        minIndex = j;
      }
  	}
    swap(nums[i],nums[minIndex]);
	 
  }
}
int random_parition(vector<int>& nums,int left,int right,int randIndex)
{
	cout<<"当前的left与right"<<left<<" "<<right<<endl;
	swap(nums[left],nums[randIndex]);
	int temp = nums[left];
	while(left<right)
	{
		while(left<right&&nums[right]>=temp)
			right--;
		cout<<left<<" "<<right<<endl;
		nums[left] = nums[right];
		while(left<right&&nums[left]<=temp)
			left++;
		cout<<left<<" "<<right<<endl;
		nums[right] = nums[left];  
		right--;
	}
	nums[left] = temp;
	return left;	
}
int parition(vector<int>& nums,int left,int right)
{
	int index = left;
	return random_parition(nums,left,right,index);
	
}
void quickSort(vector<int>& nums,int left,int right)
{
	if(left>=right)
		return ;
	int mid = parition(nums,left,right);
	display(nums);
	quickSort(nums,left,mid-1);
	quickSort(nums,mid+1,right);
} 
int main(void)
{
  vector<int> nums= {3,5,6,1,2};
  quickSort(nums,0,nums.size()-1);
//  chooseSort(nums);
  display(nums);
}
