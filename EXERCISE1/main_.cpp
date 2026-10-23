#include <iostream>
#include <string>
#include <cstdlib>
#include "classes_.hpp"

using namespace std;

string texts[50];//GLOBAL TABLE THAT HOLDS THE TEXTS THAT LATER WILL BE ASSIGNED TO THE PART text OF THE CLASS post
int sum_global;//GLOBAL VARIABLE THAT IS USED FOR THE id OF THE POSTS THAT IS UNIQUE FOR EACH POST

int main()
{
	int i;
	int random;
	for(i=0; i<50; i++)
	{
		texts[i]="text"+to_string(i);//HERE I ASSIGN IN THE i POSITION THE TEXT "texti" SO WE WILL HAVE IN THIS TABLE text0,text1,text2,text3............
	}
	string name;
	name="Antikeimenostrafhs Programmatismos";
	forum f1(name,4);//WE CREATE THE FORUM WITH NAME name AND IT WILL HAVE FOUR threads 	
	f1.print();//WE PRINT THE NAMES OF THE threads THAT BELONG TO THIS FORUM 
	f1.print_thread("Kanones kai xrhsimes plhrofories");//WE PRINT THE SPECIFIC thread 
	cout<<"\n\n\n";
	cout<<"print 5 random post of this forum "<<endl;
	i=0;
	int *A=new int[sum_global];
	for(i=0; i<sum_global; i++)//TO NOT PRINT THE SAME POST MORE THAN ONE TIME WE USE THE TABLE A THAT  WE INITIALIZE ALL ITS POSITIONS 
	{						  //WITH ZERO SO THAT IN THE POSITION E.G. ZERO WE MEAN THE FIRST POST.THEN WE SEE IF IN THE POSITION OF THE TABLE A THAT IS POINTED BY THE VARIABLE
		A[i]=0;					//random WHOSE VALUE WAS CHOSEN RANDOMLY HAS BEEN CHOSEN AGAIN(IF IT IS ZERO IT MEANS NO IF IT IS ONE IT MEANS YES).IF IT IS 
	}							//ZERO WE PRINT THE POST WHOSE id IS EQUAL TO THE VALUE OF random
	i=1;
	random=rand()%(sum_global);
	while(i<=5)//WE CHOOSE TO PRINT ONLY FIVE POSTS 
	{
		if(A[random]==0)
		{
			f1.print_post(random);
			A[random]=1;
			i++;
		}
		random=rand()%(sum_global);
	}
	delete [] A;
}

