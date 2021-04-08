// CPP Program to perform binary search using pthreads
#include <iostream>
#include <fstream>
using namespace std;

// size of array
#define MAX 1000

// maximum number of threads
#define MAX_THREAD 4

// array to be searched
int a[1000] ;

int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

// key that needs to be searched
int key = 69420;
bool found = false;
int part = 0;

void inp()
{
	int i = 0 ;
  	fstream b("data.txt", std::ios_base::in);
  	while(b >> a[i] ){
      	i++;
   }
	qsort(a, MAX, sizeof(int), compare);
}


void* binary_search(void* arg)
{

	
	int thread_part = part++;
	int mid;

	int low = thread_part * (MAX / MAX_THREAD);
	int high = (thread_part + 1) * (MAX / MAX_THREAD);

	// search for the key until low < high
	// or key is found in any portion of array
	while (low < high && !found) {

		// normal iterative binary search algorithm
		mid = (high - low) / 2 + low;

		if (a[mid] == key) {
			found = true;
			break;
		}

		else if (a[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
}


// Driver Code
int main()
{
	inp();
	
	pthread_t threads[MAX_THREAD];

	for (int i = 0; i < MAX_THREAD; i++)
		pthread_create(&threads[i], NULL, binary_search, (void*)NULL);

	for (int i = 0; i < MAX_THREAD; i++)
		pthread_join(threads[i], NULL);

	// key found in array
	if (found)
		cout << key << " found in array" << endl;

	// key not found in array
	else
		cout << key << " not found in array" << endl;

	return 0;
}

