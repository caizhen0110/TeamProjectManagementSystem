/*
�ζ��M�׺޲z�t��
�n�Ψ�Linked list�C
���@�p�խt�d�@�M�סA�g�@�ӵ{���O���p�զ����B�M�פ����h������(�u�@)��������T�P���A�C
(1) �p�զ����H�Ƥ����A�i�H�����P����C
	�C�즨�����򥻸�T�A�p�G�m�W�B�q�ܡB���ⵥ�C
	�ϥΪ̥i�H�s�W�����B�R�������B�ק令����T�B�L�X�Ҧ��������C
(2) �M�פ�������(�u�@)�i�H�����h�����O�A
	�Ҧp�G�\����R�B�\��]�p�B�{�����g�B���աB���������q�A�άO���ʳ]�p�B���a�����B�Ŷǵ��u�@�աC
	�ϥΪ̥i�H�ۦ�w�q���O���ƶq�P�U�����O���W�١C
(3) �C�ӥ���(�u�@)���򥻸�T�A
	�p�G���ȦW�١B���Ȼ����B���n�ʡB�t�d�H���B�ɵ{�B�ثe�i�סB���O�����C
	�@�ӥ��ȷ|���ݩ�@�����O�A�i�H�N���ȴ���t�@�����O�C
	�ϥΪ̥i�H�s�W���ȡB���������O�B�ק���ȸ�T�B�L�X�Ҧ����ȵ��C

�t�βӸ`�B�\��Цۦ�]�p�C
*/

// �ʤ� free(newnode);

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//�p�զ���
struct members
{
	char name[20];	//�m�W
	char phone[11];	//�q��
	char character[20];	//����
	members* nextptr;	//�U�@�즨��
};
//����-�򥻸�T
struct task_data
{
	char name[30];	//���ȦW��
	char explanation[100];	//���Ȼ���
	int importance;	//���n��(1~10)
	char responsible_people[100];	//�t�d�H��
	char time[20];	//�ɵ{
	char schedule[300];	//�ثe�i��
	char mark[300];	//���O
	task_data* nextptr;	//�U�@�ӥ���
};
//�������O
struct task_sort
{
	char category[50];	//���O�W��
	task_sort* nextptr;	//�U�@�����O
	task_data* dataptr;	//����
};

//�����]�w:
// (1)�s�W����
void new_members(members** members_list);
// (2)�R������
void delete_members(members** members_list);
// (3)�ק令����T
void change_members(members** members_list);
// (4)�L�X�Ҧ�����
void prt_members(members* members_list);

//�s�W�������O
void new_tasksort(task_sort** task_list);

//���ȳ]�w:
// (1)�s�W����
void new_task(task_sort** task_list);
// (2)���������O
void change_tasksort(task_sort** task_list);
// (3)�ק���ȸ�T
void change_task(task_sort** task_list);
// (4)�L�X�Ҧ�����
void prt_task(task_sort* task_list);


//���b:
void foolproof_check(char* check);


int main() {
	int choise = 0;
	members* members_list = NULL;
	task_sort* task_list = NULL;

	while (choise != -1)
	{
		printf("�п�� 1)�����]�w 2)�s�W�������O 3)���ȳ]�w -1)���� :");
		scanf("%d", &choise);

		switch (choise)
		{
		case 1:	//�����]�w
			printf("�п�� 1)�s�W���� 2)�R������ 3)�ק令����T 4)�L�X�Ҧ����� :");
			scanf("%d", &choise);

			switch (choise)
			{

			case 1:	//�s�W����
				new_members(&members_list);
				break;

			case 2:	//�R������
				delete_members(&members_list);
				break;

			case 3:	//�ק令����T
				change_members(&members_list);
				break;

			case 4:	//�L�X�Ҧ�����
				prt_members(members_list);
				break;
			default:
				printf("��J���~!\n");
				break;
			}
			break;

		case 2:	//�s�W�������O
			new_tasksort(&task_list);
			break;

		case 3:	//���ȳ]�w
			printf("�п�� 1)�s�W���� 2)���������O 3)�ק���ȸ�T 4)�L�X�Ҧ��������� :");
			scanf("%d", &choise);

			switch (choise)
			{

			case 1:	//�s�W����
				new_task(&task_list);
				break;

			case 2:	//���������O
				change_tasksort(&task_list);
				break;

			case 3:	//�ק���ȸ�T
				change_task(&task_list);
				break;

			case 4:	//�L�X�Ҧ�����
				prt_task(task_list);
				break;
			default:
				printf("��J���~!\n");
				break;
			}
			break;

		case -1:	//����
			break;
		default:
			printf("��J���~!\n");
			break;
		}
	}

	return 0;
}

