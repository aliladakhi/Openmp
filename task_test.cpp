#include <iostream> 
#include <cmath>
#include <algorithm>
#include <utility>
#include <omp.h>
#include <bits/stdc++.h>

using namespace std;

pair<int, int> ceilLog2(int n) {
    double log2_n = log2(n);
    int ceil_log2_n = ceil(log2_n);

    int length = pow(2, ceil_log2_n);

    return std::make_pair(ceil_log2_n, length);
}

int main() {
    int x = 99999;

    int arr1[x];

    #pragma omp parallel for
    for (int i = 0; i < x; i++) {
        arr1[i] =  1; 
    }

    pair<int, int> mypair = ceilLog2(x);
    
    int height = mypair.first;
    int length = mypair.second;

    std::cout << "length " << length << endl << "height  " << height << endl;
    int arr2[length];

    std::copy(arr1, arr1 + x, arr2);

    for (int i = x; i < length; i++) {
        arr2[i] = 0;
    }

    int counter = 0;

    #pragma omp parallel
    {
    #pragma omp single
        {
            for (int l = height - 2; l >= 0; l--) {
                int x = pow(2, l) - 1;
                int y = pow(2, l + 1) - 1; 
                for (int i = x; i < y; i++) {
                    int leftChild = 2 * i + 1;
                    int rightChild = 2 * i + 2;
                    #pragma omp task depend(in : arr2[leftChild], arr2[rightChild]) depend(out : arr2[i])
                    {
                        arr2[i] = arr2[i] + arr2[leftChild] + arr2[rightChild];
                        #pragma omp atomic
                        counter++;
                    }
                }
            }
        }
    }

    cout << arr2[0] << std::endl;
    cout << "Total number of tasks created: " << counter << std::endl;

    return 0;
}
