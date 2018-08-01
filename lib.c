#include "list.h"
#include <stdio.h>
/*
(1) function : FUNC ��� ���� �Լ�.
(2) input value
	- char *name, char *header, char *source, char *comment
(3) return value
	- FUNC *
	// ���� �� ��� 
*/
FUNC* MakeNode(char *name, char *header, char *source, char *comment) { 
	FUNC* newNode = (FUNC*)malloc(sizeof(FUNC));
	strcpy(newNode->name, name);
	strcpy(newNode->header, header);
	strcpy(newNode->source, source);
	strcpy(newNode->comment, comment);
	newNode->next = NULL;

	return newNode;
}

/*
 (1) function : $name �� �ش��ϴ� �� �˻� �Լ�.
 (2) input value
	- FUNC* root, char* name
 (3) return value
	- FUNC *
	// �˻� ���� : �˻��� ��� , �˻� ���� : NULL
 (4) ������ �Է� ����
	ex) ����/'\n' 
*/
FUNC* FindNode(FUNC* root, char* name) { 

	FUNC* curr = root; 
	char tmp[20] = { 0 };		
	while (curr != NULL) {		
		/*  ��������(1)
		���Ͽ��� �о���� �����ʹ� �������� '\n' (���Ͱ�)�� �����־ ���Ͱ� ���Ÿ� �ؾ��� �˻������ ��ġ�Ѵ�.
		ex) printf'\n' != printf --> printf == printf
		*/
		strcpy(tmp, curr->name);
		tmp[strlen(curr->name) - 1] = '\0';  
		if (!strcmp(tmp, name)) {  // ��(!)
			return curr; // �����Ͱ� �ִٸ� �ش� ��� ��ȯ
		}
		curr = curr->next;
	}	
	return NULL; // �����Ͱ� ���ٸ� NULL ��ȯ
}
/*
(1) function : ������ FUNC ��� ����.
(2) input value
	- FUNC* root, FUNC* newNode
(3) return value
	- FUNC *
	// main stack ������ root �ּҰ��� �������ֱ� ���� return �Ѵ�.
*/
FUNC* AppendNode(FUNC* root, FUNC* newNode)
{
	// ��带 ó�� �����ϴ� ���.
	if (root == NULL) {
		root = newNode;
		return root; 
	}
	// ��尡 1�� �̻��� ���.
	FUNC* curr = root;
	// ������� next �� ���� ������ ��� �̵�.
	while (curr->next != NULL) {
		curr = curr->next;
	}
	// next �� ���� ��� FUNC* newNode ���� ���� ��带 ����
	curr->next = newNode;
	return NULL;
}
/*
(1) function : ���õ� ��� ���
(2) input value
	- FUNC* curr
(3) return value
	- NONE
*/
void Print(FUNC* curr) {
	printf("name : %s", curr->name);
	printf("header : %s", curr->header);
	printf("source : %s", curr->source);
	printf("comment : %s", curr->comment);
	printf("\n");
}
/*
(1) function : ���Ͽ��� �о�� $data ����ü �������� �и�.
(2) input value
- char* data
(3) return value
- FUNC*
*/
FUNC* MakeData(char* data) {
	char name[20] = { 0 };
	char header[20] = { 0 };
	char source[1000] = { 0 };
	char comment[200] = { 0 };

	char* ptr[4] = { name, header, source, comment };
	int idx = 0;

	/*
	strtok : Ư�� ���ڷ� ���ڿ� �и�. 
	ex) printf/ int main -> char * div = printf ;  
	    ���� ó������ �˻��� �����ϰ� '/' ���� ������ �� ������ ���ڿ� ����.
	*/
	char* div = strtok(data, "$");
	while (div != NULL)
	{
		/*
		strncpy 
		ptr : name, header ... �� 4���� ���ڿ� �ּҸ� �����ϰ� �ִ� char ������ �迭
		�˻��� ���ڿ� div �� div ��ŭ ����.
		*/
		strncpy(ptr[idx++], div, strlen(div));
		// strtok ���ο� �ڸ��� ���� ���ڿ��� ����� �־ ù��° ���ڿ� NULL�� ������ �״��� '/' ���ö� ���� Ž���Ѵ�.
		div = strtok(NULL, "$");
	}

	return MakeNode(name, header, source, comment);
}
