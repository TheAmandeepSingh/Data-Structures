/**
 * Merge the two sorted array
 * a = [1 2 5 6]
 * b = [2 3 5 7]
 * 
 * c = [1 2 2 3 5 5 6 7]
 * 
 * */

#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedVectors(const vector<int>& a, const vector<int>& b){
	vector<int> nums(a.size() + b.size(), 0);
	
	int i(0), j(0), k(0);
	
	while(i < a.size() && j < b.size()){
		
		if(a[i] < b[j])
		{
			nums[k++] = a[i++];
		} else if(a[i] > b[j]){
			nums[k++] = a[j++];
		} else if(a[i] == b[j]){
			nums[k++] = a[i++];
			nums[k++] = a[j++];
		}
	}

	while(i < a.size()){
		nums[k++] = a[i++];
	}

	while(j < b.size()){
		nums[k++] = a[j++];
	}
	
	return nums;
}

int main(){
    vector<int> a{1, 2, 5, 6};
    vector<int> b{2, 3, 5, 7, 8};
    vector<int> nums = mergeSortedVectors(a, b);
	for(auto n : nums){
		cout << n << " ";
	}
    return 0;
}