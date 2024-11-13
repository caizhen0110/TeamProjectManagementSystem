/*
團隊專案管理系統
要用到Linked list。
有一小組負責一專案，寫一個程式記錄小組成員、專案內的多項任務(工作)的相關資訊與狀態。
(1) 小組成員人數不限，可以有不同角色。
	每位成員有基本資訊，如：姓名、電話、角色等。
	使用者可以新增成員、刪除成員、修改成員資訊、印出所有成員等。
(2) 專案中的任務(工作)可以分成多種類別，
	例如：功能分析、功能設計、程式撰寫、測試、完成等階段，或是活動設計、場地器材、宣傳等工作組。
	使用者可以自行定義類別的數量與各個類別的名稱。
(3) 每個任務(工作)有基本資訊，
	如：任務名稱、任務說明、重要性、負責人員、時程、目前進度、註記等等。
	一個任務會隸屬於一個類別，可以將任務換到另一個類別。
	使用者可以新增任務、更改任務類別、修改任務資訊、印出所有任務等。

系統細節、功能請自行設計。
*/

// 缺少 free(newnode);

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//小組成員
struct members
{
	char name[20];	//姓名
	char phone[11];	//電話
	char character[20];	//角色
	members* nextptr;	//下一位成員
};
//任務-基本資訊
struct task_data
{
	char name[30];	//任務名稱
	char explanation[100];	//任務說明
	int importance;	//重要性(1~10)
	char responsible_people[100];	//負責人員
	char time[20];	//時程
	char schedule[300];	//目前進度
	char mark[300];	//註記
	task_data* nextptr;	//下一個任務
};
//任務類別
struct task_sort
{
	char category[50];	//類別名稱
	task_sort* nextptr;	//下一個類別
	task_data* dataptr;	//任務
};

//成員設定:
// (1)新增成員
void new_members(members** members_list);
// (2)刪除成員
void delete_members(members** members_list);
// (3)修改成員資訊
void change_members(members** members_list);
// (4)印出所有成員
void prt_members(members* members_list);

//新增任務類別
void new_tasksort(task_sort** task_list);

//任務設定:
// (1)新增任務
void new_task(task_sort** task_list);
// (2)更改任務類別
void change_tasksort(task_sort** task_list);
// (3)修改任務資訊
void change_task(task_sort** task_list);
// (4)印出所有任務
void prt_task(task_sort* task_list);


//防呆:
void foolproof_check(char* check);


int main() {
	int choise = 0;
	members* members_list = NULL;
	task_sort* task_list = NULL;

	while (choise != -1)
	{
		printf("請選擇 1)成員設定 2)新增任務類別 3)任務設定 -1)結束 :");
		scanf("%d", &choise);

		switch (choise)
		{
		case 1:	//成員設定
			printf("請選擇 1)新增成員 2)刪除成員 3)修改成員資訊 4)印出所有成員 :");
			scanf("%d", &choise);

			switch (choise)
			{

			case 1:	//新增成員
				new_members(&members_list);
				break;

			case 2:	//刪除成員
				delete_members(&members_list);
				break;

			case 3:	//修改成員資訊
				change_members(&members_list);
				break;

			case 4:	//印出所有成員
				prt_members(members_list);
				break;
			default:
				printf("輸入錯誤!\n");
				break;
			}
			break;

		case 2:	//新增任務類別
			new_tasksort(&task_list);
			break;

		case 3:	//任務設定
			printf("請選擇 1)新增任務 2)更改任務類別 3)修改任務資訊 4)印出所有成員任務 :");
			scanf("%d", &choise);

			switch (choise)
			{

			case 1:	//新增任務
				new_task(&task_list);
				break;

			case 2:	//更改任務類別
				change_tasksort(&task_list);
				break;

			case 3:	//修改任務資訊
				change_task(&task_list);
				break;

			case 4:	//印出所有任務
				prt_task(task_list);
				break;
			default:
				printf("輸入錯誤!\n");
				break;
			}
			break;

		case -1:	//結束
			break;
		default:
			printf("輸入錯誤!\n");
			break;
		}
	}

	return 0;
}

