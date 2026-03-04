#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c;
    printf("Nhap canh a: ");
    scanf("%f", &a);
    printf("Nhap canh b: ");
    scanf("%f", &b);
    printf("Nhap canh c: ");
    scanf("%f", &c);
    if(a < 0 || b < 0 || c < 0){
        printf("so lieu khong hop le!(Huy)");
        return 0;
    }
    printf("\n=== Du Lieu Da Nhap ===\n");
    printf("canh a: %.2f | canh b: %.2f | canh c: %.2f\n", a, b, c);
    if(a == b && a == c){
        printf("Tam Giac Deu");
    } 
    if((a*a + b*b) == c*c){
        printf("Tam Giac Vuong");
    }
    if(a == b || a == c){
        printf("Tam Giac Can");
    }
    else {
        printf("Tam Giac Thuong");
    }
    float p = (a+b+c)/2;
    float s = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("\nDien tich tam giac la: %.2f", s);
    return 0;
}