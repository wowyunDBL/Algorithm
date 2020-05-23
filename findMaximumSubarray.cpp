/* maximum subarray
   divide-and-conquer
*/

#include<iostream>
using namespace std;

struct MaxSubarray{
	int maxLeftIndex;
	int maxRightIndex;
	int maxSum;
};

MaxSubarray findMaxCrossingSubarray(int *A, int low, int mid, int high) {
	MaxSubarray maxSubarray;
	
	// left
	int leftSum = INT_MIN;
	for(int sum=0, i=mid; i>=0; i--) {
		sum += A[i];
		if( sum>leftSum ) {
			leftSum = sum;
			maxSubarray.maxLeftIndex = i;
		}
	}
	
	// right
	int rightSum = INT_MIN;
	for(int sum=0, i=mid+1; i<=high; i++) {
		sum += A[i];
		if( sum>rightSum ) {
			rightSum = sum;
			maxSubarray.maxRightIndex = i;
		}
	}
	
	maxSubarray.maxSum = leftSum + rightSum;
	return maxSubarray;
}

MaxSubarray findMaximumSubarray(int *A, int low, int high) {
	if( low==high ) {
		return MaxSubarray{low, high, A[low]}; // base case: only one element
	} else {
		int mid = (low+high)/2;
		MaxSubarray L = findMaximumSubarray(A, low, mid);
		MaxSubarray R = findMaximumSubarray(A, mid+1, high);
		MaxSubarray C = findMaxCrossingSubarray(A, low, mid, high);
		
		if( L.maxSum>R.maxSum && L.maxSum>C.maxSum ) {
			return L;
		} else if ( R.maxSum>L.maxSum && R.maxSum>C.maxSum ) {
			return R;
		} else {
			return C;
		}
	}
}

int main(void){
	// array
	int n;
	int *p;
	
	cin>>n;
	p = new int [n];
	for(int i=0; i<n; i++) {
		cin>>p[i];
	}
	
	MaxSubarray maxSubarray = findMaximumSubarray(p, 0, n-1);
	cout<<maxSubarray.maxLeftIndex<<" "<<maxSubarray.maxRightIndex<<" "<<maxSubarray.maxSum<<endl;
	
	return 0;
}
