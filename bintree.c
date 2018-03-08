#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

int search(int x,struct node* root){
  if(root==NULL){
    return 0;
  }
  printf("%d : %d\n",x,root->data );
  if(x == root->data){
    return 1;
  }
  else if(x < root->data){
    return search(x,root->left);
  }else{
  return search(x,root->right);
}}

int size(struct node* node){
  if(node==NULL){
    return 0;
  }
  return 1+size(node->left) + size(node->right);
}

// int depth[2];
// int countDeep = 0;
// int findDepth(struct node* node){
//   if(node==NULL){
//     return 0;
//     countDeep = 0;
//   }
//   countDeep++;
//   if(node->left != NULL){
//     return findDepth(node->left);
//   }
//   else{
//     return findDepth(node->right);
//   }
// }
// int maxDepth(struct node* node){
//   findDepth(node->left);
//   int left = countDeep;
//   findDepth(node->right);
//   int right = countDeep;
//   if(left>=right){
//     return left;
//   }
//   else{
//     return right;
//   }
// }

int maxDepth(struct node* node){
  if(node==NULL){
    return 0;
  }
  if(size(node->left)<=size(node->right)){
    return 1+maxDepth(node->right);
  }
  else{
    return 1+maxDepth(node->left);
  }
}

int minValue(struct node* node){
  if(node->left==NULL){
    return node->data;
  }
  return minValue(node->left);
}

void printPreOrder(struct node* node){
  if(node==NULL){
    return;
  }
  printf("%d ",node->data );
  printPreOrder(node->left);
  printPreOrder(node->right);
}

void printPostOrder(struct node* node){
  if(node==NULL){
    return;
  }
  printPostOrder(node->left);
  printPostOrder(node->right);
  printf("%d ",node->data );
}

void printOrder(struct node* node){
  if(node==NULL){
    return;
  }
  printOrder(node->left);
  printf("%d ",node->data );
  printOrder(node->right);
}

int sameTree(struct node* a,struct node* b){
  if(a==NULL||b==NULL){
    return 0;
  }
  if(size(a)!=size(b)){
    return 0;
  }
  if(a->data!=b->data){
    return 0;
  }
  sameTree(a->left,b->left);
  sameTree(a->right,b->right);
  return 1;

}

struct node* insert(struct node* node, int data) {
  // 1. If the tree is empty, return a new, single node
  if (node == NULL) {
    return(newNode(data));
  }
  else {
    // 2. Otherwise, recur down the tree
    if (data <= node->data) node->left = insert(node->left, data);
    else node->right = insert(node->right, data);

    return(node); // return the (unchanged) node pointer
  }
}

void printTree(struct node* root, int level ) {
  int i;
  if (root != NULL) {
    printTree(root->right, level+1);
    for (i=0; i<level; i++) printf("  ");
    printf("%d", root->data);
    printf("\n");
    printTree(root->left, level+1);
  }
}

