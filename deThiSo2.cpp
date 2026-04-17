#include <stdio.h>

void nhapMang(int a[], int &n){
    for(int i = 0;i < n;i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void inMang(int a[], int n){
    for(int i = 0;i < n;i++){
        printf("%d ", a[i]);
    }
}
int tinhGT(int n){
    int s = 1;
    for(int i = 0;i < n;i++){
        s = s*i;
    }
    return s;
}
int tinhTongGT(int a[], int n){
    int s = 0;
    for(int i = 0;i < n;i++){
        s = s * tinhGT(a[i]);
    }
    return s;
}
int timKiemX(int a[], int n, int x){
    for(int i = 0;i < n;i++){
        if(a[i] == x){
            return i;
        }
    }
    return -1;
}
void timKiem(int a[], int n){
    int x;
    printf("Nhap gia tri can tim: "); scanf("%d", &x);
    int i = timKiemX(a, n, x);
    if(i == -1) printf("Khong ton tai x");
    else printf("%d o vi tri %d", x, i);
}
int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    int a[n];
    
    nhapMang(a, n);
    inMang(a, n);
    
    tinhTongGT(a, n);
    timKiem(a, n);
    return 0;
}