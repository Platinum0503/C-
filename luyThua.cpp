#include <stdio.h>

int main(){

    int a,b,c;
    printf("Nhap a: "); scanf("%d", &a);
    printf("Nhap b: "); scanf("%d", &b);
    printf("Nhap c: "); scanf("%d", &c);

    while(a < 0 || b < 0 || c < 0){
        printf("\nNhap ko hop le!(Nhap lai)");
        printf("Nhap a: "); scanf("%d", &a);
        printf("\nNhap b: "); scanf("%d", &b);
        printf("\nNhap c: "); scanf("%d", &c);
    }
    int tong1 = 1, tong2 = 1, tong3 = 1;

    for(int i = 1;i <= a;i++){
        tong1 = tong1 * i;
    }
    for(int i = 1;i <= b;i++){
        tong2 = tong2 * i;
    }for(int i = 1;i <= c;i++){
        tong3 = tong3 *i;
    }
    printf("\nTong a: %d", tong1);
    printf("\nTong b: %d", tong2);
    printf("\nTong c: %d", tong3);
    return 0;
}