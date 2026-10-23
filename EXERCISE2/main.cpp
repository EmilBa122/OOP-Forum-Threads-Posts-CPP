
#include <iostream>
#include <string>
#include <cstdlib>
#include "classes.hpp"
using namespace std;


//string texts[50];
//int sum_global;

int main()
{
	int i;
	int random;
	for(i=0; i<50; i++)
	{
		texts[i]="text"+to_string(i);//HERE WE ASSIGN TO THE i POSITION THE TEXT "texti" SO WE WILL HAVE IN THIS TABLE text0,text1,text2,text3............
	}
	string name;
	name="Antikeimenostrafhs Programmatismos";
	forum f1(name,2);//WE CREATE THE FORUM WITH NAME name AND IT WILL HAVE TWO threads 		
	int sum_thread=f1.get_sum_thread();//WE TAKE THE NUMBER OF THREADS THAT THIS FORUM HAS 
	for(i=0; i<sum_thread; i++)
	{
		tree t1;
		thread *th=f1.get_thread(i);//RETURNS THE ADDRESS WHICH POINTS TO A THREAD STRUCTURE DEPENDING ON THE VALUE OF i
		post **p1=th->get_post();//RETURNS THE ADDRESS WHICH POINTS TO A TABLE THAT CONTAINS ADDRESSES WHERE EACH ADDRESS POINTS TO A POST STRUCTURE OF THE SPECIFIC THREAD WHERE WE ARE NOW
		int sum_post=th->get_sum_post();///RETURNS THE NUMBER OF POSTS THAT THE THREAD WHERE WE ARE NOW HAS 
		cout<<"TREE IS"<<endl;
		t1.print_sorted(th,p1,sum_post);//AND WE GO TO MAKE THE TREE GIVEN THE THREAD WHERE WE ARE NOW 
	}
}
