#include<stdio.h>
void sop(int n, int mat1[n][n]){
    int sump=0, sumnp=0, i, j, k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==i){
                sump+=mat1[i][j];
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==i){
                sumnp+=mat1[i][n-1-i];
            }
        }
    }
    printf("sum of principle diagonal is %d\n sum of non principle diagonal is %d\n",sump,sumnp);
}
void main(){
    int m,n,choice,i,j;
    printf("Enter the values of n for nxn and matrix\n");
    scanf("%d",&n);
    int mat1[n][n];
    int mat2[n][n];
    //int mat3[n+1][n+1];
    printf("Enter the values for matrix 1\n");
    for(i = 0;i<n;i++){
        for(j=0;j<n;j++){
           scanf("%d",&mat1[i][j]);
        }
    }
    printf("Enter the values for matrix 2\n");
    for(i = 0;i<n;i++){
        for(j=0;j<n;j++){
           scanf("%d",&mat2[i][j]);
        }
    }
    printf("\nMenu\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Sum of principle and non principle diagonals\n5.Sum of rows and columns\n6.Transpose matrix\n7.Check if the matrix is symmetric\n8.Exit\n\n");
    while(1){
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: add(n,mat1,mat2);
            break;
            case 2:sub(n,mat1,mat2);
            break;
            case 3:multiply(n,mat1,mat2);
            break;
            case 4: sop(n,mat1);
            break;
            case 5: sumrc(n,mat1,mat2);
            break;
            case 6: transpose(n,mat1);
            break;
            case 7: sym(n,mat1);
            break;
            case 8:exit(0);
            default: printf("Wrong choice\n");
        }
    }

}

void add(int n, int mat1[n][n], int mat2[n][n]){
    int i,j;
    int sum[n][n];
    for(i =0; i<n;i++){
        for(j=0;j<n;j++){
            sum[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    for(i =0; i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
}
void sub(int n, int mat1[n][n], int mat2[n][n]){
        int i,j;
    int sum[n][n];
    for(i =0; i<n;i++){
        for(j=0;j<n;j++){
            sum[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
    for(i =0; i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }
}


void multiply(int n, int mat1[n][n], int mat2[n][n]){
    int sum=0,i,j,k;
    int prod[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prod[i][j] = 0;
            for (int k = 0; k < n; k++) {
                prod[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    for(i =0; i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",prod[i][j]);
        }
        printf("\n");
    }

}

void sumrc(int n, int mat1[n][n]) {
    int sumr, sumc,i,j;
    int mat3[n+1][n+2];


    for (i = 0; i < n; i++) {
        sumr = 0;
        for (j = 0; j < n; j++) {
            mat3[i][j] = mat1[i][j];
            sumr += mat1[i][j];
        }
        mat3[i][n] = sumr;
    }

    for (j = 0; j < n; j++) {
        sumc = 0;
        for (i = 0; i < n; i++) {
            sumc += mat1[i][j];
        }
        mat3[n][j] = sumc;
    }
    mat3[n][n]=0;
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n+1; j++) {
            printf("%d ", mat3[i][j]);
        }
        printf("\n");
    }
}

void transpose(int n, int mat1[n][n]) {
    int transpose[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transpose[j][i] = mat1[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
}

void sym(int n, int mat1[n][n]) {
    int flag =1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat1[i][j] != mat1[j][i]) {
                flag = 0;
            }
        }
    }

    if(flag == 0) printf("not symmetric\n");
    else printf("Symmetric\n");
}
