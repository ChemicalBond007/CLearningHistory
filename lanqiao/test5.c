#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Range {
    int start, end;
} Range;
 

Range new_Range(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    return r;
}
 

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
 

void quick_sort(int arr[], const int len) {
    if (len <= 0)
        return;
 
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);
 
    while (p > 0) {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
 
        int mid = arr[(range.start + range.end) / 2];
        int left = range.start, right = range.end;
 
        do {
            while (arr[left] < mid) ++left;
            while (arr[right] > mid) --right;
 
            if (left <= right) {
                swap(&arr[left], &arr[right]);
                left++;
                right--;
            }
        } while (left <= right);
 
        if (range.start < right) r[p++] = new_Range(range.start, right);
        if (range.end > left) r[p++] = new_Range(left, range.end);
    }
}

int cmpmin(int input1, int input2){
    return input1>=input2?input1:input2;
}
int main(){
    int n,i,min[2]={1000,1000},max[2]={0,0};
    scanf("%d",&n);
    int a[n],b[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    quick_sort(a,n);
    quick_sort(b,n);
    if(a[n-1]<=b[0]||b[n-1]<=a[0]){
        printf("%d",abs(a[0]-b[0]));
    }
    else if((a[0]>=b[0]&&a[n-1]<=b[n-1])||(a[0]<=b[0]&&a[n-1]>b[n-1]))
        printf("%d",cmpmin(abs(a[0]-b[0]),abs(a[n-1]-b[n-1])));
    else if((a[0]<=b[0]&&a[n-1]<=b[n-1])||(a[0]>=b[0]&&a[n-1]>=b[n-1]))
        printf("%d",cmpmin(cmpmin(abs(a[0]-b[0]),abs(a[n-1]-b[n-1])),cmpmin(abs(a[n-1]-b[0]),abs(a[0]-b[n-1]))));
    return 0;
}