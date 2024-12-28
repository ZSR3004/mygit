# MyGit: A git clone+

This project is intended to have two phases. First, the creation of a Git clone (this repo), then modifying that clone to to address a few issues with Git (I'll link that repo when I create it).

The first phase takes the core features of Git, simplifies them, then implements them. These are namely the `init`, `add`, `commit`, `branch`, and `checkout` commands.

The second phase seeks to improve on Git's design by simplifying some of these processes. The goal is to improve Git's resource usage (time/memory) and user interface while maintaining the core branch-based workflow.

## Table of Contents

- [Building this Project](#building-this-project)
- [Project Motivation](#project-motivation)
- [Scope of Clone](#scope-of-clone)
- [Work In Progress Features](#wip-features)
- [Contact Information](#contact-ziyad-rahman)

## Building this Project

To build this project, make sure you have Git installed on your machine.

From there, enter the following command:

```bash
git clone https://github.com/ZSR3004/mygit.git
```

Then, change to the directory:

```bash
cd mygit
```

And make the project using the makefile:

```bash
Make
```

Now, to use MyGit globally, you need to add the compiled program to the path somehow. I recommend making a temporary path because this is by no means a replacement for Git. This path will "expire" when you end the current terminal session. If close the terminal and want to use MyGit again, you just have to enter this command again (assuming you didn't delete the compiled files).

```bash
export PATH=$PATH:/path/to/the/compiled/program
```

After that, you can start using MyGit.

### Example

Here's a quick example of how you can use MyGit once its all setups. Further details about how to actually use it are [below](#scope-of-clone) and in the [wiki documentation](https://github.com/ZSR3004/mygit/wiki).

Initialize the repository:

```bash
mygit init
```

Then, add some files:

```bash
touch README.md
mkdir src
touch src/main.c
```

Now, you can add them to the repository:

```bash
mygit add .
```

Finally, just commit them with a message:

```bash
mygit commit -m 'first commit!'
```

## Project Motivation

I, like many others, use Git. As I became more familiar with it, I began to wonder about its inner workings, so I decided to create a clone of Git.
While I read the source code on Github and its official documentation, I was struck by how simple the implementation actually is. I also discoverd
many other version-control systems and standing issues with Git by reading through forums and articles. The next step of this project was obvious,
building upon Git's flaws (or simply trying something new).

## Scope of Clone

The clone seeks to implement only the core features of Git. Additionally, some liberties were taken with implementation, namely with how mygit handles
files and objects. Rather than detail every small change or note in this markdown file, I plan to create external documentation, likely through Github's
documentation wiki feature, to explain those details.

The wiki will reiterate a few points like the motivation of this project and how to build it, and build on this document by outlining the commands
available in MyGit. The plan is to describe the various commands and arguments they take, while providing implementation details and contextualizing
that information with how Git does it.

If you're only interested in how MyGit works (instead of the differences between MyGit and Git), then the internal documentation should be sufficient.
I've written documentation in the code with minimal references to Git, so even those unfamiliar with how Git works can understand it.

## WIP Features

Currently, this project has a working ```init``` and ```add``` command. The last thing I will implement is the ```commit``` command for this iteration
of MyGit. I'll then clean up the documentation and for the next big version of this project, I'll add a ```restore``` command that takes you back to
any previously committed version of your project.

## Contact: Ziyad Rahman

Github: [ZSR3004](github.com/ZSR3004)
