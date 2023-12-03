# Make
Exploring Make Build System

## Directory Structure
```shell
> tree
.
├── LICENSE
├── README.md
├── app
│   ├── Makefile
│   ├── lib
│   │   ├── calculator.h
│   │   └── libCalculator.a
│   ├── main.c
│   └── main.h
└── library
    ├── Makefile
    ├── inc
    │   ├── add
    │   │   └── add.h
    │   ├── calculator.h
    │   ├── div
    │   │   └── div.h
    │   ├── mul
    │   │   └── mul.h
    │   └── sub
    │       └── sub.h
    └── src
        ├── add
        │   └── add.c
        ├── calculator.c
        ├── div
        │   └── div.c
        ├── mul
        │   └── mul.c
        └── sub
            └── sub.c

14 directories, 18 files
```
## Try it out

1. Compile the calculator static library - compiled library and public header file is updated in ./app/lib directory

```shell
> make -C library

mkdir -p build/obj/src/
gcc -Iinc -Iinc/div -Iinc/mul -Iinc/sub -Iinc/add -c src/calculator.c -o build/obj/src/calculator.o
mkdir -p build/obj/src/div/
gcc -Iinc -Iinc/div -Iinc/mul -Iinc/sub -Iinc/add -c src/div/div.c -o build/obj/src/div/div.o
mkdir -p build/obj/src/mul/
gcc -Iinc -Iinc/div -Iinc/mul -Iinc/sub -Iinc/add -c src/mul/mul.c -o build/obj/src/mul/mul.o
mkdir -p build/obj/src/sub/
gcc -Iinc -Iinc/div -Iinc/mul -Iinc/sub -Iinc/add -c src/sub/sub.c -o build/obj/src/sub/sub.o
mkdir -p build/obj/src/add/
gcc -Iinc -Iinc/div -Iinc/mul -Iinc/sub -Iinc/add -c src/add/add.c -o build/obj/src/add/add.o
ar -r build/libCalculator.a build/obj/src/calculator.o build/obj/src/div/div.o build/obj/src/mul/mul.o build/obj/src/sub/sub.o build/obj/src/add/add.o
ar: creating archive build/libCalculator.a
cp ./build/libCalculator.a ../app/lib
cp ./inc/calculator.h ../app/lib
```

2. Compile the application executable and link the calculator library to it -

```shell
> make -C app

mkdir -p build/obj/./
gcc -I. -I./lib -c main.c -o build/obj/./main.o
gcc -L./lib -lCalculator build/obj/./main.o -o build/main
```

3. Run the application -

```shell

> ./app/build/main

-- Calculator --
Addition of 50 and 60 = 110
Subraction of 50 and 60 = -10
Multiplication of 50 and 60 = 3000
Division of 50 and 60 = 0.833333
```

4. To clean the build files -

```shell

> make -C library clean

rm -r ./build

> make -C app clean

rm -r ./build
```