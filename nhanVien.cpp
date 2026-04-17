#include <stdio.h>
#include <string.h>
int main(){
    int n;
    char ten[50];
    float luong, luongNgay;
    int ngayLam;
    
    printf("Nhap so luong nhan vien: "); scanf("%d", &n);
    while(n <= 0){
        printf("Nhap so luong nhan vien: "); scanf("%d", &n);
    }
    //fflush(stdin);  delete Bộ nhớ đệm
    for(int i = 0;i < n;i++){
        printf("Ten: "); scanf("%s", ten);
        //fflush(stdin);  delete Bộ nhớ đệm
        printf("\nLuong: "); scanf("%f", &luong);
        printf("\nLuong ngay: "); scanf("%f", &luongNgay);
        printf("\nNgay lam: "); scanf("%d", &ngayLam);
    }    
    for(int i = 0;i < n;i++){
                printf("Ten: %s", ten);
                printf("\nLuong: %.2f", luong);
                printf("\nLuong ngay: %.2f", luongNgay);
                printf("\nNgay lam: %d", ngayLam);
            } //wrong
    return 0;
}