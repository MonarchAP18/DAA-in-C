#include<stdio.h>
#include<stdlib.h>

#define MAX_TREE_HT 50

struct MinNode{
    char item;
    unsigned freq;
    struct MinNode *left, *right;
};

struct MinHeap{
    unsigned size;
    unsigned capacity;
    struct MinNode **array;
};

typedef struct MinNode MinNode;
typedef struct MinHeap MinHeap;

//create Node
MinNode *newNode(char item, unsigned freq){
    MinNode *temp = (MinNode*)malloc(sizeof(MinNode));
    temp->left=temp->right=NULL;
    temp->item=item;
    temp->freq=freq;

    return temp;
}

//create min heap
MinHeap *createMinH(unsigned capacity){
    MinHeap *minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size=0;
    minHeap->capacity=capacity;
    minHeap->array=(MinNode**)malloc(minHeap->capacity*sizeof(MinNode*));
    return minHeap;
}

void swapMinNode(MinNode **a, MinNode **b){
    MinNode *t=*a;
    *a=*b;
    *b=t;
}

//heapify
void minHeapify(MinHeap *minHeap, int idx){
    int smallest= idx;
    int left = 2*idx+1;
    int right = 2*idx +2;

    if(left< minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq){
        smallest=left;
    }
    if(right< minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq){
        smallest=right;
    }

    if(smallest!=idx){
        swapMinNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }

}

//to check if size is 1
int checkSizeOne(MinHeap *minHeap){
    return (minHeap->size==1);
}

//Extract Min Node
MinNode *extractMin(MinHeap *minHeap){
    MinNode *root = minHeap->array[0];
    minHeap->array[0]=minHeap->array[minHeap->size-1];     //last node becomes parent and then heapify is used
    minHeap->size--;
    minHeapify(minHeap,0);

    return root;
}

//Insert Node
void insertMinHeap(MinHeap *minHeap, MinNode *minHeapNode){
    minHeap->size++;
    int i=minHeap->size -1;

    while(i && minHeapNode->freq < minHeap->array[(i-1)/2]->freq){    //will be compared only with the parent of nodes
        minHeap->array[i]=minHeap->array[(i-1)/2];
        i=(i-1)/2;
    }

    minHeap->array[i]=minHeapNode;
}

void buildMinHeap(MinHeap *minHeap){
    int n= minHeap->size -1;
    int i;

    for(i=(n-1)/2 ; i>=0; i--){
        minHeapify(minHeap,i);
    }
}

int isLeaf(MinNode *root){
    return !(root->left) && !(root->right);
}

MinHeap *createAndBuildMinHeap(char item[], int freq[], int size){
    MinHeap *minHeap = createMinH(size);

    for(int i=0; i<size; i++){
        minHeap->array[i]=newNode(item[i], freq[i]);
    }

    minHeap->size=size;
    buildMinHeap(minHeap);
    return minHeap;
}

MinNode *buildHuffmanTree(char item[], int freq[], int size){
    MinNode *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(item, freq,size);

    while(!checkSizeOne(minHeap)){
        left = extractMin(minHeap);
        right = extractMin(minHeap);
    
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printHCodes(MinNode *root, int arr[], int top){
    if(root->left){
        arr[top]=0;
        printHCodes(root->left, arr, top+1);
    }
    if(root->right){
        arr[top]=1;
        printHCodes(root->right, arr, top+1);
    }
    if(isLeaf(root)){
        printf("  %c   | ", root->item);
        printArray(arr, top);
    }
}

void HuffmanCodes(char item[], int freq[], int size){
    MinNode *root= buildHuffmanTree(item, freq,size);
    int arr[MAX_TREE_HT], top=0;
    printHCodes(root, arr, top);
}

void printArray(int arr[], int n){
    for(int i=0; i<n ; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    int size;
    scanf("%d", &size);

    char arr[size];
    int freq[size];
    for(int i=0; i<size; i++){
        scanf("%s", &arr[i]);
    }
    for(int i=0; i<size; i++){
        scanf("%d", &freq[i]);
    }
    // char arr[] = {'A', 'B', 'C', 'D'};
    // int freq[] = {5, 1, 6, 3};

    // int size = sizeof(arr) / sizeof(arr[0]);

    printf(" Char | Huffman code ");
    printf("\n--------------------\n");

    HuffmanCodes(arr, freq, size);
}
