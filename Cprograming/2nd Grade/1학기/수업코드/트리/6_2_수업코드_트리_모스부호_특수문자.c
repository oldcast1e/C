#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// #pragma warning(disable:4996)

#define N 10

typedef struct {
   char alpha;
   char morseCode[N];
}Code;

typedef struct  TreeNode{
    char alpha;
    struct TreeNode* left, * right;
}TreeNode;

/*
왼쪽 자식 : 도트(.)
오른쪽 자식 : 하이픈(_)

*/

Code table[] = {
    //1차원 배열 : 구조체 배열
    //code 구조체 (alpha : 알파벳 / morseCode : 모스 부호)
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},


    {'!', "-.-.--"},
    {'\"', ".-..-."},
    
    // {',', "--..--"}, {'.', ".-.-.-"},{'?', "..--.."},{';', "-.-.-."},{':', "---..."},
    // {'/', "-..-."},{'-', "-....-"},{'\'', ".----."},{'\"', ".-..-."},{'_', "..--.-"},
    // {'(', "-.--."},{')', "-.--.-"},{'=', "-...-"},{'+', ".-.-."},{'@', ".--.-."},
    // {'!', "-.-.--"},{'&', ".-..."}
};


TreeNode* makeNode(char alpha, TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->alpha = alpha;
    node->left = left;
    node->right = right;
    return node;
}


TreeNode* makeMorseTree() {
    TreeNode* root = makeNode(0, NULL, NULL); 
    // 부모 노드 만들기 : 데이터 (0)
    for (int i = 0; i < 26; i++) {
        TreeNode* p = root;
        int n = strlen(table[i].morseCode); //table : 알파벳과 모스부호 관계
        //각각의 알파벳에 해당하는 모스 부호는 길이 모두 다름
        for (int j = 0; j < n; j++) {//해당하는 알파벳의 모스 부호 길이 만큼 반복
            char c = table[i].morseCode[j]; // 모스 부호의 인덱스 접근
            if (c == '.') {//. -> 왼쪽 자식 노드
                /*
                - 왼쪽 자식 노드가 없을 때, 왼쪽 자식 노드를 만든다.
                - 왼쪽 자식 노드가 있을 때, 왼쪽 자식 노드로 이동한다.
                */
                if (p->left == NULL)  p->left = makeNode(0, NULL, NULL);
                p = p->left;          
            }
            else {//_ -> 오른쪽 자식 노드
                /*
                - 오른쪽 자식 노드가 없을 때, 오른쪽 자식 노드를 만든다.
                - 오른쪽 자식 노드가 있을 때, 오른쪽 자식 노드로 이동한다.
                */
                if (p->right == NULL) p->right = makeNode(0, NULL, NULL);
                p = p->right;
            }
        }
        p->alpha = table[i].alpha;
        //도착한 위치(이진트리)에 값을 저장한다.
    }     
    return root;
}

void preOrder(TreeNode* root) {
    if (root != NULL) {
        if (root->alpha != 0) {
            printf("[%c] ", root->alpha);
        }
        preOrder(root->left);
        preOrder(root->right);
    }
}

void printMose(TreeNode *root, char *code){
    int len  = (int)strlen(code);
    char dot,hypen;
    TreeNode *p = root;
    for(int i=0;i<len;i++){
        if(code[i] == '.'){p = p->left; }
        else if(code[i] == '-'){p = p->right; }
    }
    printf("%c",p->alpha);
}

void Decode(TreeNode *root, char *code){
    int len  = (int)strlen(code);
    char dot,hypen;
    TreeNode *p = root;
    printf("DeCording : ");
    for(int i=0;i<len;i++){
        if(i == 0){p = root;}
        else if( code[i] == ' '){
            printf("[%c]",p->alpha);
            p = root;
        }
        else if(code[i+1] == '\0'){
            p = (code[i] == '.')?(p->left):(p->right); 
            printf("[%c]",p->alpha); 
            break;
        }
        // p = (code[i] == '.')?(p->left):(p->right); 
        if(code[i] == '.'){p = p->left; }
        else if(code[i] == '-'){p = p->right; }
    }
}

void inCode(TreeNode *root,char *str){
    int len  = (int)strlen(str);
    printf("InCording : ");
    for(int i=0;i<len;i++){
        if(str[i] == ' '){printf(" ");continue;}
        if('!' <= str[i] && str[i] <= '/'){

        }
        else{
            int n = strlen(table[str[i]-'A'].morseCode); 
            for (int j = 0; j < n; j++){
                char c = table[str[i]-'A'].morseCode[j]; // 모스 부호의 인덱스 접근
                // 여기서 특수 문자 판별이 안됨
                printf("%c",c);
            }printf(" "); 
        }
          
    }printf("\n");
}

int main(){
    TreeNode *root = makeMorseTree();
    // preOrder(root); printf("\n");
    char code[100]; 
    char str[100]; 
    // scanf("%s",code);
    // printMose(root,code);

    int func;
    printf("Incode : [0] | Decode : [1] : "); scanf("%d",&func); getchar();
    if(func == 0){
        printf("[Incoding]\n");
        gets(code);
        inCode(root,code);
    }
    else if(func == 1){
        printf("[Decoding]\n"); //getchar();
        gets(code);
        Decode(root,code);
    }
    else printf("Invaild Inout.");
    

    // gets(str);
    // inCode(root,str);

}
/*
.... . .-.. .-.. ---
HELLO WORLD!

A : .-
B : -...
C : -.-.
D : -..
E : .
F : ..-.
G : --.
H : ....
I : ..
J : .---
K : -.-
L : .-..
M : --
N : -.
O : ---
P : .--.
Q : --.-
R : .-.
S : ...
T : -
U : ..-
V : ...-
W : .--
X : -..-
Y : -.--
Z : --..
*/