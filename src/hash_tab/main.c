#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <hash_tab.h>

#define SLOTS 16

void chaining_type();
void open_adressing_type();

int main()
{
	srand(time(NULL));

	int answer;
	
	printf("Hello! This program demonstrates the work of hash table\n
	wich type of collision solution do you need?\n1)chaining\n2)open adressing\n");
	scanf("%d", &answer);
	if(answer == 1)
	{
		chaining_type();
	}
	else if(answer == 2)
	{
		open_adressing_type();
	}
	else
	{
		printf("You need to write 1 or 2. Try again");
	}
}

void chaining_type()
{
	hash_tab_chain* hash_tab = init_hash_tab_chain(SLOTS);
	for(int i = 0; i < SLOTS; i++)
	{
		insert_hash_tab_chain(rand(), rand(), hash_tab);
	}
}

void open_adressing_type()
{

}