#include <iostream>
#include <string>
#include <cstdlib>
#include "classes.hpp"

using namespace std;

string texts[50];
int sum_global;

forum::forum(const string name,int sum)//CONSTRUCTOR OF THE FORUM THAT TAKES AS ARGUMENTS THE TITLE OF THE FORUM AND THE NUMBER OF THREADS OF THE FORUM 
{
	int i;
	tittle =name;
	sum_thread=sum;
	th=new thread*[sum_thread];
	for(i=0; i<sum_thread; i++)
	{
		if(i==0)//THE FIRST THREAD OF THE FORUM WILL HAVE NAME kanones kai xrhsimes plhrofories AND EACH THREAD WILL HAVE 4 POSTS AND THE CREATORS
		{		//ARE FOUR WHERE THEY ARE CHOSEN RANDOMLY EACH TIME THAT A THREAD OR POST IS CREATED
			th[i]=new thread("Kanones kai xrhsimes plhrofories","creator"+to_string(rand()%sum),4);
		}
		else
		{
			th[i]=new thread("theme"+to_string(i),"creator"+to_string(rand()%sum),4);
		}
	}
	cout <<"Forum with tittle: "<<tittle <<" has just been created!"<<endl;
	cout<<"\n\n";
}

forum::~forum()//DESTRUCTOR OF THE FORUM
{
	int i;
	for(i=0; i<sum_thread; i++)
	{
		delete	th[i];		
	}	
	delete	[] th;
	cout <<"Forum with tittle: "<<tittle<<" is about to be destroyed"<<endl;
}

void forum::print()//FUNCTION THAT PRINTS ONLY THE NAMES OF THE THREADS THAT BELONG TO THIS FORUM
{
	int i;
	cout<<"All the names of threads of this forum are "<<endl;
	for(i=0; i<sum_thread; i++)
	{
		th[i]->print_only_theme_of_thread();
	}
	cout<<"\n\n";
}

void forum::print_thread(const string name)
{									//FUNCTION THAT TAKES THE NAME OF A THREAD AND TRIES TO FIND IT IN THE FORUM AND IF IT IS FOUND PRINTS THIS THREAD
		int i=0;
		while(name!=th[i]->get_theme())//WHILE THE NAME IS NOT EQUAL TO THE NAME OF THE THREAD SEARCH THE NEXT THREAD
		{
			i++;
			if(i>=sum_thread)//IF WE HAVE THE SAME OR EXCEEDING OF THE NUMBER OF THREADS THAT BELONG TO THIS FORUM IT MEANS THAT WE DID NOT FIND IT
			{
				break;
			}	
		}
		if(i<sum_thread)//IF THIS CONDITION IS TRUE IT MEANS THAT WE FOUND THIS THREAD SO WE PRINT IT
		{
				th[i]->print();
		}
		else{
			cout<<"theme not found"<<endl;
		}
}

void forum::print_post(int i)
{	//FUNCTION THAT TAKES A NUMBER AND TRIES TO SEE IF THERE IS AN id OF A POST THAT IS EQUAL TO THIS NUMBER IN ORDER TO PRINT THE POST OF THIS FORUM
	int g=0;
	while(g<sum_thread)
	{
		if(th[g]->search_id(i))
		{
			return;
		}
		g++;
	}
	cout<<"post not found"<<endl;
}

int forum::get_sum_thread()//RETURNS THE NUMBER OF THREADS THAT THIS FORUM HAS 
{
	return sum_thread;
}

thread * forum::get_thread(int i)//RETURNS THE ADDRESS WHICH POINTS TO A THREAD STRUCTURE DEPENDING ON THE VALUE OF i
{
	return th[i];
}

thread::thread(const string s1,const string s2,int sum)
{	//CONSTRUCTOR OF THE THREAD THAT TAKES AS ARGUMENTS THE THEME THE NAME OF THE CREATOR AS WELL AS THE NUMBER OF POSTS THAT WILL BE CONTAINED IN THIS THREAD
	int g;
	theme=s1;
	creator=s2;
	creation_date.set();//WE CALL THIS FUNCTION TO INITIALIZE THE CREATION DATE OF THE THREAD
	sum_post=sum;
	po=new post*[sum_post];
	for(g=0; g<sum_post; g++)//THE GLOBAL VARIABLE IS USED FOR THE id OF THE post AND WE CHOOSE RANDOMLY WHICH OF THE FOUR CREATORS WILL MAKE THE POST
	{
		po[g]=new post("tittle"+to_string(sum_global),"creator"+to_string(rand()%4));
	}
	cout<<"Thread with subject: "<<theme<<" has just been created!"<<endl;
}

thread::~thread()//DESTRUCTOR OF THE THREAD
{
	int i;
	for(i=0; i<sum_post; i++)
	{
		delete po[i];
	}
	delete [] po;
	cout<<"Thread with subject: "<<theme<<" is about to be destroyed"<<endl;
}

