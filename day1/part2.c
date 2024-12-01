#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void similarity_score(int a[],int b[]){
    
   int sum =0;

     for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            int count1 =0;
         if(a[i]==b[j]){
            count1++;
         }
         else{
            continue;
         }
         sum+= a[i]*count1;
         }
     }
     printf("%d",sum);
     
}

int main() {
    FILE *file = fopen("input1.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int a[1000], b[1000]; 
    int count = 0;       

   
    while (fscanf(file, "%d %d", &a[count], &b[count]) == 2) {
        count++;
    }
    fclose(file);

    qsort(a, count, sizeof(int), comp);
    qsort(b, count, sizeof(int), comp);


    similarity_score(a,b);
   

    return 0;
}
