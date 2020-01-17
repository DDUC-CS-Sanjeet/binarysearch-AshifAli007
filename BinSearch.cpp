/*  Name    : Mohd Ashif
    course  : Bsc(h)CS
    Year    : 1st  */
#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchRecursive(int* array, int startIndex, int lastIndex, int element)
{
	int mid = (startIndex + lastIndex )/2;
	if(startIndex <= lastIndex){
			if(array[mid] == element){
				return true;
			}
			else if(array[mid] < element){
				return binarySearchRecursive(array , mid+1 , lastIndex,element);
			}
			else{
				return binarySearchRecursive(array ,startIndex , mid-1,element);
			}
	}

  	return false;
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{	int mid;
	while(startIndex <= lastIndex){
		mid = (startIndex + lastIndex)/2;
		if(array[mid] == element){
			return true;
		}
		else if(array[mid] < element){
			startIndex = mid+1;
		}
		else{
			lastIndex = mid-1;
		}
	}
  	return false;
}

int main()
{		int  n,element;
		bool result_recursion,result_iterative;
		cout<<"Enter The size of Array : ";
		cin>>n;
		int arr[n];
		
		cout<<"\nEnter "<<n<<" Elements Of Array :-\n";
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		sort(arr,arr+n);
		cout<<"\nEnter The Element You Want to search : ";
		cin>>element;
		result_recursion = binarySearchRecursive(arr,0,n-1,element);
		result_iterative = binarySearchIterative(arr,0,n-1,element);
		cout<<"Given Array After Sorting Is : ";
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\nResult Of Search using Recursion : ";
		if(result_recursion == 1){
			cout<<"True (Element Exist)";
		}else{
			cout<<"False (Element Not Found)";
		}
		cout<<"\nResult Of Search Using Iteration : ";
		if(result_iterative == 1){
			cout<<"True (Element Exist)";
		}else{
			cout<<"False (Element Not Found)";
		}
		
		return 0;
}
