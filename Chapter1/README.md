# Chapter 1 - Basics of Linux / UNIX operative systems

- Introduction to Linux operative systems, terminal and bash.
- Programing languages and performance comparison. Text editors.
- First steps with C++. Hello world.

## Setting up C++

For some programming languages, like Python, R, Matlab - the so-called *interpreted* ones, there is just one program you need to open to write your code and then run it. For others, like C++, you will need one program to write your code, and then another to *compile* it.

A *compiler* is a program which takes the text file we have written and turns it into something we can run, that is, an *executable*. Compilers do not look like normal programs, with windows and graphics. Instead they run using the *command line*, or *terminal*.

When programming, we are generally going to have two windows open at the same time:

- The text editor (for this code we are using as an example [VSCode](https://code.visualstudio.com/))
- The command line, or terminal, where a C++ compiler has already been installed and set up

*Integrated Development Environments* (IDEs) also exist, which often combine a text editor and compiler in one useful program: XCode, Code::Blocks and - to a lesser degree - Visual Studio Code are examples. In scientific computing, we typically develop on different machines to those we end up running on, so in this class we will keep the two ideas separate.

### Getting C++ set up on the college computers running Windows
1. Open a browser and navigate to Imperial College [Software Hub](https://softwarehub.imperial.ac.uk/?labs)
2. Search for `Visual Studio Code` in the search box
3. Visual Studio Code is one of the few search results. Just click `launch`  - done!
4. Clear the search box and then search for `mingw` in the search box
5. Among the small set of search results that pop up, launch `MinGW 1.0` (the newer version plays badly with Armadillo).
6. You are all set!

## Terminal and bash

For the purpose of this code we will use the Linux command window or terminal, which runs with the language `bash`.
For more information check: [this link](https://en.wikipedia.org/wiki/Bash_(Unix_shell))

- Open the `Terminal`.

- Try launching some bash basic comands such as `~$ echo`, that prints the text directly on screen.

  ```bash
  ~$ echo "Hello World!"
  ```
  followed by the key `Enter`.

- Note: all bash commands must be followed by the key `Enter` to be executed.

## The file system

Data contained in the disc of the system is structured in folders, or *directories*. 
In general, in Linux / UNIX systems, the base directory is called **root**, and it typically comes with the symbol `/`.
Inside this folder we can find other folders that contain programs, data and configuration systems that allow the computer to work, e.g. `/usr/`, `/bin/`, `/home/`, etc.
All useres are able to write and read files that are found inside the proper **home** directory. For instance, the user `james` has as home directory `/home/james`. 

We propose now a list of commands / exercises which are useful for navigating and creating files.
For all comands the use of the `man` command is allowed, displaying the manual and usage information, and also the option `<command> --help`.

1. For watching the name of the directory in which we are, use the command:

  ```bash
  ~$ pwd
  ```
  (print working directory)

2. For watching all files in the present folder:

  ```bash
  ~$ ls
  ```
  (list). If instead we use the command `ls -l` (that means `ls` with extra option `-l`)
  more details will be shown, as owner, permissions, file dimension, etc.

3. For creating a new directory:

  ```bash
  ~$ mkdir <new_diretory_name>
  ```
  (make directory).

4. For entering a new directory:

  ```bash
  ~$ cd <directory>
  ```
  (change directory). Also for going back to the previous directory:
  ```bash
  ~$ cd ..
  ```
  if we use `cd` without a specific destination it will take us automatically to our home directory. Instead `cd -` will take us to the folder that we visited previously.

5. For creating an empty file:

  ```bash
  ~$ touch <file_name>
  ```

6. For watching the content of a file without open it:

  ```bash
  ~$ less <file>
  ~$ more <file>
  ```
  for closing the intergace and going back to the terminal, just press `q`. 
  As an exercise try to create the following folder structure:
  ```bash
    /home/<username>/CppCourse
      |- Chapter1
          |- new_dir
              |- file1.txt
              |- file2.txt 
  ```

7. For deleting a file or directory:

  ```bash
  ~$ rm <file>
  ~$ rm -r <directory>
  ```
  (remove). For deleting files and empty directories, the `rm` command is enough, whereas for not empty directories it needs to be called with the option `-r` (recursive).
  As an example, it can also be used with `*` (everything), i.e. `rm -rf *` means delete all files present in the current directory.

8. For copying a file to a specific path:

  ```bash
  ~$ cp <file_to_copy> <destination_path>
  ```
  (copy). If we want to copy a folder is enough to add the option, i.e. `cp -r`.
  For moving a file, and also to rename it:
  ```bash
  ~$ mv <file> <destination_path/new_name_file>
  ~$ mv <file> <new_name_file>
  ```
  As an exercise try to create the following folder structure:
  ```bash
    /home/<username>/CppCourse
      |- Chapter1
          |- new_dir
              |- file1.txt
              |- new_dir2
                  |- new_file1.txt
                  |- new_file2.txt 
  ```
  Try to copy the file `file1.txt` created in the previous exercise inside `new_dir2`, and then rename it. Move `file2.txt` directly changing its name in the new destination.

## Text editor

There are plenty of programs to edit files in Linux. As an example, with the suffix `.txt` a file is interpreted as pure text file, otherwise with `.cpp` it is a program file in C++,
so colors and messaged concering indentation will appear. We will review these concepts in detail in the following sessions.

In all machines the following text editors are available:
- `Visual Studio Code`: Default editor recommended for this course. More information at (https://code.visualstudio.com/)
- `Vim`: Very flexible editor with plenty of supports. Time is needed in order to learn how use it properly.
- `Emacs`: Very flexible editor, similar to vim. Time is needed in order to learn how to use it properly.

As an exercise try to open `Visual Studio Code` and follow the instructions:

1. Open the terminal, choose a folder inside the home directory and write:

  ```bash
  ~$ code file1.txt
  ```
  write any content, save and close the editor.

2. Check the content of this file with `cat`.

3. Open `VSCode` in mode *background*, such that the terminal remains free for receiving commands while `VSCode` remains active.
  ```bash
  ~$ code file1.txt &
  ```

4. Delete `file1.txt`.

At this point you can try to create a file for C++ code:

1. Open the terminal and write

  ```bash
  ~$ code file1.cpp
  ```

2. Write the folloing line:

  ```c++
  #include <iostream>
  ```
  you will notice that colors will activate for each word: `VSCode` has recognized the file as contianing syntax C++.

3. Delete `file1.cpp`.

You are now ready to dowload the content of the course and follow the first exercises.

## Clone with git

Git is a very useful instrument when programming. Even though we will not cover this topic in detail, at least mention that it allows for saving files on a remote server, keep the history of modifications and work in collaborative mode. For instance, [https://github.com](https://github.com) is quite popular for open-source projects at big scale.
Going through the details of `git` in this tutorial is beyond need. We will use it only as a place to save your codes and access the solutions in an efficient way.

As an example you can try downloading this guide and all material from the course writing:
```bash
~$ git clone git@github.com:ImperialCollegeLondon/RCDS-intro-cpp.git
```
and then going through the folder `Chapter1` with
```bash
~$ cd Chapter1
```

Every week a new chapter will be published here in the `git` repository.
For obtaining the updated versions it will be enought to perform a `pull`, i.e.:
```bash
~$ cd RCDS-intro-cpp
~$ git pull
```

## Hello World in C++

* Open up VSCode and write the following syntax:
```c++
#include <iostream>
using namespace std;

int main() {

  // Print on screen
  cout << "Hello world!" << endl;
  return 0;

}
```

* Save the file as `helloworld.cpp`. As said, `VSCode` should recognice the C++ syntax and print colours accordingly.

* Compile by going to the command line and typing
```bash
c++ helloworld.cpp -o hello
```
where `c++` - or `g++` - is the compiler for C++, `-o` the option to determine the name of output, or *executable* that will be created by `c++` / `g++`.

* Then run the program. On Windows this is done with
```bash
hello
```
and on Mac/Linux, with
```bash
./hello
```