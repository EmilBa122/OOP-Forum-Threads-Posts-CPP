#include <iostream>
#include <string>
#include <cstdlib>
#include "classes_.hpp"

using namespace std;

forum::forum(const string name,int sum)//CONSTRUCTOR OF THE FORUM THAT TAKES AS ARGUMENTS THE TITLE OF THE FORUM AND THE NUMBER OF THREADS OF THE FORUM
{
	int i;
	tittle =name;
	sum_thread=sum;
	th=new thread*[sum_thread];
	for(i=0; i<sum_thread; i++)
	{
		if(i==0)//THE FIRST THREAD OF THE FORUM WILL HAVE NAME kanones kai useful xrhsimes plhrofories AND EACH THREAD WILL HAVE 4 POSTS AND THE CREATORS 
		{		//ARE FOUR WHERE THEY ARE CHOSEN AT RANDOM EACH TIME A THREAD OR POST IS MADE 
			th[i]=new thread("Kanones kai xrhsimes plhrofories","creator"+to_string(rand()%4),4);
		}
		else
		{
			th[i]=new thread("theme"+to_string(i),"creator"+to_string(rand()%4),4);
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
{								//FUNCTION THAT TAKES THE NAME OF A THREAD AND TRIES TO FIND IT IN THE FORUM AND IF IT IS FOUND PRINTS THIS THREAD
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
		else
		{
			cout<<"theme not found"<<endl;
		}
}

void forum::print_post(int i)
{	//FUNCTION THAT TAKES A NUMBER AND TRIES TO SEE IF THERE IS AN id OF A POST THAT IS EQUAL TO THIS NUMBER TO PRINT THE POST OF THIS FORUM
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

thread::thread(const string s1,const string s2,int sum)
{	//CONSTRUCTOR OF THE THREAD THAT TAKES AS ARGUMENTS THE THEME THE NAME OF THE CREATOR AS WELL AS THE NUMBER OF POSTS THAT WILL BE CONTAINED IN THIS THREAD
	int g;
	theme=s1;
	creator=s2;
	creation_date.set();//I CALL THIS FUNCTION TO INITIALIZE THE CREATION DATE OF THE THREAD
	sum_post=sum;
	po=new post*[sum_post];
	for(g=0; g<sum_post; g++)//THE GLOBAL VARIABLE IS USED FOR THE id OF THE post AND WE CHOOSE AT RANDOM WHICH OF THE FOUR CREATORS WILL MAKE THE POST
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

void thread::print()//FUNCTION THAT PRINTS THE THREAD
{
	int i;
	cout<<"theme is "<<theme<<" creator is "<<creator<<" creation date is "<<endl;
	creation_date.print();
	cout<<"print all the post of this thread"<<endl;
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

post::post(const string s1,const string s2)//CONSTRUCTOR OF THE POST THAT TAKES AS ARGUMENTS THE TITLE OF THE POST AND THE CREATOR OF THE POST
{
	int random=(rand()%51);//HERE A TEXT IS CHOSEN RANDOMLY FROM THE GLOBAL TABLE OF texts AND IS ASSIGNED TO THE text OF THE post
	id=sum_global;
	tittle=s1;
	creator=s2;
	creation_date.set();//I CALL THIS FUNCTION TO INITIALIZE THE CREATION DATE OF THE POST
	text=texts[random];
	sum_global++;
	print();//WE PRINT THIS POST 
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