#include <stdio.h>
int main(){
    int thang;
    printf("Nhap thang: "); scanf("%d", &thang);

    //1 3 5 7 8 10 12  --> 31day
    // 2 -> 28 | nhuan 29
    // 4 6 9 11
    
    switch(thang){
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12:
            printf("Thang %d co 31 ngay", thang);
            break;
        case 4 : case 6: case 9 : case 11:
            printf("Thang %d co 30 ngay", thang); 
            break;
        case 2:
            int nam;
            printf("Nhap nam(kiem tra nhuan hay khong): ");
            scanf("%d", &nam);
            if(nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)){
                printf("Nam %d thang 2 co 29 ngay (Nam nhuan)",nam);
            }else{
                printf("Nam %d thang 2 co 28 ngay (Khong phai la nam nhuan)", nam);
            }
            break;
            default: printf("Nhap sai(1-12) nhap lai: ");
    }
    return 0;
}