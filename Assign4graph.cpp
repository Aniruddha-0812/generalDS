/*
a) Consider a friends’ network on face book social web site. Model it as a graph to represent each node
as a user and a link to represent the fried relationship between them. Store data such as date of birth,
number of comments for each user.
i) Find who is having maximum friends
Hint: Use adjacency list representation
b) For a friends’ network,
ii) Find who has post maximum and minimum comments (using BFS)
iii) Find users having birthday in this month (using DFS)
*/
#include<bits/stdc++.h>

using namespace std;

class node
{
	public:
	int index;
	char name[20];
	int day,month,year,numCom,numLikes,numFrnds;
	node *next;
	node();
	node(int i,char *n,int d,int m,int y,int nC,int nL,int nF);
};

node::node()
{
	index=0;
	name[0]='\0';
	next=NULL;
	day=0;
	month=0;
	year=0;
	numCom=0;
	numLikes=0;
	numFrnds=0;
	
}

node::node(int i,char *n,int d,int m,int y,int nC,int nL,int nF)
{
	index=i;
	strcpy(name,n);
	next=NULL;
	day=d;
	month=m;
	year=y;
	numCom=nC;
	numLikes=nL;
	numFrnds=nF;
}

class graph
{
public:
	node *G[20];
	int numUsers,mon;
	int frnds[20],visited[20];
	void readGraph();
	void insert(int a,int b);
	void printGraph();
	void bfs();
	void dfsCall(node *temp,int month);
	void maxFrnds();
	void dfs()
	{
		cout<<"Enter month \t";
		cin>>mon;
		dfsCall(G[0],mon);
	}
};
void graph::maxFrnds()
{
	int max=0,idx=0;
	for(int i=0;i<numUsers;i++)
	{
		if(frnds[i]>max)
		{
			max=frnds[i];
			idx=i;	
		}
	}
		
	cout<<G[idx]->name<<" has maximum number Friends \n";
}
void graph::readGraph()
{
	char name[20];
	int index,day,month,year,numCom,numLikes,numFrnds;
	for(int i=0;i<numUsers;i++)
	{
		cout<<"\n\nEnter name\t";cin>>name;
		cout<<"Enter birthday in format of ---day month year---\t";cin>>day>>month>>year;
		cout<<"Enter number of comments\t";cin>>numCom;
		cout<<"Enter number of likes\t";cin>>numLikes;
		cout<<"Enter number of Friends\t";cin>>numFrnds;
		
		frnds[i]=numFrnds;
		G[i]=new node(i+1,name,day,month,year,numCom,numLikes,numFrnds);
	}
}

void graph::insert(int a,int b)
{
	node *temp=new node(*G[b-1]);
	
	node *t=G[a-1];
	
	while(t->next!=NULL)
		t=t->next;
	t->next=temp;
}

void graph::printGraph()
{
	for(int i=0;i<numUsers;i++)
	{
		cout<<"Friends of "<<G[i]->name<<" are : ";
		node *temp=G[i]->next;
		while(temp!=NULL)
		{
			cout<<temp->name<<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}
}

void graph::bfs()
{
	queue<node*>q;
	node *p=G[0], *temp;
	int min=p->numCom,max=p->numCom,minidx=p->index,maxidx=p->index;
	for(int i=0;i<10;i++)
		visited[i]=0;
	visited[p->index]=1;
	q.push(p);
	
	while(!q.empty())
	{
		temp=q.front();q.pop();
		
		p=temp->next;
		while(p!=NULL)
		{
			if(!visited[p->index])
			{
				if(p->numCom > max)
				{
					max=p->numCom;
					maxidx=p->index;
				}
				if(p->numCom < min)
				{
					min=p->numCom;
					minidx=p->index;
				}
				visited[p->index]=1;
				q.push(p);
			}
			p=p->next;
		}
		
	}
	cout<<"Maximum number of comments are "<<max<<" by person of index "<<maxidx<<"\n";
	cout<<"Minimum number of comments are "<<min<<" by person of index "<<minidx<<"\n";
}

void graph::dfsCall(node *temp,int month)
{
	if(month==temp->month)
		cout<<temp->name<<" has birthday in "<<month<< " month \n";
		
	temp=temp->next;
	if(temp!=NULL)
	{
			dfsCall(temp,month);
	}
}

int main()
{
	graph gra;
	cout<<"Enter total number of friends in network\n";
	cin>>gra.numUsers; 
	gra.readGraph();
	
	int t,relnum,choice;
	cout<<"Enter relation of each friend\n";
	for(int i=0;i<gra.numUsers;i++)
	{
		cout<<"Enter number of relation for "<< i+1 <<"\t";
		cin>>relnum;
		for(int i=0;i<relnum;i++)
		{
		cin>>t;
		gra.insert(i+1,t);
		}
			 
	}
	
	
	while(1)
	{
	cout<<"\n\n1.Maximum number of friends\n2.maximum and minimum comments\n3.users having birthday in this month\n4.Exit\n\n";
	
	cin>>choice;
		switch(choice)
		{
			case 1:gra.maxFrnds();break;
			case 2:gra.bfs();break;
			case 3:gra.dfs();break;
			case 4:exit(1);
			default:
			cout<<"Please enter valid choice\n";
		}
	}
}
