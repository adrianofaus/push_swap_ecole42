![push_swape](https://user-images.githubusercontent.com/63206471/175189112-d98c76d9-a08c-4e4e-98b6-6837ee5bbbbb.png)

# Push_Swap

* [Introduction](#introduction)
* Notion
* [The Project](#the-project)

## Introduction
This project made me understand a bit deeper two concepts that I already knew: the redirections and the pipes. This was an introductory project.

## Skills that I have improved
* Imperative programming
* Unix logic

## The Project
In order to succeed in doing this project I had to master the following:
* Manage forks and child proccesses
* Manage pipes
* Manage file descriptors
* How to execute programs inside another program 

### What are my thoughts about the project?
Pipex is a important step in the journey to become a great software engineer. The biggest challenge that I had during this project was to learn how child processes work and how to redirect inputs and outputs. If you don't manage pipes and file descriptors correctly the result is always weird and difficult do debug. 
What I loved about pipex is that I could learn how to automatize the execution of a program inside my code, this was like an inception for me.

### Workflow


### How to run it?

```
1 - make or make bonus
2 - Example => ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
It should behave like:
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

You can also run with here_doc
Example =>  ./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file
IT should behave like:
cmd << LIMITER | cmd1 >> file
```
