#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

extern string texts[50];//GLOBAL TABLE THAT HOLDS THE TEXTS THAT LATER WILL BE ASSIGNED TO THE PART text OF THE CLASS post 
extern int sum_global;//GLOBAL VARIABLE THAT IS USED FOR THE id OF THE POSTS THAT IS UNIQUE FOR EACH POST 

class date{//CLASS THAT IS USED FOR THE REPRESENTATION OF THE DATE
	private:
		int day;
		int month;
		int year;
	public:
		void set();//FUNCTION THAT INITIALIZES THE DATE 
		void print();//FUNCTION THAT PRINTS THE DATE 	
};

class post{//CLASS THAT IS USED FOR THE POSTS
	private:
    		int id;
    		string tittle;
    		string creator;
    		date creation_date;
    		string text;
	public:
		post(const string s1,const string s2);//CONSTRUCTOR OF THE POST THAT TAKES AS ARGUMENTS THE TITLE OF THE POST AND THE CREATOR OF THE POST 
		~post();//DESTRUCTOR OF THE POST    
		void print();//FUNCTION THAT PRINTS THE POST
		int get_id();//FUNCTION THAT RETURNS THE id OF THE POST
};

class thread{//CLASS THAT IS USED FOR THE THREADS
	private:
	    	string theme;
    		string creator;
    		date creation_date;
    		int sum_post;
    		post **po;//POINTS TO A TABLE THAT CONTAINS ADDRESSES WHERE EACH ADDRESS POINTS TO A STRUCTURE POST
	public:
		thread(const string s1,const string s2,int sum);//CONSTRUCTOR OF THE THREAD THAT TAKES AS ARGUMENTS THE THEME THE NAME OF THE CREATOR AS WELL AS THE NUMBER OF POSTS THAT WILL BE CONTAINED IN THIS THREAD 
		~thread();//DESTRUCTOR OF THE THREAD
		void print();//FUNCTION THAT PRINTS THE THREAD
		void print_only_theme_of_thread();//FUNCTION THAT PRINTS THE THEME OF THE THREAD  
		string get_theme();//FUNCTION THAT RETURNS THE THEME OF THE THREAD  
		int search_id(int i);//FUNCTION THAT SEARCHES THE ID OF THE POST AND IF IT IS FOUND PRINTS THE SPECIFIC POST
};

class forum{//CLASS THAT IS USED FOR THE FORUM
	private:
    	string tittle;
    	int sum_thread;
    	thread **th;//POINTS TO A TABLE THAT CONTAINS ADDRESSES WHERE EACH ADDRESS POINTS TO A STRUCTURE THREAD
	public:
		forum(const string name,int sum);//CONSTRUCTOR OF THE FORUM THAT TAKES AS ARGUMENTS THE TITLE OF THE FORUM AND THE NUMBER OF THREADS OF THE FORUM
		~forum();//DESTRUCTOR OF THE FORUM
		void print();//FUNCTION THAT PRINTS ONLY THE NAMES OF THE THREADS THAT BELONG TO THIS FORUM
		void print_thread(const string name);//FUNCTION THAT TAKES THE NAME OF A THREAD AND TRIES TO FIND IT IN THE FORUM AND IF IT IS FOUND PRINTS THIS THREAD 
		void print_post(int i);//FUNCTION THAT TAKES A NUMBER AND TRIES TO SEE IF THERE IS AN id OF A POST THAT IS EQUAL TO THIS NUMBER TO PRINT THE POST OF THIS FORUM
};

