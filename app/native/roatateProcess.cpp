#include <nan.h>
#include <utility>
#include <cassert>
#include <vector>
#include<iostream>
#include<array> 
class rotateArray
    {
public:    
template <class T, int N>
void rotateInplace(T (&arr)[N], int M) {
 
	assert(M < N);
    using std::swap;
	for (int i= 0; i < M >> 1; i++) swap( arr[M - i - 1], arr[i]);
    auto dist = N - M;
	for (int i= 0; i< dist >> 1; i++) swap(arr[M + i], arr[N - i - 1] );
    for (int i= 0; i< N >> 1; i++) swap(arr[i], arr[N - i - 1]);
}
template <class T, int N>
void rotateMod(T (&arr)[N], int M)
{
    int result[N];
    for (int i = 0; i < N; i++)result[(i + M) % N] = arr[i];
    for (int i = 0; i < N; i++)arr[i] = result[i];
    }
template <class T, int N>
int * rotateReturn(T (&arr)[N], int M)
{
   static int result[N];
    int j = 0; 
    for (int i= M; i < N; i++, j++)result[j] = arr[i]; 
    for (int i = 0; i < M; i++, j++)result[j] = arr[i];
    return result; 
}

};