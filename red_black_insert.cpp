/*************************************************************************
	> File Name: red_black_insert.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Apr 2021 04:32:23 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
        int key;
        int color; // 0 red, 1 black, 2 double black
        struct Node *lchild, *rchild;

} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
        NIL->key = -1;
        NIL->color = 1;
        NIL->lchild = NIL->rchild = NIL;
        return ;

}

Node *getNewNode(int key) {
        Node *p = (Node *)malloc(sizeof(Node));
        p->key = key;
        p->color = 0;
        p->lchild = p->rchild = NIL;
        return p;

}

int has_red_child(Node *root) {
        return root->lchild->color == 0 || root->rchild->color == 0;

}

Node *left_rotate(Node *root) {
        printf("left rotate : %d\n", root->key);
        Node *temp = root->rchild;
        root->rchild = temp->lchild;
        temp->lchild = root;
        return temp;

}

Node *right_rotate(Node *root) {
        printf("right rotate : %d\n", root->key);
        Node *temp = root->lchild;
        root->lchild = temp->rchild;
        temp->rchild = root;
        return temp;

}

const char *insert_maintain_str[] = {"", "LL", "LR", "RL", "RR"};

Node *insert_maintain(Node *root) {
        if (!has_red_child(root)) return root;
    if (root->lchild->color == 0 && root->rchild->color == 0) {
        if (!has_red_child(root->lchild) && !has_red_child(root->rchild)) return root;
            printf("Situation 1 : change color\n");
            root->color = 0;    
            root->lchild->color = root->rchild->color = 1;
            return root;                                   
    }
    if (root->lchild->color == 0 && !has_red_child(root->lchild)) return root;
        if (root->rchild->color == 0 && !has_red_child(root->rchild)) return root;

    int flag = 0;
        printf("Situation 2 : \n");
    if (root->lchild->color == 0) {
        if (root->lchild->rchild->color == 0) {
                        root->lchild = left_rotate(root->lchild);
                        flag = 2;
                    
        } else {
                        flag = 1;
                    
        }
                root = right_rotate(root);
            
    } else {
        if (root->rchild->lchild->color == 0) {
                        root->rchild = right_rotate(root->rchild);
                        flag = 3;
                    
        } else {
                        flag = 4;
                    
        }
                root = left_rotate(root);
            
    }
        printf("Maintain Type : %s\n", insert_maintain_str[flag]);
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
        return root;
}


Node *__insert(Node *root, int key) {
        if (root == NIL) return getNewNode(key);
        if (root->key == key) return root;
    if (key < root->key) {
                root->lchild = __insert(root->lchild, key);
            
    } else {
                root->rchild = __insert(root->rchild, key);
            
    }
        return insert_maintain(root);

}

Node *insert(Node *root, int key) {
        root = __insert(root, key); // insert ans maintain
        root->color = 1;
        return root;

}

void clear(Node *root) {
        if (root == NIL) return ;
        clear(root->lchild);
        clear(root->rchild);
        free(root);
        return ;

}

void print(Node *root) {
        printf("(%d | %d, %d, %d)\n",
                      root->color, root->key,
                      root->lchild->key, root->rchild->key
                  );
        return ;

}

void output(Node *root) {
        if (root == NIL) return ;
        print(root);
        output(root->lchild);
        output(root->rchild);
        return ;

}

Node *rand_insert(Node *root) {
        int val = rand() % 100;
        printf("\ninsert %d to red black tree: \n", val);
        root = insert(root, val);
        output(root);
        return root;

}

int main() {
        int n;
        scanf("%d", &n);
        Node *root = NIL;
    for (int i = 0; i < n; i++) {
                root = rand_insert(root);
            
    }
        clear(root);
        return 0;

}

