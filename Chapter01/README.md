# Chapter 1

### Jesús Urtasun Elizari - Uiverisity of Milan - 2019/20

## Exercise 1 - Get used to Linux

Find the content of the course:

  [https://github.com/JesusUrtasun/CppCourse]( https://github.com/JesusUrtasun/CppCourse)

- Navigate on the menu `Applications` and open the text editor. 

- All commands for exploration of a file and manipulation of files can be done directly from the terminal.

## Exercise 2 - Terminal and bash

For programming we will use the Linux command window or terminal, for which we use the language `bash`.

- Create and open the `Terminal`.

- Try launching the bash comand that prints the text directly on screen.

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

2. Fro watching all files in the present folder:
  ```bash
  ~$ ls
  ```
  (list). If instead we use the command `ls -l` (that means `ls` with extra option `-l`)
  more details will be shown, as owner, persmissions, file dimension, etc.

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
  ~$ cd <cartella>
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
  /home/<username>/cpp_course
    |- Chapter01
          |- data.txt # leave it empty
```

## Exercise 4 - Copy and move files

Per copiare e spostare files utilizziamo i seguenti comandi:
- Per copiare:
  ```bash
  ~$ cp <file_da_copiare> <directory_in_cui_copiare>
  ```
  (copy). Se vogliamo copiare una cartella basta aggiungere l'opzione recursive, i.e. `cp -r`.
- Se vogliamo muovere un file oppure rinominare un file, usiamo:
  ```bash
  ~$ mv <file> <nuovo_nome_file>
  ```
 Ricordare che le directories possono essere rappresentate da notazione relativa rispetto
 alla cartella attuale sia in notazione assoluta.

Provate a copiare il file `data.txt` creato nell'esercizio precedente dentro la
cartella `Lezione1` e poi cambiate il suo nome da `data.txt` a `README.md`.

## Esercizio 5 - Editor di testo

Esistono innumerevoli programmi per editare files su Linux, che capiscono il tipo
di contenuto in base al suffisso del file. Per esempio un file con suffisso `.txt` è
considerato come puro testo, invece un file con `.cc` è un file di programmazione in C++, quindi si attiveranno dei colori per la sintassi utilizzata.

Sono disponibili su tutte le macchine i seguenti editor di testo:
- `gedit`: editor generale, user-friendly, molto facile e intuitivo da usare.
- `vim`: editor molto flessibile e con supporto a innumerevoli plug-ins. Richiede tempo
  per imparare ad utilizzare in modo proficuo.
- `emacs`: editor molto flessibile, contestualmente simile a vim, richiede però tempo
  per imparare ad utilizzare in modo proficuo.

Come esercizio proviamo a creare un file usando gedit:
1. aprire il terminale, scegliere una cartella dentro la propria home e eseguire:
  ```bash
  ~$ gedit file1.txt
  ```
  scrivere un contenuto qualunque, salvare il file e chiudere `gedit`.

2. controllare il contenuto di questo nuovo file con `cat`.

3. lanciare nuovamente `gedit` ma in modalità *background*, cioè il terminale
  resterà libero per ricevere nuovi comandi mentre `gedit` è attivo.
  ```bash
  ~$ gedit file1.txt &
  ```

4. Cancellare `file1.txt`.

A questo punto proviamo a creare un file per codice in C++:
1. aprire il terminale e eseguire
  ```bash
  ~$ gedit file.cc
  ```

2. scrivere la seguente riga
  ```c++
  #include <iostream>
  ```
  noterete che si attiveranno dei colori diversi per ogni parola: `gedit` ha
  riconosciuto che il vostro file contiene sintassi del C++.

3. Cancellare `file.cc`.

Con la tastiera italiana i seguenti simboli utili per programmazione sono:
```
{ = Alt Gr + Shift + è
} = Alt Gr + Shift + +
~ = Alt Gr + ì
```

## Exercise 6 - Clone with git

Git is a very useful instrument when programming. It allows for saving files on a remote server,
keep the history of modifications and work in collaborative mode. For instance, [https://github.com](https://github.com)
is quite popular for open-source projectr at big scale.

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

Every week the new chapter will be published here in the `git` repository.
For obtaining the updated versions is enought to perform a `pull`, i.e.:
```bash
~$ cd CppCourse
~$ git pull
```

At this point you can try opening the documents just cloned with `gedit` or `code`, and for PDFs use `evince`.

## Esercizio 7 - Accesso remoto e copia dei file

Siccome programmare richiede allenamento e studio, vi capiterà di lavorare
su diverse macchine, sia in laboratorio che sul vostro computer personale. Il
metodo che raccomandiamo per salvare il vostro lavoro consiste in utilizzare una semplice *chiavetta USB* in cui saranno copiati tali files.

Detto ciò, esistono metodi per la copia di files da remoto utilizzando la rete
usando `ssh` e `scp`. Da notare però che per motivi di sicurezza le connessioni
dirette da remoto non sono sempre possibili dovuti a regole firewall oppure la
mancanza di software opportuno per tali operazioni.

- Per accedere da remoto ad un computer raggiungibile sulla rete usiamo il comando:
  ```bash
  ~$ ssh <username>@<indirizzo_computer>
  ```
  dove per `<indirizzo_computer>` intendiamo l'IP oppure il suo dominio da rete.
  Questo metodo vi permetterà di entrare nella macchina remota e lavorare.
  Eseguendo il comando `ssh -X <username>@<indirizzo_computer>` sarete capaci
  di inoltrare l'output delle applicazioni grafiche da remoto.

- Per copiare files da remoto utilizziamo il comando `scp`:
  ```bash
  ~$ scp <username>@<indirizzo_computer>:<file> <file_destinazione>
  ```
  Questo comando funziona in modo analogo a `cp`, quindi si possono copiare
  intere cartelle aggiungendo l'opzione `cp -r`.

Loggarsi sulle macchine del laboratorio di calcolo del dipartimento di fisica usando ssh e copiare i propri files.

1. Loggarsi con `ssh <username>@tolab.fisica.unimi.it`.

2. Verificare il contenuto della propria home directory.

3. Copiare alcuni files e folders tra la vostra macchina e tolab usando `scp` e `scp -r` rispettivamente.
