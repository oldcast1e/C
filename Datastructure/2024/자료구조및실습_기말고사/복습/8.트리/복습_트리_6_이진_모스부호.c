#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100

typedef struct {
   char alpha;
   char morseCode[N];
}Code;

typedef struct TreeNode{
    char alpha;
    struct TreeNode* left;
    struct TreeNode* right;

} TreeNode;


Code table[] = {
    //1차원 배열 : 구조체 배열
    //code 구조체 (alpha : 알파벳 / morseCode : 모스 부호)
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}
};

TreeNode* makeNode(char data, TreeNode* left, TreeNode* right){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

    node->alpha = data;
    node->left = left;
    node->right = right;

    return node;
}

TreeNode* makeMorseTree() {
    TreeNode* root = makeNode(0, NULL, NULL); // 루트 노드 생성
    for(int i= 0 ;i< 26 ;i++){

        TreeNode* p = root;
        for(int j = 0; j< (int)strlen(table[i].morseCode) ; j++){
            if(table[i].morseCode[j] == '.'){
                if(p->left == NULL) p->left = makeNode(0, NULL,NULL);
                p = p->left;
            }
            if(table[i].morseCode[j] == '-'){
                if(p->right == NULL) p->right = makeNode(0, NULL,NULL);
                p = p->right;
            }
        }
        p->alpha = table[i].alpha;
    }
    return root;
}

void printMose(TreeNode* root, char *code){
    TreeNode* p = root;
    for(int i= 0; i<(int)strlen(code); i++){
        if(code[i] == '.') p = p->left;
        if(code[i] == '-') p = p->right;
    }
    printf("RESULT : [%c]",p->alpha);
}

void preorder(TreeNode* root){
    if (root != NULL) {
        if (root->alpha != 0) {
            printf("[%c]", root->alpha);
        }
        preorder(root->left);
        preorder(root->right);
    }
}


int main(){
    TreeNode* root = makeMorseTree();
    // preorder(root);
    printMose(root, table[3].morseCode);
}

/*
[E][I][S][H][V][U][F][A][R][L][W][P][J][T][N][D][B][X][K][C][Y][M][G][Z][Q][O]
[E][I][S][H][V][U][F][A][R][L][W][P][J][T][N][D][B][X][K][C][Y][M][G][Z][Q][O] 
*/