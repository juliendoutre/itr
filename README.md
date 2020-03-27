# ITR

Source code for a real-time computer science course.

## Repository organization

The exercices guide the development of functions and classes to manage the real-time execution of tasks on a Linux platform.
In this repository we gathered them in a static library called `itr`.
It is used by several example programs that can be compiled and run to demonstrate the lib features.

- `includes/` contains the header files of the library.
- `src/` contains the source files of both the library functions and classes, and the example programs.
- `doc/` contains the project documentation generated with Doxygen.
- `lib/` contains the static library
- `build/` contains the object files
- `bin/` contains the examples binaries

The `Makefile` allows oneself to compile the static library, the examples and the documentation.

## Usage

```shell
make
```

## Build the documentation

```shell
make doc
```

## Exercices documentation

- [TD0](main_8c.html)
