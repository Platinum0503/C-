#include <stdio.h>

// void luuFile(){
//     FILE *f = fopen("lyLich.txt", "w");
//     if(f == NULL){
//         printf("Loi mo file\n");
//         return;
//     }

//     fprintf(f, "\n");
//     fprintf(f, "%s%d%s%.2f", "Hai Dang", 19, "Nam", 7.0);
//     fclose(f);
//     printf("Da luu file\n");
// }
// int docFile(){
//     FILE *f = fopen("lyLich.txt", "r");
//     if(f == NULL){
//         printf("Loi mo file!\n");
//         return;
//     }

//     fscanf(f, "\n");
//     fscanf(f, "%s%d%s%.2f");
//     fclose(f);

// }
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0;i < n;i++){
        scanf("%d ", &arr[i]);
    }
    
    FILE *f = fopen("soNguyen.txt", "w");
for(int i = 0;i < n;i++){
    fprintf(f, "%d", arr[i]);
    }
    fclose(f);
    printf("Da luu file\n");

    return 0;
}