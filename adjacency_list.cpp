#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define max 10
class node
{
	friend class graph;
	char city[10];
	int time;
	node *next;
};
class graph
{
	int total;
	node *start_city[max],*ptr;
  public:
  	graph()
  	{
  		for(int i=0;i<10;i++)
			start_city[i]=NULL;
			
	}
  	int check(char[]);
  	node* create_node(int,char[]);
  	void insert(int,char[],char[]);
	void display();
};
node* graph::create_node(int dur,char name[])
{
	ptr=new node;
	ptr->time=dur;
	strcpy(ptr->city,name);
	ptr->next=NULL;
	return ptr;
}
int graph::check(char name[])
{
	int flag=0,i;
	for(i=0;start_city[i]!=NULL;i++)
	{
		if(strcmp(start_city[i]->city,name)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		start_city[i]=create_node(0,name);
	return i;	
}
void graph::insert(int dur,char city1[],char city2[])
{
	int pos,flag=0;
	node *np;
	pos=check(city1);
	np=start_city[pos];
	while(np->next!=NULL)
	{
		if(strcmp(np->next->city,city2)==0)
		{
			flag=1;
			break;
		}
		np=np->next;
	}
	if(flag!=1)
		np->next=create_node(dur,city2);
	else
		cout<<"\nALREADY ENTERED SOURCE AND DESTINATION";				
}
void graph::display()
{
	int i=0;
	node *np;
	for(i=0;start_city[i]!=NULL;i++)
	{
		np=start_city[i];
		cout<<"["<<np->city<<"|"<<np->time<<"]"<<" --> ";
		while(np->next!=NULL)
		{
			cout<<"["<<np->next->city<<"|"<<np->next->time<<"]"<<" --> ";
			np=np->next;
		}
		cout<<"NULL\n   |\n";
	}
	cout<<"  NULL";
}
int main()
{
	int choice,num,dur;
	char ch,source[10],dest[10];
	graph ob;
	do
	{
	cout<<"\n1. insert";
	cout<<"\n2.display";
	cout<<"\nchoice : ";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"\nenter source : ";
			cin>>source;
			cout<<"\nenter destination : ";
			cin>>dest;
			cout<<"\nenter duration (in hrs) : ";
			cin>>dur;
			ob.insert(dur,source,dest);
			ob.check(dest);		
			break; 	
		case 2: cout<<"\ngraph contains :-\n";
			ob.display();			
			break;
		case 3: exit(1);
		default:cout<<"\nWRONG CHOICE!!!";			
	}
	cout<<"\ncontinue (y/n) : ";
	cin>>ch;
	}while(ch=='y');
	return 0;
}


