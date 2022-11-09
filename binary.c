#include <stdio.h>

int BinarySearch(int arr[],int n,int element){
    int low,mid,high;
    low = 0;
    high = n-1;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}
int main(){
    int n,element;
    printf("Enter the number of elements");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements i sorted order");
    for(int i=0 ; i<n ;i++){
        scanf("%d",&arr[i]);
    }
    int check = BinarySearch(arr,n,element);
    if(check==element){
        printf("Element found");
    }
    else{
        printf("element not found");
    }

}