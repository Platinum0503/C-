#include <stdio.h>

int main(){
    float toan, ly, hoa;
    printf("Nhap diem toan: ");
    scanf("%f", &toan);
    printf("Nhap diem ly: ");
    scanf("%f", &ly);
    printf("Nhap diem hoa: ");
    scanf("%f", &hoa);
    printf("\n===Diem cua ban===\n");
    printf("toan: %.2f | ly: %.2f | hoa: %.2f\n", toan, ly, hoa);
    if(toan < 0 || toan > 10 || ly < 0 || ly > 10 || hoa < 0 || hoa > 10 ){
        printf("diem khong hop le!(Huy)");
        return 0;
    }
    float tbc = (toan+ly+hoa)/3;
    printf("trung binh cong: %.2f\n", tbc);
    if(tbc >= 8){
        printf("Gioi");
    }else if(tbc >= 7){
        printf("Kha");
    } else if(tbc >= 5){
        printf("Trung binh");
    } else {
        printf("Yeu");
    }
    

    return 0;
}