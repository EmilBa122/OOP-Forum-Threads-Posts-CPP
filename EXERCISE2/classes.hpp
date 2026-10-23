#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

extern string texts[50];//GLOBAL TABLE THAT KEEPS THE TEXTS THAT LATER WILL BE ASSIGNED TO THE PART text OF THE CLASS post 
extern int sum_global;//GLOBAL VARIABLE THAT IS USED FOR THE id OF THE POSTS WHICH IS UNIQUE FOR EACH POST 

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
		post();//THE SECOND CONSTRUCTOR OF THE POST IS USED BECAUSE WE HAVE IN THE struct list_node post content SO WE JUST WANT TO CREATE A post
		~post();//DESTRUCTOR OF THE POST    
		void print();//FUNCTION THAT PRINTS THE POST
		int get_id();//FUNCTION THAT RETURNS THE id OF THE POST
		string get_creator();//RETURNS THE creator OF THE SPECIFIC post
};

class thread{//CLASS THAT IS USED FOR THE THREADS
	private:
    	string theme;
    	string creator;
    	date creation_date;
    	int sum_post;
    	post **po;//POINTS TO A TABLE THAT CONTAINS ADDRESSES WHERE EACH ADDRESS POINTS TO A POST STRUCTURE
	public:
		thread(const string s1,const string s2,int sum);//CONSTRUCTOR OF THE THREAD THAT TAKES AS ARGUMENTS THE THEME THE NAME OF THE CREATOR AS WELL AS THE NUMBER OF POSTS THAT WILL BE CONTAINED IN THIS THREAD
		~thread();//DESTRUCTOR OF THE THREAD
		void print();//FUNCTION THAT PRINTS THE THREAD
		void print_only_theme_of_thread();//FUNCTION THAT PRINTS THE THEME OF THE THREAD  
		string get_theme();//FUNCTION THAT RETURNS THE THEME OF THE THREAD  
		int search_id(int i);//FUNCTION THAT SEARCHES THE ID OF THE POST AND IF IT IS FOUND PRINTS THE SPECIFIC POST
		post **get_post();//RETURNS THE ADDRESS WHICH POINTS TO A TABLE THAT CONTAINS ADDRESSES WHERE EACH ADDRESS POINTS TO A POST STRUCTURE
		int get_sum_post();//RETURNS THE NUMBER OF POSTS THAT THE THREAD HAS
};

class forum{//CLASS THAT IS USED FOR THE FORUM
	private:
    	string tittle;
    	int sum_thread;
    	thread **th;//POINTS TO A TABLE THAT CONTAINS ADDRESSES WHERE EACH ADDRESS POINTS TO A THREAD STRUCTURE
	public:
		forum(const string name,int sum);//CONSTRUCTOR OF THE FORUM THAT TAKES AS ARGUMENTS THE TITLE OF THE FORUM AND THE NUMBER OF THREADS OF THE FORUM
		~forum();//DESTRUCTOR OF THE FORUM
		void print();//FUNCTION THAT PRINTS ONLY THE NAMES OF THE THREADS THAT BELONG TO THIS FORUM
		void print_thread(const string name);//FUNCTION THAT TAKES THE NAME OF A THREAD AND TRIES TO FIND IT IN THE FORUM AND IF IT IS FOUND PRINTS THIS THREAD
		void print_post(int i);//FUNCTION THAT TAKES A NUMBER AND TRIES TO SEE IF THERE IS AN id OF A POST THAT IS EQUAL TO THIS NUMBER IN ORDER TO PRINT THE POST OF THIS FORUM
		thread *get_thread(int i);//RETURNS THE ADDRESS WHICH POINTS TO A THREAD STRUCTURE DEPENDING ON THE VALUE OF i
		int get_sum_thread();//RETURNS THE NUMBER OF THREADS THAT THIS FORUM HAS 
};

struct list_node {//THE PARTS OF THE LIST
    post  content;
    struct list_node *next;
};

class list{//CLASS THAT IS USED FOR THE LIST 
	private:
		struct list_node *list_head;//EACH LIST HAS ITS HEAD 
	public:
		list();//CONSTRUCTOR OF THE LIST THAT SIMPLY ASSIGNS TO THE HEAD POINTER THE NULL
		~list();//DESTRUCTOR OF THE LIST
		int list_empty();//WE SEE IF THE LIST IS EMPTY
		int add_node_to_list(post *item);//FUNCTION THAT INSERTS A NODE IN THE LIST
		int list_print();//FUNCTION THAT PRINTS THE LIST
		int list_destroy();//FUNCTION THAT DESTROYS THE LIST		
};

struct tree_node{//THE PARTS OF THE TREE
	list li;
	string creator;
	struct tree_node *left;
	struct tree_node *right;
};

class tree{//CLASS THAT IS USED FOR THE TREE
	private:
		struct tree_node *root;//EACH TREE HAS ITS ROOT 
	public:
		tree();//CONSTRUCTOR OF THE TREE THAT SIMPLY ASSIGNS TO THE POINTER OF ITS ROOT THE NULL
		~tree();//DESTRUCTOR OF THE TREE
		int tree_empty();//WE SEE IF THE TREE IS EMPTY
		struct tree_node *new_node(string info);//FUNCTION THAT CREATES A NEW NODE	
		void tree_destroy(tree_node **t);//FUNCTION THAT DESTROYS THE TREE
		struct tree_node *set();//FUNCTION THAT ASSIGNS TO A POINTER THE ADDRESS OF THE TREE
		void inorder_print(struct tree_node *ptr);//FUNCTION THAT PRINTS THE NODES OF THE TREE FIRST BY DEPTH AND FROM THE LEFT TO THE RIGHT
		void tree_insert_post(post *item);//WE INSERT INTO THE TREE A post STRUCTURE THAT THE POINTER item POINTS TO SO THAT THE TREE IS SORTED 
		void create_tree_from_thread(thread *th,post **p1,int sum);//WE CREATE A TREE FROM EACH THREAD OF THE FORUM 
		void print_sorted(thread *th,post **po,int sum);//WE PRINT THE TREE SORTED IN ASCENDING ORDER 
};



