//approach 1
 
void sort012(int *arr, int n)
{
   //   Write your code here
    int zeros=0, ones=0, twos=0;
    for(int i=0; i<n; i++){
        if(arr[i] == 0) zeros++;
        else if(arr[i] == 1) ones++;
        else twos++;
    }
    int i=0;
    while(i<n){
        while(zeros--) {
            arr[i] = 0;
            i++;
        }
        while(ones--) {
            arr[i] = 1;
            i++;
        }
        while(twos--) {
            arr[i] = 2;
            i++;
        }
    }
}


//approach 2 - Dutch national flag algo

void sort012(int *arr, int n)
{
   //   Write your code here
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        switch(arr[mid]){
            case 0:
                swap(arr[mid], arr[low]);
                mid++, low++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[high], arr[mid]);
                high--;
                break;
        }
    }
}
