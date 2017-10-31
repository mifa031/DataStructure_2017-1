#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_FILE 100
#define NUM_PATTERN 5
#define RATE_SUSPECTED 0.8
#define RATE_INFETCTED 1

typedef struct {
	int offset;
	char* location = "default";
	bool pattern[NUM_PATTERN] = { false,false,false,false,false };
}ABSTRACT_FILE;

typedef struct {
	int offset;
	float infectedRate;
	char* status;
}INFECTED_FILE;

float inspectFile(ABSTRACT_FILE* file);
int countInfected(ABSTRACT_FILE* file);
void isolateFile(ABSTRACT_FILE* file);
void deleteFile(ABSTRACT_FILE* file);
void createInfectedList(ABSTRACT_FILE* file, INFECTED_FILE* inf_file);
void listInfected(INFECTED_FILE* inf_file, int inf_num);
void infoFile(ABSTRACT_FILE* file, INFECTED_FILE* inf_file, int inf_num);

void main()
{
	ABSTRACT_FILE file[NUM_FILE];
	INFECTED_FILE* inf_file;

	srand((unsigned)time(NULL));
	for (int i = 0; i < NUM_FILE; i++) {
		file[i].offset = i;
		for (int j = 0; j < NUM_PATTERN; j++) {
			if (rand() % 2) {
				file[i].pattern[j] = true;
			}
			else {
				file[i].pattern[j] = false;
			}
		}
	}    /* �׽�Ʈ�� ���� �� ���� ����ü�� ������ ���̷��� ������ �Է��ϴ� �κ� */

	int inf_num = countInfected(file);
	inf_file = (INFECTED_FILE*)malloc(sizeof(INFECTED_FILE*)*inf_num);
	createInfectedList(file, inf_file);
	listInfected(inf_file, inf_num);
	while (1) {
		infoFile(file, inf_file, inf_num);
	}
	free(inf_file);   /*�ش� ADT ����ü�� ������ �����ϴ� �κ� */
}

float inspectFile(ABSTRACT_FILE* file) {
	float infectedRate;
	int num_true = 0;
	for (int j = 0; j < NUM_PATTERN; j++) {
		if (file->pattern[j] == true) {
			num_true++;
		}
	}
	return infectedRate = (float)num_true / NUM_PATTERN;
}

int countInfected(ABSTRACT_FILE* file) {
	float infRate;
	int num = 0;
	for (int i = 0; i < NUM_FILE; i++) {
		infRate = inspectFile(&file[i]);
		if (infRate > RATE_SUSPECTED)
			num++;
	}
	return num;
}

void isolateFile(ABSTRACT_FILE* file) {
	file->location = "isolated";
}

void deleteFile(ABSTRACT_FILE* file) {
	file->location = "deleted";
}

void createInfectedList(ABSTRACT_FILE* file, INFECTED_FILE* inf_file) {
	float infRate;
	int j = 0;
	for (int i = 0; i < NUM_FILE; i++) {
		infRate = inspectFile(&file[i]);
		if (infRate >= RATE_INFETCTED) {
			inf_file[j].offset = i;
			inf_file[j].infectedRate = infRate;
			inf_file[j].status = "deleted";
			deleteFile(&file[i]);
			j++;
		}
		else if (infRate >= RATE_SUSPECTED) {
			inf_file[j].offset = i;
			inf_file[j].infectedRate = infRate;
			inf_file[j].status = "isolated";
			isolateFile(&file[i]);
			j++;
		}
	}
}

void listInfected(INFECTED_FILE* inf_file, int inf_num) {
	printf("\n�ڰ����� ���� ��ϡ�\n");
	for (int i = 0; i <inf_num; i++) {
		printf("\n%d\n", i);
		printf("���� ������: %d\n", inf_file[i].offset);
		printf("������: %0.f%%\n", inf_file[i].infectedRate * 100);
		printf("���� ����: %s\n", inf_file[i].status);
	}
}

void infoFile(ABSTRACT_FILE* file, INFECTED_FILE* inf_file, int inf_num) {
	int i;
	printf("\n\n�ڰ��������� �˰���� ������ ������ �Է�: ");
	scanf("%d", &i);
	printf("�Ҽ�����: %s\n", file[i].location);
	printf("���Ͽ�����: %d\n", file[i].offset);
	printf("��������:");
	for (int j = 0; j < NUM_PATTERN; j++) {
		if (file[i].pattern[j] == true)
			printf(" true");
		if (file[i].pattern[j] == false)
			printf(" false");
	}
	printf("\n");
	for (int k = 0; k < inf_num; k++) {
		if (i == inf_file[k].offset) {
			printf("������: %0.f%%\n", inf_file[k].infectedRate * 100);
			if (strcmp(inf_file[k].status, "isolated") == 0) {
				printf("���ϻ���: %s (�Ǽ��ǽ�)\n", inf_file[k].status);
			}
			else if (strcmp(inf_file[k].status, "deleted") == 0) {
				printf("���ϻ���: %s (�Ǽ�Ȯ��)\n", inf_file[k].status);
			}
			else {
				break;
			}
		}
	}
}