#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 1000


typedef struct element {
    char reserve[7];
    int count;
}element;
typedef struct TreeNode
{
    element key;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
int compare(element e1, element e2)
{
	return strcmp(e1.reserve, e2.reserve);
}
void display(TreeNode* p) {
	if (p) {
		display(p->left);
		printf("[%s]", p->key.reserve);
		printf(":%d", p->key.count);
		display(p->right);
	}
}
void write_file(FILE*fp1, TreeNode* p) {
	if (p) {
		write_file(p->left,fp1);
		//printf("[%s]", p->key.reserve);
		fputs(p->key.reserve, fp1);
		//printf(":%d", p->key.count);
		fputs(p->key.count, fp1);
		write_file(p->right,fp1);
	}
}
TreeNode* search(TreeNode* root, element key)
{
	TreeNode* p = root;
	while (p != NULL) {
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
}
TreeNode* new_node(element item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, element key) {
	if (node == NULL) return new_node(key);
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);
	return node;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}
TreeNode* delete_node(TreeNode* root, element key) {
	if (root == NULL) return root;
	if (compare(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	if (compare(key, root->key) > 0)
		root->right = delete_node(root->right, key);

	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
int is_alphabet(char c);


int main() {
	char buffer[MAX_SIZE] = { 0 };
	char *tmp[MAX_SIZE] = { 0 };
	char reserved_word [11][7] = { "break" ,"case"," do","else","for","if","int","return","struct","switch","while"};
	FILE* fp;
	FILE* fp1;
	TreeNode* root = NULL;
	TreeNode* temp = NULL;
    element tmp1 = {0};
	fp = fopen("bst_in1.txt", "r");
	fp1 = fopen("bst_out.txt", "w");
	fread(buffer, sizeof(buffer), sizeof(char), fp);
	printf("%s\n", buffer);
	fclose(fp);
	
	char seps[] = "#<>={}[]'`_*?0123456789()\",.! -:;/\t\n";
	char* token;
	int count = 0;
	token = strtok(buffer, seps);
	while (token != NULL) {
		tmp[count] = malloc(strlen(token) + 1);
		strcpy(tmp[count], token);
		count++;
		token = strtok(NULL, seps);
	}
	tmp1.count = 1;
	for (int i = 0; i < count; i++) {
		printf("%d: [%s]\n", i, tmp[i]);
		for (int j = 0; j < 11; j++) {
            if (strcmp(tmp[i], reserved_word[j]) == 0) {
                printf("this is reserve\n");
				strcpy(tmp1.reserve, reserved_word[j]);
				//printf("copy = %s\n", tmp1.reserve);
				
				//printf("copy = %d\n", tmp1.count);
				if (temp = search(root, tmp1)) {
					temp->key.count = temp->key.count + 1;
					printf("%s is already in!\n", tmp1.reserve[j]);
				}
				else
				{
					root = insert_node(root, tmp1);
					printf("new word\n");
				}
            }
		}
	}
	//for (int i = 0; i < MAX_SIZE; i++) {
	//	
	//	if (is_alphabet(buffer[i])) {
	//		tmp[i] = buffer[i];
	//	}
	//	else if (buffer[i] == ' ') {
	//		for (int j = 0; j < 11; j++)
	//			if(strcmp(tmp, reserved_word[j]) == 0)
	//				printf("here is resrve\n");
	//	}
	//}
	display(root);
	write_file(fp1, root);
	fclose(fp1);
	return 0;
}

int is_alphabet(char c) {
	if (c >= 'a' && c <= 'z')
		return 1;
	else
		return 0;
}



