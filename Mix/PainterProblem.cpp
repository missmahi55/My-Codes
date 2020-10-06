/*We have to paint n boards of length {A1, A2…An}. 
There are k painters available and each takes 1 unit time to paint 1 unit of board. 
The problem is to find the minimum time to get
this job done under the constraints that any 
painter will only paint continuous sections of boards, 
say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}*/

#include <climits> 
#include <iostream> 
using namespace std; 

int sum(int arr[], int from, int to) 
{ 
	int total = 0; 
	for (int i = from; i <= to; i++) 
		total += arr[i]; 
	return total; 
} 

int partition(int arr[], int n, int k) 
{ 
	// base cases	 
	if (k == 1) // one partition 
		return sum(arr, 0, n - 1);	 
	if (n == 1) // one board 
		return arr[0]; 

	int best = INT_MAX; 

	for (int i = 1; i <= n; i++) 
		best = min(best, max(partition(arr, i, k - 1), 
								sum(arr, i, n - 1))); 

	return best; 
} 

int main() 
{ 
	int arr[] = { 10, 20, 60, 50, 30, 40 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 3; 
	cout << partition(arr, n, k) << endl; 

	return 0; 
} 
