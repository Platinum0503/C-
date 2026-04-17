#include <stdio.h>

int giaiThua(int n){
    int s = 1;
    for(int i = 2;i < n;i++){
        s = s*i;   
    }
    return s;
}
float tinhToHop(int n, int k){
    return  giaiThua(n) / (giaiThua(k)/giaiThua(n-k));
}
int main(){
    int n,k;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Nhap k: ");
    scanf("%d", &k);
    float s = tinhToHop(n, k);
    printf("%.2f", s);
    return 0;
}