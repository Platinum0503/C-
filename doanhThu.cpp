#include <stdio.h>
int main(){
    int n;
    printf("Nhap so ngay thong ke: ");
    scanf("%d", &n);
    while(n <= 0){
        printf("\nso ko hop le! (Nhap lai): ");
        scanf("%d", &n);
        printf("\nNhap so ngay thong ke: ");
    }

    float doanhThu[n];
    float tongDoanhThu = 0;
    for(int i = 0;i < n;i++){
        printf("Nhap doanh thu ngay %d :", i+1);
        scanf("%f", &doanhThu[i]);
        tongDoanhThu += doanhThu[i];
    }
    int ngay;
    float caoNhat = doanhThu[0];
    for(int i = 0;i < n;i++){
        if(caoNhat < doanhThu[i]){
            caoNhat = doanhThu[i];
            ngay = i+1;
        }
    }
    float trungBinh = tongDoanhThu/n;
    printf("\n=== TONG HOP ===\n");
    printf("Tong doanh thu: %.2f", tongDoanhThu);
    printf("\ntrung binh: %.2f", trungBinh);
    printf("\ndoanh thu ngay thu %d cao nhat %.2f ", ngay, caoNhat);
    return 0;
}