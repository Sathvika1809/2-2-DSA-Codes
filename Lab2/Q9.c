#include <stdio.h>

void swap(int* a,int* b){
    int temp = *a;
    *a =*b;
    *b = temp;
}
void bubblesort(int* a,int n){
    for(int i =0;i<n;i++){
        int didSwap =0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                didSwap = 1;
            }
        }
        if(!didSwap){
            break;
        }
    }
}
void countevenodd(int* arr,int n){
    int even = 0;
    int odd = 0;
    for(int i=0;i<n;i++){
        if(i%2==0 && arr[i]%2==0){
            even++;
        }
        if(i%2 == 1 && arr[i]%2==1){
            odd++;
        }
    }
    printf("%d,%d",even,odd);
}
int main(){
    int n;
    printf("Enter the size of the Array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the Array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,n);
    countevenodd(arr,n);


}