// (1)�s�W����
void new_members(members** members_list)
{
	members* newnode = (members*)malloc(sizeof(members));

	printf("�п�J �m�W �q�� ���� :");
	scanf("%s%s%s", newnode->name, newnode->phone, newnode->character);

	//�쥻�S�����
	if (*members_list == NULL)
	{
		newnode->nextptr = NULL;	//newnode ���V NULL
		*members_list = newnode;	//��s newnode ���Ĥ@�Ӹ`�I
	}
	else
	{
		newnode->nextptr = *members_list;	//newnode ���V�ª��}�Y�`�I
		*members_list = newnode;	//newnode �����s���}�Y�`�I
	}
	printf("�s�W�������\!\n");
}

// (2)�R������
void delete_members(members** members_list)
{
	members* currentptr = *members_list;
	members* previousptr = NULL;
	char user[11];
	char check = ' ';

	printf("�п�J���R���H�����q�� :");
	scanf("%s", user);

	if (currentptr == NULL)
	{
		printf("�����W�椤�d�L���H��!\n");
	}
	while (currentptr != NULL)
	{
		//���ӤH�����
		if (strcmp(currentptr->phone, user) == 0)
		{
			printf("����Ʀp�U:\n�m�W:%s\n�q��:%s\n����:%s\n\n�O�_�����H��(Y/N): ", currentptr->name, currentptr->phone, currentptr->character);
			scanf(" %c", &check);

			foolproof_check(&check);
			//�n�R��
			if (check == 'Y')
			{
				if (previousptr != NULL) {
					previousptr->nextptr = currentptr->nextptr;	//��e�`�I�� �e�@��&��@�ӳs��
				}
				else {
					*members_list = currentptr->nextptr;	//��e�`�I�� �e�@��&��@�ӳs��
				}
				free(currentptr);	//�R���ӤH��
				printf("�ӤH����Ƥw�R��!\n");
				break;
			}
			//�d�ߤU�@�Ӹ`�I
			else
			{
				previousptr = currentptr;
				currentptr = currentptr->nextptr;	//currenptr ��s���U�@�Ӹ`�I

				if (currentptr == NULL)
				{
					printf("�����W�椤�d�L���H��!\n");
				}
			}
		}
		//�d�ߤU�@�Ӹ`�I
		else
		{
			previousptr = currentptr;
			currentptr = currentptr->nextptr;	//currenptr ��s���U�@�Ӹ`�I

			if (currentptr == NULL)
			{
				printf("�����W�椤�d�L���H��!\n");
			}
		}
	}
}

// (3)�ק令����T
void change_members(members** members_list)
{
	members* currentptr = *members_list;
	members* previousptr = NULL;
	char user[11];
	char check = ' ';
	int choise = 0;

	printf("�п�J���ק�H�����q�� :");
	scanf("%s", user);

	if (currentptr == NULL)
	{
		printf("�����W�椤�d�L���H��!\n");
	}
	while (currentptr != NULL)
	{
		//���ӤH�����
		if (strcmp(currentptr->phone, user) == 0)
		{
			printf("����Ʀp�U:\n�m�W:%s\n�q��:%s\n����:%s\n\n�O�_�����H��(Y/N): ", currentptr->name, currentptr->phone, currentptr->character);
			scanf(" %c", &check);

			foolproof_check(&check);
			//�n�ק�
			if (check == 'Y')
			{
				while (check != 'N')
				{
					printf("�п�ܭn�ק諸���� 1)�m�W 2)�q�� 3)���� : ");
					scanf("%d", &choise);

					while (choise < 1 || choise>3)
					{
						printf("��J���~�Э��s��J: ");
						scanf("%d", &choise);
					}

					if (choise == 1)
					{
						printf("�п�J�s���m�W: ");
						scanf("%s", currentptr->name);
					}
					else if (choise == 2)
					{
						printf("�п�J�s���q��: ");
						scanf("%s", currentptr->phone);
					}
					else if (choise == 3)
					{
						printf("�п�J�s������: ");
						scanf("%s", currentptr->character);
					}


					printf("�аݬO�_�٭n�~��ק�(Y/N): ");
					scanf(" %c", &check);
					foolproof_check(&check);
				}

				printf("�ӤH����Ƥw��s!\n");
				break;
			}
			//�d�ߤU�@�Ӹ`�I
			else
			{
				previousptr = currentptr;
				currentptr = currentptr->nextptr;	//currenptr ��s���U�@�Ӹ`�I

				if (currentptr == NULL)
				{
					printf("�����W�椤�d�L���H��!\n");
				}
			}
		}
		//�d�ߤU�@�Ӹ`�I
		else
		{
			previousptr = currentptr;
			currentptr = currentptr->nextptr;	//currenptr ��s���U�@�Ӹ`�I

			if (currentptr == NULL)
			{
				printf("�����W�椤�d�L���H��!\n");
			}
		}
	}
}

