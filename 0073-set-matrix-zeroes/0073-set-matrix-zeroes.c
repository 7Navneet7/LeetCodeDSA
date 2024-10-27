// void setZeroes(int* matrix, int Size, int ColSize) {
//     int arr[30];int brr[30];int a=0;int b=0;
//     for(int i=0;i<Size;i++){
//         for(int j=0;j<ColSize;j++){
//             if(&matrix[i][j]==0){
//                 arr[a++]=i;brr[b++]=j;
//             }
//         }
//     }
    
//     for(int i=0;i<a;i++){
//         for(int j=0;j<ColSize;j++){
//             if(&matrix[i][j]==1){
//                 matrix[i][j]=-1;
//             }
//         }
//     }
    
//     for(int i=0;i<Size;i++){
//         for(int j=0;j<b;j++){
//             if(&matrix[i][j]==1){
//                 &matrix[i][j]=-1;
//             }
//         }
//     }
    
//     for(int i=0;i<Size;i++){
//         for(int j=0;j<ColSize;j++){
//             if(&matrix[i][j]==-1){
//                 &matrix[i][j]=0;
//             }
//         }
//     }
    
//     for(int i=0;i<Size;i++){
//         for(int j=0;j<ColSize;j++){
//             printf("%d",matrix[i][j]);
//         }
//         printf("\n");
//     }
    
    
// }

typedef struct Node{
    int x,y;struct Node *next;
}node;

void setZeroes(int **mat,int size,int *colsize){
    node *head=NULL;
    for(int i=0;i<size;i++){
        for(int j=0;j<*colsize;j++){
            if(!mat[i][j]){
                node *nnode=malloc(sizeof(struct Node));
                nnode->x=i;nnode->y=j;
                nnode->next=head;head=nnode;
            }
        }
    }
    while(head){
        int i;
        for(i=0;i<size;i++){
            mat[i][head->y]=0;
        }
        for( i=0;i<*colsize;i++){
            mat[head->x][i]=0;
        }
        head=head->next;
    }
}