// (1)新增成員
void new_members(members** members_list)
{
	members* newnode = (members*)malloc(sizeof(members));

	printf("請輸入 姓名 電話 角色 :");
	scanf("%s%s%s", newnode->name, newnode->phone, newnode->character);

	//原本沒有資料
	if (*members_list == NULL)
	{
		newnode->nextptr = NULL;	//newnode 指向 NULL
		*members_list = newnode;	//更新 newnode 為第一個節點
	}
	else
	{
		newnode->nextptr = *members_list;	//newnode 指向舊的開頭節點
		*members_list = newnode;	//newnode 成為新的開頭節點
	}
	printf("新增成員成功!\n");
}

// (2)刪除成員
void delete_members(members** members_list)
{
	members* currentptr = *members_list;
	members* previousptr = NULL;
	char user[11];
	char check = ' ';

	printf("請輸入欲刪除人員的電話 :");
	scanf("%s", user);

	if (currentptr == NULL)
	{
		printf("成員名單中查無此人員!\n");
	}
	while (currentptr != NULL)
	{
		//找到該人員資料
		if (strcmp(currentptr->phone, user) == 0)
		{
			printf("找到資料如下:\n姓名:%s\n電話:%s\n角色:%s\n\n是否為此人員(Y/N): ", currentptr->name, currentptr->phone, currentptr->character);
			scanf(" %c", &check);

			foolproof_check(&check);
			//要刪除
			if (check == 'Y')
			{
				if (previousptr != NULL) {
					previousptr->nextptr = currentptr->nextptr;	//當前節點的 前一個&後一個連結
				}
				else {
					*members_list = currentptr->nextptr;	//當前節點的 前一個&後一個連結
				}
				free(currentptr);	//刪除該人員
				printf("該人員資料已刪除!\n");
				break;
			}
			//查詢下一個節點
			else
			{
				previousptr = currentptr;
				currentptr = currentptr->nextptr;	//currenptr 更新為下一個節點

				if (currentptr == NULL)
				{
					printf("成員名單中查無此人員!\n");
				}
			}
		}
		//查詢下一個節點
		else
		{
			previousptr = currentptr;
			currentptr = currentptr->nextptr;	//currenptr 更新為下一個節點

			if (currentptr == NULL)
			{
				printf("成員名單中查無此人員!\n");
			}
		}
	}
}

// (3)修改成員資訊
void change_members(members** members_list)
{
	members* currentptr = *members_list;
	members* previousptr = NULL;
	char user[11];
	char check = ' ';
	int choise = 0;

	printf("請輸入欲修改人員的電話 :");
	scanf("%s", user);

	if (currentptr == NULL)
	{
		printf("成員名單中查無此人員!\n");
	}
	while (currentptr != NULL)
	{
		//找到該人員資料
		if (strcmp(currentptr->phone, user) == 0)
		{
			printf("找到資料如下:\n姓名:%s\n電話:%s\n角色:%s\n\n是否為此人員(Y/N): ", currentptr->name, currentptr->phone, currentptr->character);
			scanf(" %c", &check);

			foolproof_check(&check);
			//要修改
			if (check == 'Y')
			{
				while (check != 'N')
				{
					printf("請選擇要修改的部分 1)姓名 2)電話 3)角色 : ");
					scanf("%d", &choise);

					while (choise < 1 || choise>3)
					{
						printf("輸入錯誤請重新輸入: ");
						scanf("%d", &choise);
					}

					if (choise == 1)
					{
						printf("請輸入新的姓名: ");
						scanf("%s", currentptr->name);
					}
					else if (choise == 2)
					{
						printf("請輸入新的電話: ");
						scanf("%s", currentptr->phone);
					}
					else if (choise == 3)
					{
						printf("請輸入新的角色: ");
						scanf("%s", currentptr->character);
					}


					printf("請問是否還要繼續修改(Y/N): ");
					scanf(" %c", &check);
					foolproof_check(&check);
				}

				printf("該人員資料已更新!\n");
				break;
			}
			//查詢下一個節點
			else
			{
				previousptr = currentptr;
				currentptr = currentptr->nextptr;	//currenptr 更新為下一個節點

				if (currentptr == NULL)
				{
					printf("成員名單中查無此人員!\n");
				}
			}
		}
		//查詢下一個節點
		else
		{
			previousptr = currentptr;
			currentptr = currentptr->nextptr;	//currenptr 更新為下一個節點

			if (currentptr == NULL)
			{
				printf("成員名單中查無此人員!\n");
			}
		}
	}
}