// (4)�L�X�Ҧ�����
void prt_members(members* members_list)
{
	members* currentptr = members_list;

	if (currentptr == NULL)
	{
		printf("�٨S��������!\n");
	}
	while (currentptr != NULL)
	{
		printf("\n�m�W:%s\t�q��:%s\t����:%s\n", currentptr->name, currentptr->phone, currentptr->character);	//�L�X�Ӹ`�I���
		currentptr = currentptr->nextptr;	//�d�ݤU�@�Ӹ`�I
	}
}

//�s�W�������O
void new_tasksort(task_sort** task_list)
{
	task_sort* newnode = (task_sort*)malloc(sizeof(task_sort));
	task_sort* currentptr = NULL;

	printf("�п�J ���O�W�� :");
	scanf("%s", newnode->category);
	newnode->dataptr = NULL;

	//�쥻�S�����
	if (*task_list == NULL)
	{
		newnode->nextptr = NULL;	//newnode ���V NULL
		*task_list = newnode;	//��s newnode ���Ĥ@�Ӹ`�I
	}
	else
	{
		currentptr = *task_list;
		//�ˬd������
		while (currentptr != NULL)
		{
			//����
			if (strcmp(newnode->category, currentptr->category) == 0)
			{
				printf("���W�٤w�s�b!�ХR�s��J ���O�W�� :");
				scanf("%s", newnode->category);
				currentptr = *task_list;
			}
			else {
				currentptr = currentptr->nextptr;
			}
		}

		newnode->nextptr = *task_list;	//newnode ���V�ª��}�Y�`�I
		*task_list = newnode;	//newnode �����s���}�Y�`�I
	}
	printf("�������O�s�W���\!\n");
}

// (1)�s�W����
void new_task(task_sort** task_list) {

	task_data* newnode = (task_data*)malloc(sizeof(task_data));
	task_sort* currentptr;
	char save_sort[50];	//����J�����O

	currentptr = *task_list;
	if (currentptr == NULL)
	{
		printf("�S���������O! �Х��s�W�������O�C\n");
	}
	else {
		printf("�п�J ���ȦW�� ���Ȼ��� �ɵ{ : ");
		scanf("%s%s%s", newnode->name, newnode->explanation, newnode->time);
		printf("�п�J �t�d�H�� : ");
		scanf("%s", newnode->responsible_people);
		printf("�п�J ���n��(�ж�Ʀr 1~10 ) : ");
		scanf("%d", &newnode->importance);
		printf("�п�J �ثe�i�� : ");
		scanf("%s", newnode->schedule);
		printf("�п�J ���O : ");
		scanf("%s", newnode->mark);


		//�L�X�Ҧ����O
		printf("�ثe�s�b�����O: \n");
		while (currentptr != NULL)
		{
			printf("%s ", currentptr->category);
			currentptr = currentptr->nextptr;	//�s���U�@�����O�W��
		}
		printf("\n");

		printf("�п�J�n�x�s�����O�W��: ");
		scanf("%s", save_sort);

		//�j�M�����O�W��
		currentptr = *task_list;
		while (currentptr != NULL)
		{
			if (strcmp(save_sort, currentptr->category) == 0)
			{
				break;
			}
			else if (currentptr->nextptr == NULL)
			{
				printf("��J���~!\n");
				printf("�п�J�n�x�s�����O�W��: ");
				scanf("%s", save_sort);

				currentptr = *task_list;
			}
			else {
				currentptr = currentptr->nextptr;	// �U�@�����O
			}
		}

		//�쥻�S�����
		if (currentptr == NULL)
		{
			newnode->nextptr = NULL;
			currentptr->dataptr = newnode;
		}
		//�쥻�����
		else {
			newnode->nextptr = currentptr->dataptr;	//newnode ���V�쥻���}�Y����
			currentptr->dataptr = newnode;	//newnode ��s���}�Y����
		}
		printf("���ȷs�W���\!\n");
	}

}

