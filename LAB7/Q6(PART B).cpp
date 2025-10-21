#include<iostream>
using namespace std;

 

void merge(int a[], int beg, int mid, int end)   

{   

    int i, j, k; 

    int n1 = mid - beg + 1;   

    int n2 = end - mid;   

     

    int LeftArray[n1], RightArray[n2]; 

      

    for (int i = 0; i < n1; i++)   

    LeftArray[i] = a[beg + i];   

    for (int j = 0; j < n2; j++)   

    RightArray[j] = a[mid + 1 + j];   

     

    i = 0;

    j = 0;

    k = beg; 

     

    while (i < n1 && j < n2)   

    {   

        if(LeftArray[i] <= RightArray[j])   

        {   

            a[k] = LeftArray[i];   

            i++;   

        }   

        else   

        {   

            a[k] = RightArray[j];   

            j++;   

        }   

        k++;   

    }   

    while (i<n1)   

    {   

        a[k] = LeftArray[i];   

        i++;   

        k++;   

    }   

     

    while (j<n2)   

    {    

        a[k] = RightArray[j];   

        j++;   

        k++;   

    }   

}   

 

void mergeSort(int a[], int beg, int end) 

{ 

    if (beg < end)  

    { 

        int mid = (beg + end) / 2; 

        mergeSort(a, beg, mid); 

        mergeSort(a, mid + 1, end); 

        merge(a, beg, mid, end); 

    } 

} 

   

void printArray(int a[], int n) 

{ 

    int i; 

    for (i = 0; i < n; i++) 

        cout<<a[i]<<" "; 

    cout<<"\n"; 

} 

 

int main() 

{ 

    int array1[] = { 12, 34, 6, 78, 33, 9, 59, 0, 31, 99 }; 

    int array2[] = { 45, 60, 1, 39, 89, 11, 26, 90, 23, 56 }; 

    int n1 = sizeof(array1) / sizeof(array1[0]); 

    int n2 = sizeof(array2) / sizeof(array2[0]);

    int sumsize = n1 + n2;

    int combined[sumsize];

    for(int i =0; i<n1; i++){

                combined[i] = array1[i];

                }

                for(int i=0; i<n2; i++){

                                combined[n1+i] = array2[i];

                }

   

    cout<<"Before sorting array 1 the elements are - \n"; 

    printArray(array1, n1); 

    cout<<"Before sorting array 2 the elements are - \n"; 

    printArray(array2, n2);

   

    mergeSort(combined, 0, sumsize - 1); 

    cout<<"After sorting array elements are - \n"; 

    printArray(combined, sumsize); 

    return 0; 


}