// (4)印出所有成員
void prt_members(members* members_list)
{
	members* currentptr = members_list;

	if (currentptr == NULL)
	{
		printf("還沒有任何資料!\n");
	}
	while (currentptr != NULL)
	{
		printf("\n姓名:%s\t電話:%s\t角色:%s\n", currentptr->name, currentptr->phone, currentptr->character);	//印出該節點資料
		currentptr = currentptr->nextptr;	//查看下一個節點
	}
}

//新增任務類別
void new_tasksort(task_sort** task_list)
{
	task_sort* newnode = (task_sort*)malloc(sizeof(task_sort));
	task_sort* currentptr = NULL;

	printf("請輸入 類別名稱 :");
	scanf("%s", newnode->category);
	newnode->dataptr = NULL;

	//原本沒有資料
	if (*task_list == NULL)
	{
		newnode->nextptr = NULL;	//newnode 指向 NULL
		*task_list = newnode;	//更新 newnode 為第一個節點
	}
	else
	{
		currentptr = *task_list;
		//檢查不重複
		while (currentptr != NULL)
		{
			//重複
			if (strcmp(newnode->category, currentptr->category) == 0)
			{
				printf("此名稱已存在!請充新輸入 類別名稱 :");
				scanf("%s", newnode->category);
				currentptr = *task_list;
			}
			else {
				currentptr = currentptr->nextptr;
			}
		}

		newnode->nextptr = *task_list;	//newnode 指向舊的開頭節點
		*task_list = newnode;	//newnode 成為新的開頭節點
	}
	printf("任務類別新增成功!\n");
}

// (1)新增任務
void new_task(task_sort** task_list) {

	task_data* newnode = (task_data*)malloc(sizeof(task_data));
	task_sort* currentptr;
	char save_sort[50];	//欲放入的類別

	currentptr = *task_list;
	if (currentptr == NULL)
	{
		printf("沒有任何類別! 請先新增任務類別。\n");
	}
	else {
		printf("請輸入 任務名稱 任務說明 時程 : ");
		scanf("%s%s%s", newnode->name, newnode->explanation, newnode->time);
		printf("請輸入 負責人員 : ");
		scanf("%s", newnode->responsible_people);
		printf("請輸入 重要性(請填數字 1~10 ) : ");
		scanf("%d", &newnode->importance);
		printf("請輸入 目前進度 : ");
		scanf("%s", newnode->schedule);
		printf("請輸入 註記 : ");
		scanf("%s", newnode->mark);


		//印出所有類別
		printf("目前存在的類別: \n");
		while (currentptr != NULL)
		{
			printf("%s ", currentptr->category);
			currentptr = currentptr->nextptr;	//存取下一個類別名稱
		}
		printf("\n");

		printf("請輸入要儲存的類別名稱: ");
		scanf("%s", save_sort);

		//搜尋該類別名稱
		currentptr = *task_list;
		while (currentptr != NULL)
		{
			if (strcmp(save_sort, currentptr->category) == 0)
			{
				break;
			}
			else if (currentptr->nextptr == NULL)
			{
				printf("輸入錯誤!\n");
				printf("請輸入要儲存的類別名稱: ");
				scanf("%s", save_sort);

				currentptr = *task_list;
			}
			else {
				currentptr = currentptr->nextptr;	// 下一個類別
			}
		}

		//原本沒有資料
		if (currentptr == NULL)
		{
			newnode->nextptr = NULL;
			currentptr->dataptr = newnode;
		}
		//原本有資料
		else {
			newnode->nextptr = currentptr->dataptr;	//newnode 指向原本的開頭任務
			currentptr->dataptr = newnode;	//newnode 更新為開頭任務
		}
		printf("任務新增成功!\n");
	}

}

