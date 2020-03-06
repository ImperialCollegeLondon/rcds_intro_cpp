# Chapter 1

### Jesús Urtasun Elizari - University of Milan - 2019/20

## Exercise 1 - Get used to Linux

Find the content of the course:

  [https://github.com/JesusUrtasun/CppCourse](https://github.com/JesusUrtasun/CppCourse)

- Navigate on the menu `Applications` and open the text editor. 

- All commands for exploration and manipulation of files can be done directly from the terminal.

## Exercise 2 - Terminal and bash

For programming we will use the Linux command window or terminal, for which we use the language `bash`.

- Create and open the `Terminal`.

- Try launching some bash basic comands such as `~$ echo`, that prints the text directly on screen.

  - Write
    ```bash
    ~$ echo "Hello World!"
    ```
    followed by the key `Enter`.

    *Note: all bash commands must be followed by the key `Enter` to be executed.

- For knowing a bit more about the commands use
  ```bash
  ~$ help
  ```

- For knowing the details of a given command you can use the command `man` that opens the
  page of the manual of all details of the command, e.g.:
  ```bash
  ~$ man echo
  ```
  for closing the manual simply press the key `q` on the keyboard.

- You can use the arrow up and down to recover the last used commands.

- For more information check: [this link](https://it.wikipedia.org/wiki/Bash)

*Note: there exist other languages for command but bash is the most popular one.*

## Exercise 3 - The file system

Data contained in the disc of the system are structured in folders (*directories*).
In general, in the UNIX system the base directory, called **root**, comes with the symbol `/`.
Inside this folder we can find other folders that contain programs, data and configuration 
systems that allow the computer to work, e.g. `/usr/`, `/bin/`, `/home/`, ecc.

 All useres have are able to write and read files that are found inside the proper **home** directory.
 For instance, the user `james` has as home directory `/home/james`. 

We propose now a list of commands/exercises useful for navigating and creating files.
For all comands the use of the command `man` is allowed, and also the option `<command> --help`.

1. For watching the name of the directory in which we are, we use the command:
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

3. For creating a folder:
  ```bash
  ~$ mkdir <nome_nuova_cartella>
  ```
  (make directory). If we add the option `mkdir -p` all parent directories will be created.

4. For creating an empty file:
  ```bash
  ~$ touch <nome_file>
  ```

5. For deleting a file or directory:
  ```bash
  ~$ rm <file>
  # Also for not-empty directories:
  ~$ rm -r <directory>
  ```
  where the remove command is called just with the option `-r` (recursive).
  Also use `*`, i.e. `rm -rf *` means delete all files present in the current directory.

6. For going to a new directory:
  ```bash
  ~$ cd <directory>
  ```
  (change directory) also for going back to the previous directory:
  ```bash
  ~$ cd ..
  ```
  if we use `cd` this will take us automatically to our home directory. Instead `cd -` will take
  us to the folder that we visited previously.

7. For watching the content of a file without open it:
  ```bash
  ~$ less <file>
  ~$ more <file>
  ~$ cat <file>
  ```
  the command `cat` is used to concatenate files, e.g. `cat file1 file2 > file3`.

As an exercise create the following folder structure:
```bash
  /home/<username>/CppCourse
    |- Chapter01
          |- data.txt # leave it empty
```

## Exercise 4 - Copy and move files

For copying and moving files we will use the following commands:
- For copying:
  ```bash
  ~$ cp <file_to_copy> <folder_where_to_copy>
  ```
  (copy). If we want to copy a folder is enough to add the option, i.e. `cp -r`.
- If instead of moving a file we want to just rename it we can use:
  ```bash
  ~$ mv <file> <new_name_file>
  ```

Try to copy the dile `data.txt` created in the previous exercise inside the folder
`Chapter01` and then change its name from `data.txt` to `README.md`.

## Exercise 5 - Text editor

There are plenty of programs to edit files in Linux. As an example, with the suffix `.txt` a file is interpreted as pure text file,
otherwise with `.cc` it is a program file in C++, so colors and messaged concering indentation will appear.
We will review these concepts in detail in the following sessions.

In all machines the following text editors are available:
- `gedit`: General editor, user-friendly, easy and intuitive.
- `vim`: Very flexible editor with plenty of supports. Time is needed in order to learn how use it properly.
- `emacs`: Very flexible editor, similar to vim. Time is needed in order to learn how to use it properly.
- `visual studio code`: Not installed. The one I use.  I dont like either of those mentioned above :/ More information at (https://code.visualstudio.com/)

As an exercise try to create a folder using gedit:
1. Open the terminal, choose a folder inside the home directory and write:
  ```bash
  ~$ gedit file1.txt
  ```
  write any content, save and close `gedit`.

2. Check the content of this file with `cat`.

3. Open `gedit` in mode *background*, such that the terminal remains free for receiving commands while `gedit` remains active.
  ```bash
  ~$ gedit file1.txt &
  ```

4. Delete `file1.txt`.

At this point you can try to create a file for C++ code:
1. Open the terminal and write
  ```bash
  ~$ gedit file.cc
  ```

2. Write the folloing line:
  ```c++
  #include <iostream>
  ```
  you will notice that colors will activate for each word: `gedit` has
  recognized the file as contianing syntax C++.

3. Delete `file.cc`.

## Exercise 6 - Clone with git

Git is a very useful instrument when programming. Even though we will not cover this topic in detail, at least mention that it allows for saving files on a remote server, keep the history of modifications and work in collaborative mode. For instance, [https://github.com](https://github.com)
is quite popular for open-source project at big scale.

Going through the details of `git` in this tutorial is beyond need.
We will use only as a place to save your codes and acces to the solutions in an efficient way.

As an example you can try downloading this guide and all material from the course writing:
```bash
~$ git clone https://github.com/JesusUrtasun/CppCourse.git
```
and then going through the folder `Chapter01` with
```bash
~$ cd Chapter01
```

Every week a new chapter will be published here in the `git` repository.
For obtaining the updated versions it will be enought to perform a `pull`, i.e.:
```bash
~$ cd CppCourse
~$ git pull
```

At this point you can try opening the documents just cloned with `gedit` or `code`, and for PDFs use `evince`.

## Exercise 7 - Remote access and copy files

There are ways for copying files remotely using `ssh` e `scp`. For security reasons remote connections are not always possible due to firewall rules or the lack of proper software for such operations.

- For accessing remotely to a computer online we use:
  ```bash
  ~$ ssh <username>@<address_computer>
  ```
  where for `<address_computer>` we understand the IP or its online domain.

- For copying files remotely we use `scp`:
  ```bash
  ~$ scp <username>@<address_computer>:<file> <file_destination>
  ```
  This command works in an analogous way to `cp`, so there can be copied instead folders using also `cp -r`.

Log in computers of the lab of the department of physics ussing ssh and copy files.

1. Log in with `ssh <username>@tolab.fisica.unimi.it`.

2. Verify the content of the proper home directory.

3. Copy some files and folders between our machine and tolab using `scp` e `scp -r` respectively.
