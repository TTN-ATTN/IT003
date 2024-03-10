#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
const int N = 1000000;

// == HEAP SORT == //

void heapify(float arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest);
    }
}
 
void HeapSort(float arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0);
    }
}

// == QUICK SORT == //

void QuickSort(float a[], int l, int r)
{
    float p = a[(l+r)/2];
    int i = l, j = r;
    while(i < j)
    {
        while(a[i] < p)
            i++;
        while(a[j] > p)
            j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }

    }
    if(i < r)
        QuickSort(a, i, r);
    if(l < j)
        QuickSort(a, l, j);
}

// == MERGE SORT == //

void merge(float a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    float L[n1], R[n2];
    
    for(int i = 0; i < n1; i++)
        L[i] = a[l+i];
    for(int i = 0; i < n2; i++)
        R[i] = a[m+i+1];
    
    int i, j, k;
    i = j = 0;
    k = l;
    
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while(i < n1)
        a[k++] = L[i++];
         
    while(j < n2)
        a[k++] = R[j++];
        
}

void MergeSort(float a[], int l , int r)
{
    if(l < r)
    {
        int m = l + (r - l)/2;
        MergeSort(a, l, m);
        MergeSort(a, m+1, r);
        if(a[m] > a[m+1])
            merge(a, l, m, r);
    }
}

// === SOLVE === //

void Solve(int idx)
{
    string types[4] = {"stl sort", "heap sort", "merge sort", "quick sort"};
    cout << types[idx] << '\n';
    for(int t = 1; t <= 10; t++){
        
        string f = "test_" + to_string(t) + ".txt";
        freopen(f.c_str(), "r", stdin);

        float* tests = new float[N];
        for(int i = 0; i < N; i++)
            cin >> tests[i];
        
        // for(int i = N - 1; i > N - 1 - 10; i--)
        //     cout << tests[i] << ' ';
        // cout << '\n';
        auto start = high_resolution_clock::now();

        switch(idx)
        {
            case 0:
                sort(tests, tests + N);
                break;
            case 1:
                for(int i = N/2-1; i >= 0; i--)
                    heapify(tests, N, i);
                HeapSort(tests,N);
                break;
            case 2: 
                MergeSort(tests, 0, N - 1);
                break;
            default:
                QuickSort(tests, 0, N - 1);
        }
        
        auto end = high_resolution_clock::now();
        auto len = duration_cast<milliseconds>(end - start);
        cout << "Sorting time of test " << t << " : " << len.count() << " ms\n";
        delete[] tests;
    }
}

int main()
{
    for(int i = 0; i < 4; i++)
        Solve(i);
    return 0;
}