// (2)更改任務類別
void change_tasksort(task_sort** task_list) 
{
	task_sort* currentptr;
	task_data* dataptr;
	task_data* previousptr = NULL;
	char taskname[30];                                                                                                                                                                                                                                                                                                                                                                                                                              
	char categary[50] = { " " };	//新類別

	//印出所有類別
	printf("目前存在的類別: \n");
	currentptr = *task_list;
	if (currentptr == NULL)
	{
		printf("沒有任何類別!\n");

	}
	while (currentptr != NULL)
	{
		printf("%s ", currentptr->category);
		currentptr = currentptr->nextptr;	//存取下一個類別名稱
	}
	printf("\n");

	printf("請輸入要更改類別的任務名稱: ");
	scanf("%s", taskname);

	currentptr = *task_list;
	if(currentptr==NULL)
	{
		printf("找不到此任務!\n");
	}
	//類別中還有資料
	else
	{
		while (currentptr != NULL)
		{
			dataptr = currentptr->dataptr;

			//有任務
			while (dataptr != NULL)
			{
				//找到任務
				if (strcmp(dataptr->name, taskname) == 0)
				{
					printf("請輸入要改到的類別: ");
					scanf("%s", categary);

					//第一個節點就找到
					if (previousptr == NULL)
					{	
						//更新下一個任務為此類別的新開頭節點
						currentptr->dataptr = dataptr->nextptr;	
					}
					else
					{
						//將前一個&後一個節點連結
						previousptr->nextptr = dataptr->nextptr;	
					}
					break;	//break 任務-while
				}
				//已到達該類別結尾
				else if (dataptr->nextptr == NULL)
				{
					//查看下一個類別
					currentptr = currentptr->nextptr;
					//下一個類別有任務
					if (currentptr->dataptr != NULL)
					{
						dataptr = currentptr->dataptr;
					}
				}
				//查看下一個任務
				else
				{
					previousptr = dataptr;
					dataptr = dataptr->nextptr;
				}
			}

			if (categary[0] != ' ')
			{
				break;	//break 類別-while
			}
		}
	}

	//找到該類別作新增
	currentptr = *task_list;
	while (currentptr!=NULL)
	{
		//找到該類別
		if (strcmp(currentptr->category, categary) == 0)
		{
			dataptr->nextptr = currentptr->dataptr;	//dataptr 指向原本該類別的開頭節點
			currentptr->dataptr = dataptr;	//更新 dataptr 為新的開頭節點

			printf("任務類別更改成功!\n");
			break;
		}
		else if(currentptr->nextptr == NULL)
		{
			printf("找不到該任務類別!\n");
		}
	}
}

// (3)修改任務資訊
void change_task(task_sort** task_list) {}

// (4)印出所有任務
void prt_task(task_sort* task_list)
{

	task_sort* currentptr = NULL;
	task_data* thistask;

	if (task_list == NULL)
	{
		printf("目前沒有資料!");
	}
	else
	{

		currentptr = task_list;	//存取第一個任務類別
		while (currentptr != NULL)
		{
			printf("%s: \n", currentptr->category);
			thistask = currentptr->dataptr;	//存取任務
			while (thistask != NULL)
			{
				//輸出任務內容
				printf("任務名稱: %s\n任務說明: %s\n重要性: %d\n負責人員: %s\n時程: %s\n目前進度: %s\n註記: %s\n\n", thistask->name, thistask->explanation, thistask->importance, thistask->responsible_people, thistask->time, thistask->schedule, thistask->mark);

				thistask = thistask->nextptr;	//存取下一個任務
			}
			currentptr = currentptr->nextptr;	//存取下一個任務類別
		}

	}
}

void foolproof_check(char* check)
{
	while (*check != 'Y' && *check != 'N')
	{
		printf("輸入錯誤請重新輸入 :");
		scanf(" %c", &*check);
	}
}