## Usage Instructions for the program:

1. Open Linux terminal
2. Type `unzip askisi2.zip`
3. TYPE `make`
4. TYPE `./main`

## Program design idea:

We have the global table texts where it keeps the texts that later will be assigned to the part text of the class post which contains in the position i the text texti that is in the position 0 it has the text text0 in the position 1 the text text1……..(I use the method to_string(i))and we have the global variable sum_global that is used for the id of the post.

As we create a forum with a name, we specify that this forum will have 2 threads where this number will be assigned to the sum_thread of the class forum also we have in the private part of the forum \*\*th that points to a table that contains addresses where each address points to a thread structure.

As we create a thread with a name and the name of the creator we specify that this thread will have 4 post where this number will be assigned to the sum_post of the class thread,we also have in the private part of the thread \*\*po that points to a table that contains addresses where each address points to a post structure.

**EACH TIME THAT A thread OR A post IS CREATED WE CHOOSE RANDOMLY 1 OF THE 4 creators.**

As a post is created we choose randomly a text from the table texts and we assign it to the text of the class post,also in the class post to the id we assign the value of the variable sum_global.In the public part of the post we have the function print() that prints the post.

The class date is specified by the day,month and year and in the public part we have the function set() that initializes the creation date and the print() that prints the creation date of the threads and of the posts.

**FOR THE REPRESENTATION OF A NODE OF THE LIST WE HAVE A struct list_node THAT CONSISTS OF THE PARTS post content AND A POINTER THAT POINTS TO THE NEXT NODE OF THE LIST.FOR THE REPRESENTATION OF THE LIST WE HAVE THE class list THAT CONTAINS A POINTER WHICH IS THE HEAD OF THE LIST (list_head) AND POINTS TO THE FIRST NODE OF THE LIST.**

**FOR THE REPRESENTATION OF A NODE OF THE TREE WE HAVE THE struct tree_node THAT CONSISTS OF THE NAME OF THE creator,A LIST (list li) THAT CONTAINS ALL THE post OF THE SPECIFIC creator AND OF POINTERS THAT POINT TO THE NEXT NODES OF THE TREE.FOR THE REPRESENTATION OF THE TREE WE HAVE THE class tree THAT CONTAINS A POINTER WHICH IS THE ROOT OF THE TREE (root) AND POINTS TO THE FIRST NODE OF THE TREE.**

**THE SECOND constructor OF THE post IS USED BECAUSE WE HAVE IN THE struct list_node post content SO WE JUST WANT TO CREATE A post,CONSEQUENTLY DURING THE EXECUTION OF THE PROGRAM WE WILL HAVE TWO MESSAGES FOR THE DESTRUCTION OF THE ‘’SAME’’ post,THE ONE REFERS TO THE post THAT WAS CREATED IN THE forum AND THE OTHER THAT WAS CREATED IN THE LIST BUT BY ASSIGNING THE VALUE OF THE forum’s post.**

Before we create a tree based on a thread we must take the address which points to a thread structure,the address which points to a table that contains addresses where each address points to a post structure of the specific thread whose address we have,as well as the number of post that the specific thread has all these are implemented with the following corresponding functions thread \*get_thread(int i),post \*\*get_post(),int get_sum_post().

**THE FUNCTION print_sorted CALLS THE FUNCTION create_tree_from_thread WHERE IT PASSES TO IT AS ARGUMENTS ALL THESE THAT WE SAID IN THE PREVIOUS PARAGRAPH.THE FUNCTION create_tree_from_thread FOR EACH post OF THE SPECIFIC thread CALLS THE FUNCTION tree_insert_post PASSING AS ARGUMENT THE ADDRESS OF A post EACH TIME.THE FUNCTION tree_insert_post IS RESPONSIBLE FOR INSERTING INTO THE TREE A post STRUCTURE IN THE CORRECT POSITION DEPENDING ON THE NAME OF THE creator OF THE post.WHEN WE ARE READY TO INSERT A post IN THE APPROPRIATE POSITION IN THE TREE BASED ON THE NAME OF THE creator WE CALL THE FUNCTION add_node_to_list PASSING AS ARGUMENT THE ADDRESS OF THE post AND WE INSERT THE SPECIFIC post IN THE LIST OF THE SPECIFIC creator.WHEN ALL THESE ARE FINISHED WE CALL THE FUNCTION inorder_print WHICH HAS AS A RESULT TO PRINT THE TREE IN ASCENDING ORDER BASED ON THE NAMES OF THE creator.**

**ONLY THE ABILITY TO EXTEND THE TREE WITH THE CONTENTS OF ANOTHER TREE HAS NOT BEEN IMPLEMENTED.**
