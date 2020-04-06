#include <iostream> 
#include "Sort.h"
#include <chrono>

using namespace std;


int main() {
		chrono::steady_clock time;
		int N = 50;
		int *arr;
		arr = new int[N];
		for (int i = 0; i < N; ++i)
			arr[i] = rand() % N;
		for (int i = 0; i < N; ++i)
			cout << arr[i] << " ";
		cout << endl;
		auto start = time.now();
		for (int i = 0; i < N; ++i)
			choisesSort(arr, N);   
			//bubbleSort(arr, N);     
			//shellSort(arr, N);     
			//quickSort(arr, N);
			//mergingSort(arr, N);
		auto end = time.now();
		chrono::duration<double> diff = end - start;
		cout << diff.count() / 100 << endl;
		for (int i = 0; i < N; ++i)
			cout << arr[i] << " ";
		cout << endl;

	getchar();
}