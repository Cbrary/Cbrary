#include "list.h"
#include <stdio.h>

int main() {

	FILE* fp = fopen("/data/Cbrary/test.txt", "r");
	FUNC* root = NULL, *tmp;
	char buf[1240] = { 0 };	
	char name[20] = { 0 };
	int cnt = 0;
	int deli_cnt = 0;
	char deli = '$';
	int n;
	int size;

	while ((buf[cnt] = fgetc(fp)) != EOF) {
		if (buf[cnt++] == deli) deli_cnt++;
		if (deli_cnt == 4) {
			tmp = AppendNode(root, MakeData(buf, cnt));
			if (tmp != NULL) root = tmp;
			deli_cnt = 0;
			cnt = 0;
			continue;
		}
	}
	fclose(fp);

	while (1) {
		printf("�˻��� ��ɾ �Է��ϼ��� : ");
		scanf("%s", name);
		printf("--------------------------------\n");
		tmp = FindNode(root, name);
		printf("���\n");
		if (tmp != NULL) {
			Print(tmp);
		}
		else {
			printf("%s ��ɾ �����ϴ�\n", name);
		}
	}
	
	return 0;
}
