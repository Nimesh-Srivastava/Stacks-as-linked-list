#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<process.h>

using namespace std;

struct node
{
	int info;
	node *next;
}*top, *newptr, *save, *ptr;

node * create_new_node(int);
void push(node*);
void pop();
void display(node*);

int main()
{
	int inf;
	char ch = 'y';
	top = NULL;
	system("cls");
	while (ch == 'y' || ch == 'Y')
	{
		system("cls");
		cout << "\n\tEnter information for new node : ";
		cin >> inf;
		newptr = create_new_node(inf);
		if (newptr == NULL)
		{
			cout << "\n\tCannot create new node!! Aborting!!! ";
			_getch();
			exit(1);
		}
		push(newptr);
		cout << "\n\n\tNow the linked stack is : \n\n";
		display(top);
		cout << "\n\n\tPress Y to enter more nodes, N to initiate deletion : ";
		cin >> ch;
	}
	system("cls");
	cout << "\n\n\tNow deletion begins......";
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		pop();
		cout << "\n\n\tNow the stack is : \n";
		display(top);
		cout << "\n\n\tWant to delete more(y/n) : ";
		cin >> ch;
		system("cls");
	}
	return 0;
}

node * create_new_node(int n)
{
	ptr = new node;
	ptr->info = n;
	ptr->next = NULL;
	return ptr;
}

void push(node * np)
{
	if (top == NULL)
	{
		top = np;
	}
	else
	{
		save = top;
		top = np;
		np->next = save;
	}
}

void display(node * np)
{
	cout << "\t";
	if (top == NULL)
	{
		cout << "\n\n\tUnderflow!!!";
		return;
	}
	cout << np->info << " <-- top" << endl;
	np = np->next;
	while (np != NULL)
	{
		cout << "\t" << np->info << " -> " << endl;
		np = np->next;
	}
	cout << "\t" << "END";
}

void pop()
{
	if (top == NULL)
	{
		cout << "\n\tUnderflow!!!";
		exit(1);
	}
	else
	{
		ptr = top;
		top = top->next;
		delete ptr;
	}
}