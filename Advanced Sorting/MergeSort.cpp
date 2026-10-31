#include <iostream>
using namespace std;
void merge(int *,int, int , int );

void merge_sort(int *arr, int start, int end)
{
    int mid;
    if (start < end){
        //divide the array at mid and sort independently using merge sort
        mid=(start+end)/2;
        merge_sort(arr,start,mid); // left
        merge_sort(arr,mid+1,end); // right
        //merge or conquer sorted arrays
        merge(arr,start,end,mid);
    }
}
// Merge sort 
void merge(int *arr, int start, int end, int mid)
{
    int i, j, k, c[30];
	
	//i → first element of left subarray
    //j → first element of right subarray
    //k → position in temporary array
	
    i = start;
    k = start;
    j = mid + 1;

    // merge both sorted halves
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
	
//  The remaining elements of the left side of the array are now coping :	
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    
//  The remaining elements of the right side of the array are now coping :		
	while (j <= end) {
        c[k] = arr[j];
        k++;
        j++;
    }
   
   for (i = start; i < k; i++)  {
        arr[i] = c[i];
    }
}
// read input array and call mergesort
int main()
{
    int myarray[30], num;
    cout<<"Enter number of elements to be sorted:";
    cin>>num;
    cout<<"Enter "<<num<<" elements to be sorted:";
    for (int i = 0; i < num; i++) 
		{ 
			cin>>myarray[i];
		}
    
	merge_sort(myarray, 0, num-1);
    
	cout<<"Sorted array\n";
    for (int i = 0; i < num; i++)
    {
        cout<<myarray[i]<<"\t";
    }
}