int main(int argc, char** argv) {
  FILE *f;
  FILE *f2;
  FILE *f3;
  FILE *f4;
  int i;
  int j;
  int k;
  int l;
  struct node *root10;
  struct node *root20;
  struct node *root50;
  struct node *root100;
  root10 = NULL;
  root20 = NULL;
  root50 = NULL;
  root100 = NULL;
  f = fopen(argv[1],"r");
  f2 = fopen(argv[2],"r");
  f3 = fopen(argv[3],"r");
  f4 = fopen(argv[4],"r");
  while (fscanf(f, "%d", &i) != EOF) {
    root10 = insert(root10, i);
  }
  while (fscanf(f2, "%d", &j) != EOF) {
    root20 = insert(root20, j);
  }
  while (fscanf(f3, "%d", &k) != EOF) {
    root50 = insert(root50, k);
  }
  while (fscanf(f4, "%d", &l) != EOF) {
    root100 = insert(root100, l);
  }
  // printTree(root, 0);

  printf("______Test search method______\n");
  int input = -1;
  printf("Number to search in root 10: ");
  scanf("%d", &input);
  if(search(input,root10)==1){
    printf("found it!!!\n");
  }else{
  printf("No!!!\n");
  }
  printf("Number to search in root 20: ");
  scanf("%d", &input);
  if(search(input,root20)==1){
    printf("found it!!!\n");
  }else{
  printf("No!!!\n");
  }
  printf("Number to search in root 50: ");
  scanf("%d", &input);
  if(search(input,root50)==1){
    printf("found it!!!\n");
  }else{
  printf("No!!!\n");
  }
  printf("Number to search in root 100: ");
  scanf("%d", &input);
  if(search(input,root100)==1){
    printf("found it!!!\n");
  }else{
  printf("No!!!\n");
  }
  printf("\n\n");

  printf("______Test size method______\n");
  printf("Size of root random10 = %d\n",size(root10));
  printf("Size of root random20 = %d\n",size(root20));
  printf("Size of root random50 = %d\n",size(root50));
  printf("Size of root random100 = %d\n",size(root100));
  printf("\n\n");

  //maxDepth
  printf("______Test max depth method______\n");
  printf("Depth of root 10 = %d\n",maxDepth(root10) );
  printf("Depth of root 20 = %d\n",maxDepth(root20) );
  printf("Depth of root 50 = %d\n",maxDepth(root50) );
  printf("Depth of root 100 = %d\n",maxDepth(root100) );
  printf("\n\n");

  printf("______Test Min value method______\n");
  printf("Min of root 10 = %d\n",minValue(root10) );
  printf("Min of root 20 = %d\n",minValue(root20) );
  printf("Min of root 50 = %d\n",minValue(root50) );
  printf("Min of root 100 = %d\n",minValue(root100) );
  printf("\n\n");

  //Preorder
  printf("______Test Print Preorder method______\n");
  printf("PrintPreOrder of root 10 = ");
  printPreOrder(root10);
  printf("\nPrintPreOrder of root 20 = ");
  printPreOrder(root20);
  printf("\nPrintPreOrder of root 50 = ");
  printPreOrder(root50);
  printf("\nPrintPreOrder of root 100 = ");
  printPreOrder(root100);
  printf("\n\n");

  printf("______Test Print Postorder method______\n");
  printf("PrintPostOrder of root 10 = ");
  printPostOrder(root10);
  printf("\nPrintPostOrder of root 20 = ");
  printPostOrder(root20);
  printf("\nPrintPostOrder of root 50 = ");
  printPostOrder(root50);
  printf("\nPrintPostOrder of root 100 = ");
  printPostOrder(root100);
  printf("\n\n");

  printf("______Test Print Order method______\n");
  printf("PrintOrder of root 10 = ");
  printOrder(root10);
  printf("\nPrintOrder of root 20 = ");
  printOrder(root20);
  printf("\nPrintOrder of root 50 = ");
  printOrder(root50);
  printf("\nPrintOrder of root 100 = ");
  printOrder(root100);
  printf("\n\n");

  printf("______Test Search method______\n");
  if(sameTree(root10,root20)==1){
    printf("\nThese two tree(10/20) are the same.\n");
  }else{
    printf("\nThese two tree(10/20) are not the same.\n");
  }
  if(sameTree(root10,root10)==1){
    printf("\nThese two tree(10/10) are the same.\n");
  }else{
    printf("\nThese two tree(10/10) are not the same.\n");
  }
  if(sameTree(root20,root50)==1){
    printf("\nThese two tree(10/50) are the same.\n");
  }else{
    printf("\nThese two tree(10/50) are not the same.\n");
  }
  if(sameTree(root100,root100)==1){
    printf("\nThese two tree(100/100) are the same.\n");
  }else{
    printf("\nThese two tree(100/100) are not the same.\n");
  }






}
