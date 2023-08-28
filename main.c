#include <stdio.h>

struct Node {
  struct Node* left;
  char name;
  struct Node* right;
};

struct Node* stack[7];
int top = -1;

int dfs(struct Node* start);
int push(struct Node* value);
int pop();
struct Node* seek();
int isEmpty();

int main() {
  struct Node tree[7] = {
      {tree + 1, 'a', tree + 2}, {NULL, 'b', tree + 3}, {tree + 5, 'c', NULL},
      {tree + 4, 'd', NULL},     {NULL, 'e', NULL},     {tree + 6, 'f', NULL},
      {NULL, 'g', NULL},
  };
  dfs(tree);
}

int dfs(struct Node* start) {
  push(start);
  struct Node* now = start;
  int visited[7] = {};
  int i = 0;
  while (!isEmpty()) {
    if (!visited[now->name - 97]) {
      printf("%c->", now->name);
      visited[now->name - 97] = 1;
    }
    if (now->left != NULL && !visited[now->left->name - 97]) {
      push(now->left);
    } else if (now->right != NULL && !visited[now->right->name - 97]) {
      push(now->right);
    } else {
      pop();
    }
    now = seek();
    i++;
  }
}

int push(struct Node* value) { stack[++top] = value; }

int isEmpty() { return top == -1; }
struct Node* seek() { return stack[top]; }
int pop() { top--; }