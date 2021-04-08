// C++ program to implement recursive Binary Search 
#include <bits/stdc++.h> 
#include <fstream>
using namespace std; 
 
int arr[1000];

int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

void inp()
{
	int i = 0 ;
  	fstream b("data.txt", std::ios_base::in);
  	while(b >> arr[i] ){
      	i++;
   }
	qsort(arr, 1000, sizeof(int), compare);
}

// A iterative binary search function. It returns 
// location of x in given array arr[l..r] if present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
	while (l <= r) { 
		int m = l + (r - l) / 2; 

		// Check if x is present at mid 
		if (arr[m] == x) 
			return m; 

		// If x greater, ignore left half 
		if (arr[m] < x) 
			l = m + 1; 

		// If x is smaller, ignore right half 
		else
			r = m - 1; 
	} 

	// if we reach here, then element was 
	// not present 
	return -1; 
} 

int main(void) 
{ 
	inp();
	int x = 69420; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int result = binarySearch(arr, 0, n - 1, x); 
	(result == -1) ? cout << "69420 is not present in array"
				: cout << "69420 is present at index " << result; 
	return 0; 
} 

