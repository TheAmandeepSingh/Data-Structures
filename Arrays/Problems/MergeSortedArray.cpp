/**
 * Merge the sorted array
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
	vector<int> nums;
	
	int i(0), j(0);
	
	while(i < a.size() && j < b.size()){
		
		if(a[i] < b[j])
		{
			nums.push_back(a[i]);
			++i;
		} else if(a[i] > b[j]){
			nums.push_back(b[j]);
			++j;
		} else if(a[i] == b[j]){
			nums.push_back(a[i]);
			nums.push_back(a[i]);
			++i;
			++j;
		}
	}
	
	if(i != a.size()){
		nums.insert(std::end(nums), std::begin(a) + i-1, std::end(a));
	}

	if(j != b.size()){
		nums.insert(std::end(nums), std::begin(b) + i-1, std::end(b));
	}
	
	return nums;
	
}

int main(){
    vector<int> a{1, 2, 5, 6};
    vector<int> b{2, 3, 5, 7, 8};
    vector<int> nums = mergeSortedVectors(a, b);
    return 0;
}