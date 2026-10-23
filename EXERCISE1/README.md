# OOP Forum Threads Posts CPP

## Usage Instructions of the program:

1. Open Linux terminal
2. Type `unzip askisi1.zip`
3. TYPE `make`
4. TYPE `./main`

## Program design idea:

**WE HAVE THE GLOBAL TABLE texts WHERE IT HOLDS THE TEXTS THAT LATER WILL BE
ASSIGNED TO THE PART text OF THE CLASS post WHICH CONTAINS IN THE POSITION i THE
TEXT texti THAT IS IN THE POSITION 0 IT HAS THE TEXT text0 IN THE POSITION 1 THE TEXT
text1…….(I use the method to_string((i))AND WE HAVE THE GLOBAL VARIABLE sum_global
THAT IS USED FOR THE id OF THE posts.**

**AS WE CREATE A forum WITH A NAME,WE SPECIFY THAT THIS forum WILL HAVE 4 threads
WHERE THIS NUMBER WILL BE ASSIGNED TO THE sum_thread OF THE CLASS forum ALSO WE
HAVE IN THE private PART OF THE forum \*\*th THAT POINTS TO A TABLE THAT CONTAINS
ADDRESSES WHERE EACH ADDRESS POINTS TO A STRUCTURE thread.** In the public part of the
forum we have the function print() that prints the themes of the threads that belong to this
forum,we have the print_thread that takes the name of a thread and tries to find it in the
forum and if it is found prints this thread.The print_post takes a number and tries to see if
there will be an id of a post that is equal to this number to print the post of this forum.

**AS WE CREATE A thread WITH A NAME AND THE NAME OF THE CREATOR WE SPECIFY THAT
THIS thread WILL HAVE 4 post WHERE THIS NUMBER WILL BE ASSIGNED TO THE sum_post
OF THE CLASS thread,WE ALSO HAVE IN THE private PART OF THE thread \*\*po THAT POINTS
TO A TABLE THAT CONTAINS ADDRESSES WHERE EACH ADDRESS POINTS TO A STRUCTURE
post.** In the public part of the thread we have the function print() that prints the thread,we
have the function print_only_theme_of_thread() that prints the theme of the thread and the
get_theme that returns the theme of the thread,the search_id searches the id of the post in
this thread and if it is found prints the specific post.

**EACH TIME THAT A thread OR A post IS CREATED WE CHOOSE RANDOMLY ONE OF THE
FOUR creators.**

As we create a post we choose randomly a text from the table texts and we assign it to the
text of the class post,also in the class post to the id we assign the value of the variable
sum_global.In the public part of the post we have the function print() that prints the post and
the get_id() that returns the id of the post.

**THE CLASS date IS SPECIFIED BY THE day,month AND year AND IN THE public PART WE HAVE
THE FUNCTION set() THAT INITIALIZES THE CREATION DATE AND THE print() THAT PRINTS
THE CREATION DATE OF THE threads AND OF THE posts.**

**AT THE END OF THE main I CHOOSE TO PRINT RANDOMLY 5 post FROM ALL THE threads OF THIS forum.**
