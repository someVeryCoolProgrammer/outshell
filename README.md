<div align="center">
    <h1>outshell</h1>
    <h3>Private. Terse. Reliable.</h3>
</div>

# Table Of Contents
- [Getting Started](#getting-started)
- [About](#about)

# About

outshell is an open-source shell that values user privacy, aims to be less verbose than powershell, and easy to use.outshell is available for both windows and unix based operating systems.

[![outshell's Version](https://img.shields.io/github/v/release/someVeryCoolProgrammer/outshell)](https://github.com/someVeryCoolProgrammer/outshell/releases/latest)

# Getting Started

First, you need to install [Make](https://gnuwin32.sourceforge.net/packages/make.htm) and [git](https://git-scm.com/install/).  

Clone outshell:
```shell
git clone https://github.com/someVeryCoolProgrammer/outshell.git
```

Switch to outshell's directory:
```shell
cd outshell
```

Make bin directory:
```shell
mkdir bin
```

Compile outshell on windows:
```shell
make w
```

Compile outshell on unix based operating systems:
```shell
make u
```

Run outshell on windows:  
```shell
./bin/outshell.exe
```

Run outshell on unix based operating systems:  
```shell
./bin/outshell
```

PLEASE MAKE SURE **NOT** TO RUN:
```shell
make <os> | ./bin/outshell(.exe)
```
It will cause the outshell to enter an infinite while loop. To escape it, please press control + c.

Thank you for using outshell ❤️