// (2)���������O
void change_tasksort(task_sort** task_list) 
{
	task_sort* currentptr;
	task_data* dataptr;
	task_data* previousptr = NULL;
	char taskname[30];                                                                                                                                                                                                                                                                                                                                                                                                                              
	char categary[50] = { " " };	//�s���O

	//�L�X�Ҧ����O
	printf("�ثe�s�b�����O: \n");
	currentptr = *task_list;
	if (currentptr == NULL)
	{
		printf("�S���������O!\n");

	}
	while (currentptr != NULL)
	{
		printf("%s ", currentptr->category);
		currentptr = currentptr->nextptr;	//�s���U�@�����O�W��
	}
	printf("\n");

	printf("�п�J�n������O�����ȦW��: ");
	scanf("%s", taskname);

	currentptr = *task_list;
	if(currentptr==NULL)
	{
		printf("�䤣�즹����!\n");
	}
	//���O���٦����
	else
	{
		while (currentptr != NULL)
		{
			dataptr = currentptr->dataptr;

			//������
			while (dataptr != NULL)
			{
				//������
				if (strcmp(dataptr->name, taskname) == 0)
				{
					printf("�п�J�n��쪺���O: ");
					scanf("%s", categary);

					//�Ĥ@�Ӹ`�I�N���
					if (previousptr == NULL)
					{	
						//��s�U�@�ӥ��Ȭ������O���s�}�Y�`�I
						currentptr->dataptr = dataptr->nextptr;	
					}
					else
					{
						//�N�e�@��&��@�Ӹ`�I�s��
						previousptr->nextptr = dataptr->nextptr;	
					}
					break;	//break ����-while
				}
				//�w��F�����O����
				else if (dataptr->nextptr == NULL)
				{
					//�d�ݤU�@�����O
					currentptr = currentptr->nextptr;
					//�U�@�����O������
					if (currentptr->dataptr != NULL)
					{
						dataptr = currentptr->dataptr;
					}
				}
				//�d�ݤU�@�ӥ���
				else
				{
					previousptr = dataptr;
					dataptr = dataptr->nextptr;
				}
			}

			if (categary[0] != ' ')
			{
				break;	//break ���O-while
			}
		}
	}

	//�������O�@�s�W
	currentptr = *task_list;
	while (currentptr!=NULL)
	{
		//�������O
		if (strcmp(currentptr->category, categary) == 0)
		{
			dataptr->nextptr = currentptr->dataptr;	//dataptr ���V�쥻�����O���}�Y�`�I
			currentptr->dataptr = dataptr;	//��s dataptr ���s���}�Y�`�I

			printf("�������O��令�\!\n");
			break;
		}
		else if(currentptr->nextptr == NULL)
		{
			printf("�䤣��ӥ������O!\n");
		}
	}
}

// (3)�ק���ȸ�T
void change_task(task_sort** task_list) {}

// (4)�L�X�Ҧ�����
void prt_task(task_sort* task_list)
{

	task_sort* currentptr = NULL;
	task_data* thistask;

	if (task_list == NULL)
	{
		printf("�ثe�S�����!");
	}
	else
	{

		currentptr = task_list;	//�s���Ĥ@�ӥ������O
		while (currentptr != NULL)
		{
			printf("%s: \n", currentptr->category);
			thistask = currentptr->dataptr;	//�s������
			while (thistask != NULL)
			{
				//��X���Ȥ��e
				printf("���ȦW��: %s\n���Ȼ���: %s\n���n��: %d\n�t�d�H��: %s\n�ɵ{: %s\n�ثe�i��: %s\n���O: %s\n\n", thistask->name, thistask->explanation, thistask->importance, thistask->responsible_people, thistask->time, thistask->schedule, thistask->mark);

				thistask = thistask->nextptr;	//�s���U�@�ӥ���
			}
			currentptr = currentptr->nextptr;	//�s���U�@�ӥ������O
		}

	}
}

void foolproof_check(char* check)
{
	while (*check != 'Y' && *check != 'N')
	{
		printf("��J���~�Э��s��J :");
		scanf(" %c", &*check);
	}
}