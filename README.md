# Make
Exploring Make Build System

## Directory Structure
```shell
> tree
.
├── inc
│ ├── add
│	 └── add.h
│ ├── div
│	 └── div.h
│ ├── mul
│	 └── mul.h
│ └── sub
│	 └── sub.h
│ └── main.h
├── src
│ ├── add
│	 └── add.c
│ ├── div
│	 └── div.c
│ ├── mul
│	 └── mul.c
│ └── sub
│	 └── sub.c
│ └── main.c
├── LICENSE
├── Makefile
└── Readme.md

11 directories, 13 files
```
## Build Process

The application is compiled by the GCC compiler for the host machine with the help of the makefile -

```shell
> make

mkdir -p build/obj/src/div/
gcc -Iinc -Iinc/div -Iinc/mul -Iinc/sub -Iinc/add -c src/div/div.c -o build/obj/src/div/div.o
mkdir -p build/obj/src/mul/
gcc -Iinc -Iinc/div -Iinc/mul -Iinc/sub -Iinc/add -c src/mul/mul.c -o build/obj/src/mul/mul.o
mkdir -p build/obj/src/sub/
gcc -Iinc -Iinc/div -Iinc/mul -Iinc/sub -Iinc/add -c src/sub/sub.c -o build/obj/src/sub/sub.o
mkdir -p build/obj/src/add/
gcc -Iinc -Iinc/div -Iinc/mul -Iinc/sub -Iinc/add -c src/add/add.c -o build/obj/src/add/add.o
mkdir -p build/obj/src/
gcc -Iinc -Iinc/div -Iinc/mul -Iinc/sub -Iinc/add -c src/main.c -o build/obj/src/main.o
gcc build/obj/src/div/div.o build/obj/src/mul/mul.o build/obj/src/sub/sub.o build/obj/src/add/add.o build/obj/src/main.o -o build/main
```

To run the application -
```shell

>./build/main

-- Calculator --
Addition of 50 and 60 = 110
Subraction of 50 and 60 = -10
Multiplication of 50 and 60 = 3000
Division of 50 and 60 = 0.833333
```

To clean the build files -
```shell

>make clean

rm -r ./build
```