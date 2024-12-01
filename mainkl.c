#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    FILE *file = fopen("input1.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int arr[1000], barr[1000]; 
    int count = 0;       

   
    while (fscanf(file, "%d %d", &arr[count], &barr[count]) == 2) {
        count++;
    }
    fclose(file);

    qsort(arr, count, sizeof(int), comp);
    qsort(barr, count, sizeof(int), comp);


    int diff = 0;
    for (int i = 0; i < count; i++) {
        int f; 
       if(arr[i]>barr[i]){
        f= arr[i]-barr[i];
       }
       else{
        f = barr[i]-arr[i];
       }
       diff+=f;
    }
    for(int i=0; i < count; i++){
        printf("%d %d\n", arr[i], barr[i]);
    }
    
    printf("%d\n", diff);
   

    return 0;
}