void thread:: print()//FUNCTION THAT PRINTS THE THREAD
{
	int i;
	cout<<"theme is "<<theme<<" creator is "<<creator<<endl;
	creation_date.print();
	for(i=0; i<sum_post; i++)
	{
		po[i]->print();
	}
}

void thread::print_only_theme_of_thread()//FUNCTION THAT PRINTS THE THEME OF THE THREAD
{
	cout<<theme<<endl;
}

string thread::get_theme()//FUNCTION THAT RETURNS THE THEME OF THE THREAD
{
	return theme;
}

int thread::search_id(int i)//FUNCTION THAT SEARCHES THE ID OF THE POST AND IF IT IS FOUND PRINTS THE SPECIFIC POST
{
	int g=0;
	while(g<sum_post)
	{
		if(po[g]->get_id()==i)
		{
			po[g]->print();
			return 1;
		}
		g++;
	}
	return 0;
}

int thread::get_sum_post()//RETURNS THE NUMBER OF POSTS THAT THE THREAD HAS
{
	return sum_post;
}

post **thread::get_post()//RETURNS THE ADDRESS WHICH POINTS TO A TABLE THAT CONTAINS ADDRESSES WHERE EACH ADDRESS POINTS TO A POST STRUCTURE
{
	return po;
}

post::post(const string s1,const string s2)//CONSTRUCTOR OF THE POST THAT TAKES AS ARGUMENTS THE TITLE OF THE POST AND THE CREATOR OF THE POST
{
	int random=(rand()%51);//HERE A TEXT IS CHOSEN RANDOMLY FROM THE GLOBAL TABLE OF texts AND IS ASSIGNED TO THE text OF THE post
	id=sum_global;
	tittle=s1;
	creator=s2;
	creation_date.set();//WE CALL THIS FUNCTION TO INITIALIZE THE CREATION DATE OF THE POST
	text=texts[random];
	sum_global++;
	print();//WE PRINT THIS POST
}

post::post()//THE SECOND CONSTRUCTOR OF THE POST IS USED BECAUSE WE HAVE IN THE struct list_node post content SO WE JUST WANT TO CREATE A post
{
	
}

post::~post()//DESTRUCTOR OF THE POST
{
	cout<<"Post number: "<<id<<" is about to be destroyed"<<endl;
}

void post::print()//FUNCTION THAT PRINTS THE POST
{
	cout<<"id is "<<id<<" tittle is "<<tittle<<" creator is "<<creator<<" creation date is "<<endl;
	creation_date.print();
	cout<<"and text is "<<text<<endl;
}

int post::get_id()//FUNCTION THAT RETURNS THE id OF THE POST
{
	return id;
}

string post::get_creator()//RETURNS THE creator OF THE SPECIFIC post
{
	return creator;
}

void date::set()//FUNCTION THAT INITIALIZES THE DATE
{
	day=(rand()%31)+1;//WE CHOOSE A RANDOM NUMBER IN THE INTERVAL [1,31] FOR THE DAY
	month=(rand()%12)+1;//WE CHOOSE A RANDOM NUMBER IN THE INTERVAL [1,12] FOR THE MONTH
	year=(rand()%2)+2019;//WE CHOOSE A RANDOM NUMBER IN THE INTERVAL [2019,2020] FOR THE YEAR 
}

void date::print()//FUNCTION THAT PRINTS THE DATE
{
	cout<<"day "<<day<<" month "<<month<<" year "<<year<<endl;
}

list::list()//CONSTRUCTOR OF THE LIST THAT SIMPLY ASSIGNS TO THE HEAD POINTER THE NULL
{
	list_head=NULL;
}

int list::list_empty()//WE SEE IF THE LIST IS EMPTY
{
	return (list_head==NULL);
}

int list::add_node_to_list(post  *item)//FUNCTION THAT INSERTS A NODE IN THE LIST
{
	list_node *neos=new (struct list_node);
	if(neos==NULL)
	{
		return 1;
	}
	neos->content=*item;//WE ASSIGN TO THE content A post STRUCTURE DEPENDING ON WHICH post STRUCTURE THE POINTER item POINTS TO  
	neos->next=list_head;
	list_head=neos;
}

int list::list_print()//FUNCTION THAT PRINTS THE LIST
{
	struct list_node *temp;
	temp=list_head;
	if (temp==NULL ) 
	{
		return 1;
	} 
	else 
	{
		cout<<("List: ")<<endl;
		while (temp) 
		{
			temp->content.print();
			cout<<(" ")<<endl;
			temp=temp->next;
		}
		cout<<"\n"<<endl;
	}
	return 0;
}

int list::list_destroy()//FUNCTION THAT DESTROYS THE LIST
{
	list_node *temp;
	if(list_head==NULL)
	{
		return 1;
	}
	else
	{
		while(list_head)
		{
			temp=list_head;
			list_head=list_head->next;
			delete (temp);
		}
	}
	return 0;
}

