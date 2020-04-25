# Operating System (OS-6233) NYU Spring 2020 

## Part 1: Implement your own shell

### 1.1 Command Execution  
Implement basic command execution by filling in the code inside of the case ' ' blockin the runcmd function. You will want to look at the manual page for the exec(3) function by typing "man 3 exec" (Note: throughout this course, when referring to commands that one can look up in the man pages, we will typically specify the section number in parentheses -- thus, since exec is found in section 3, we will say exec(3)).
Once this is done, you should be able to use your shell to run single commands, such as

<code>
cs6233> ls
cs6233> grep cat /usr/share/dict/words 
</code>

### 1.2 I/O Redirection  
Now extend the shell to handle input and output redirection. Programs will be expecting their input on standard input and write to standard output, so you will have to open the file and then replace standard input or output with that file. As before, the parser already recognizes the '>' and '<' characters and builds a redircmd structure for you, so you just need to use the information in that redircmd to open a file and replace standard input or output with it.

<code>
cs6233> ls > a.txt
cs6233> sort -r < a.txt
</code>

### 1.3 Pipes  
The final task of part 1 is to add the ability to pipe the output of one command into the input of another. You will fill out the code for the \"|\"
case of the switch statement in runcmd to do this.

<code>
cs6233> cat /usr/share/dict/words | grep cat | sed s/cat/dog/ > doggerel.txt
cs6233> grep con < doggerel.txt
</code>

## Part 2: Add System Calls  

### 2.1 System call tracing (10 points)  
Getting start with the latest version of xv6  
`git clone https://github.com/GusSand/xv6-public.git `  
Your first task is to modify the xv6 kernel to print out a line for each system call invocation. It is enough to print the name of the system call and the return value; you don't need to print the system call arguments.

### 2.2 Date system call (15 points)  
Your second task is to add a new system call to xv6. The main point of the exercise is for you to see some of the different pieces of the system call machinery. Your new system call will get the current UTC time and return it to the user program. You may want to use the helper function, cmostime() (defined in lapic.c), to read the real time clock. date.h contains the definition of the struct rtcdate struct, which you will provide as an argument to cmostime() as a pointer.
You should create a user-level program that calls your new date system call;

### 2.3 dup2() system call (25 points)
Read Linux man pages for description on dup2 system call. xv6 doesn't implement the dup2 system call by default and you are required to implement dup2 as a part of this assignment.
The function prototype for dup2 is as below:  
`int dup2(int oldfd, int newfd);`  
The difference from the native dup call is that instead of allocating the first available file descriptor, the user can specify through newfd which
exact file descriptor should be used.

