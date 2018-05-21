#include <stdio.h>
#include <stdlib.h>
#include<string.h>

// included to check for memory leaks
#define CRTDBG_MAP_ALLOC // Visual Studio 
#include <crtdbg.h>      // Visual Studio

#pragma warning(disable: 4996)	//Visual Studio

#define MAX_SIZE 100
//Forward Declerations
void BuildLinkedList();
void ReadInputFile();
void SaveLinkedList();
void DisplayLinkList();

//Global Variables for Procces 
FILE *fp;
char lineInFile[MAX_SIZE];
char grade[MAX_SIZE];

//Struct Definition
struct Node
{
	char name[MAX_SIZE];
	float finalGrade;
	struct Node *next;
};
struct Node *startPointer = NULL;
//Forward Declerations

int main()
{
	printf("\nCSE-310 Recitation - Take Home Activity\n");
	ReadInputFile();
	BuildLinkedList();
	
	SaveLinkedList();
	DisplayLinkList();
	


	return 0;
}

void ReadInputFile()
{
	char buffer[255];
	fp = fopen("input.txt", "r");

	if (!fp)
	{
		printf("File does not exists \n");
		return;
	}
	while (fgets(buffer, 255, fp) != NULL)
	{
		printf(" %s", buffer);
	}
	fclose(fp);
}

void BuildLinkedList()
{
	
	if ((fp = fopen("input.txt", "r")) == NULL)
	{
		printf("ERROR: Sorry input.txt file does not exist LinkedList Cannot be Built");
		exit(1);
	}
	printf("\nEnter Grades\n");
	while(fgets(lineInFile, sizeof(lineInFile), fp))
	{
		struct Node *ListMember = (struct Node*)malloc(sizeof(struct Node));
		
		strcpy(ListMember->name, lineInFile);
		ListMember->finalGrade = 0.00;
		ListMember->next = startPointer;
		startPointer = ListMember;
	}
	fclose(fp);
}

void SaveLinkedList()
{
	struct Node* studentListPointer = startPointer;
	fp = fopen("output.txt", "wb");
	while (studentListPointer != NULL)
	{
		printf("%s", studentListPointer->name);
		scanf("%f", &studentListPointer->finalGrade);
		gcvt(studentListPointer->finalGrade, 6, grade);
		fputs(studentListPointer->name, fp);
		fputs(" ", fp);
		fputs(grade, fp);
		fputs("\n", fp);
		studentListPointer = studentListPointer->next;
	}
	fclose(fp);
}

void DisplayLinkList()
{
	struct Node *List = startPointer;
	if (List == NULL)
	{
		printf("List is Empty !\n");
		return;
	}
	else
	{
		while (List != NULL)
		{
			printf("%s ", List->name);
			printf("%.2f ", List->finalGrade);

			List = List->next;
		}
	}
}