list::~list()//DESTRUCTOR OF THE LIST WHICH CALLS THE DESTRUCTION FUNCTION OF THE LIST
{
	list_destroy();
}

tree::tree()//CONSTRUCTOR OF THE TREE THAT SIMPLY ASSIGNS TO THE POINTER OF ITS ROOT THE NULL
{
	root=NULL;	
}

int tree::tree_empty()//WE SEE IF THE TREE IS EMPTY
{
	return (root==NULL);
}

struct tree_node * tree::new_node(string info)//FUNCTION THAT CREATES A NEW NODE
{
	struct tree_node *neos=new (struct tree_node);
	neos->creator=info;
	neos->left=NULL;
	neos->right=NULL;
	return neos;
}

void tree::tree_insert_post(post *item)//WE INSERT INTO THE TREE A post STRUCTURE THAT THE POINTER item POINTS TO SO THAT THE TREE IS SORTED
{
	struct tree_node *next,*current;
	int isleft=0;
	current=root;
	if(root==NULL)//IF THE TREE IS EMPTY MAKE THE NEW NODE WHERE THE root WILL POINT TO IT AND ADD TO THE PART OF THE LIST THE post POINTED TO  
	{			 //BY THE POINTER item
		struct tree_node *ptr;
		ptr=new_node(item->get_creator());
		root=ptr;
		root->li.add_node_to_list(item);
		return;
	}
	while(1)//IF THE TREE IS NOT EMPTY 
	{
		if(item->get_creator()<current->creator)//IF THE creator OF THE post THAT THE POINTER item POINTS TO IS SMALLER THAN THE creator WHERE WE ARE NOW GO 
		{									   //TO THE LEFT CHILD
			next=current->left;
			isleft=1;
		}
		else if(item->get_creator()>current->creator)//IF THE creator OF THE post THAT THE POINTER item POINTS TO IS BIGGER THAN THE creator WHERE WE ARE NOW
		{											//GO TO THE RIGHT CHILD
			next=current->right;
			isleft=0;
		}
		else//IF THE creator OF THE post THAT THE POINTER item POINTS TO IS EQUAL TO THE creator WHERE WE ARE NOW ASSIGN THE post TO THE PART OF THE LIST
		{
			current->li.add_node_to_list(item);
			return;
		}
		if(next==NULL)//IF THE creator OF THE SPECIFIC post DOES NOT EXIST IN THE TREE MAKE A NEW NODE  AND PLACE IT IN THE CORRECT POSITION IN THE TREE
		{
			struct tree_node *ptr;
			ptr=new_node(item->get_creator());
			if(isleft==1)
			{
				current->left=ptr;
				current->left->li.add_node_to_list(item);//ASSIGNS THE post TO THE PART OF THE LIST OF THE SPECIFIC NEW NODE
			}
			else
			{
				current->right=ptr;
				current->right->li.add_node_to_list(item);//ASSIGNS THE post TO THE PART OF THE LIST OF THE SPECIFIC NEW NODE 
			}
			return;
		}
		current=next;
	}
	return;
}

void tree::tree_destroy(tree_node **root)//FUNCTION THAT DESTROYS THE TREE
{
	if(*root==NULL)
	{
		return;
	}
	tree_destroy(&(*root)->left);
	tree_destroy(&(*root)->right);
	(*root)->li.list_destroy();
	delete (*root);
	*root=NULL;
}

struct tree_node * tree::set()//FUNCTION THAT ASSIGNS TO A POINTER THE ADDRESS OF THE TREE
{
	struct tree_node *temp;
	return (temp=root);
}

void tree::inorder_print(struct tree_node *ptr)//FUNCTION THAT PRINTS THE NODES OF THE TREE FIRST BY DEPTH AND FROM THE LEFT TO THE RIGHT
{
	if(ptr==NULL)
	{
		return ;
	}
	inorder_print(ptr->left);
	cout<<"creator of this post is "<<ptr->creator<<endl;
	ptr->li.list_print();
	inorder_print(ptr->right);
}

tree::~tree()//DESTRUCTOR OF THE TREE THAT CALLS THE DESTRUCTION FUNCTION OF THE TREE
{
	tree_destroy(&root);
	cout<<"\n";	
}

void tree::create_tree_from_thread(thread *th,post **p1,int sum)//WE CREATE A TREE FROM EACH THREAD OF THE FORUM 
{
	int i;
	for(i=0; i<sum; i++)
	{
		tree_insert_post(p1[i]);
	}
}

void tree::print_sorted(thread *th,post **p1,int sum)//WE PRINT THE TREE SORTED IN ASCENDING ORDER
{
	this->create_tree_from_thread(th,p1,sum);
	struct tree_node *ptr=this->set();
	this->inorder_print(ptr);
	
}

