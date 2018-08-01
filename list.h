#pragma once
// ����ü ���� FUNC
typedef struct _FUNC {
	char name[20];			// �Լ� ��
	char header[20];		// �ش� ��
	char source[1000];		// �ҽ� ����
	char comment[200];		// �ڸ�Ʈ
	struct _FUNC* next;		
} FUNC;

FUNC* MakeData(char* data);
FUNC* MakeNode(char *name, char *header, char *source, char *comment);
FUNC* FindNode(FUNC* root, char* name);
FUNC* AppendNode(FUNC* root, FUNC* newNode);
void Print(FUNC* root);


