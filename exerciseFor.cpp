#include <stdio.h>

int main(){
    int maPin;
    const int PIN = 1234;

    for(int i = 1;i <= 5;i++){
        printf("Nhap ma pin: ");
        scanf("%d", &maPin);
        if(maPin == PIN){
        printf("ma PIN dung! >>> dang nhap thanh cong");
        return 0;
        }
        else {
            if(i == 5){
                printf("tai khoan ban bi khoa!");
            }else {
            printf("ma PIN SAI! ban con duoc phep nhap %d ", 5-i , " lan\n");
            }
        }
    }
    return 0;
}