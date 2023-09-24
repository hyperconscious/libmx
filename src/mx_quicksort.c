#include "../inc/libmx.h"

void mx_strswap(char **s1, char **s2){
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int mx_partition(char **arr, int left, int right, int *count){
    char *pivot = arr[left + (right - left)/2];

    while(left <= right){
        while(mx_strlen(arr[left]) < mx_strlen(pivot)) left++;
        while(mx_strlen(arr[right]) > mx_strlen(pivot)) right--;

        if(left <= right){
            if(mx_strlen(arr[right]) != mx_strlen(arr[left])){
                mx_strswap(&arr[left], &arr[right]);
                (*count)++;
            }
            left++;
            right--;
        }
    }
    return left;
}

int mx_quicksort(char **arr, int left, int right){
    if(left >= right) return 0;
    int count = 0;
    int border = mx_partition(arr, left, right, &count);

    count += mx_quicksort(arr, left, border - 1);
    count += mx_quicksort(arr, border, right);
    return count;
}

