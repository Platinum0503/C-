#include <stdio.h>

void luuFile(int n){
    FILE *f = fopen ("sanPham1.txt", "w");
    if(f == NULL){
        printf("Loi mo file\n");
        return;
    }

    fprintf(f, "%d\n", n);
    for(int i = 0; i < n;i++){
       // fprintf(f, "%d|%s|%f", sp[i].id, sp[i].ten, sp[i].gia);
    }
    fclose(f);
    printf(">>> Da luu file!\n");
}
int docFile(){ //sanPham **sp
    FILE *f = fopen("sanPham1.txt", "r");
    if(f == NULL){
        printf("Loi! khong tim thay file! khoi tao file moi\n");
        return 0;
    }
    int n;
    fscanf(f, "%d\n", n);
   // *sp = (sanPham*)malloc(n * sizeof(sanPham));
    if(*sp == NULL){
        printf("Loi cap phat!");
        fclose(f);
        return 0;
    }
    for(int i = 0;i < n;i++){
        fscanf(f, "%d|%s|%.2f", (*sp)[i].id, (*sp)[i].ten, (*sp)[i].gia);
    }
    fclose(f);
    printf("Da doc %d san pham tu file", n);
    return n;
}
int main(){



    return 0;
}