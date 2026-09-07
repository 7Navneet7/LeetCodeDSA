

typedef struct{
    int* arr;
    int top;
}Stack;


typedef struct {
    Stack stack[200000];
    int atStack;
    int maxStack;
    int capacity;
} DinnerPlates;


DinnerPlates* dinnerPlatesCreate(int capacity) {
    DinnerPlates* obj = (DinnerPlates*)malloc(sizeof(DinnerPlates));
    for(int i=0;i<200000;i++){
        obj->stack[i].arr = NULL;
        obj->stack[i].top = -1;
    }
    obj->atStack = 0;
    obj->capacity = capacity;
    obj->maxStack = 0;
    return obj;
}

void dinnerPlatesPush(DinnerPlates* obj, int val) {
    while(obj->stack[obj->atStack].top == obj->capacity-1){
        obj->atStack++;
    }
    if(obj->stack[obj->atStack].arr == NULL){
        obj->stack[obj->atStack].arr = (int*)malloc(obj->capacity*sizeof(int));
    }
    obj->stack[obj->atStack].arr[++obj->stack[obj->atStack].top] = val;
    if(obj->atStack>obj->maxStack){
        obj->maxStack = obj->atStack;
    }
}

int dinnerPlatesPop(DinnerPlates* obj) {

    while(obj->stack[obj->maxStack].top == -1){
        if(obj->stack[obj->maxStack].top == -1 && obj->maxStack == 0){
            return -1;
        }
        obj->maxStack--;
    }
    int val = obj->stack[obj->maxStack].arr[obj->stack[obj->maxStack].top--];
    if(obj->maxStack < obj->atStack){
        obj->atStack = obj->maxStack;
    }
    return val;
}

int dinnerPlatesPopAtStack(DinnerPlates* obj, int index) {
    if((obj->stack[obj->maxStack].top == -1 && obj->maxStack == 0) || (obj->stack[index].top == -1)){
        return -1;
    }
    if(obj->atStack > index){
        obj->atStack = index;
    }

    return obj->stack[index].arr[obj->stack[index].top--];
}

void dinnerPlatesFree(DinnerPlates* obj) {
    for(int i=0;i<20000;i++){
        free(obj->stack[i].arr);
    }
    free(obj);
}

/**
 * Your DinnerPlates struct will be instantiated and called as such:
 * DinnerPlates* obj = dinnerPlatesCreate(capacity);
 * dinnerPlatesPush(obj, val);
 
 * int param_2 = dinnerPlatesPop(obj);
 
 * int param_3 = dinnerPlatesPopAtStack(obj, index);
 
 * dinnerPlatesFree(obj);
*/