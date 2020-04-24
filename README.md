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

to generate HTML and Latex Doxygen documentation for the project in the `doc/` folder.

It will load the produced html page on your default browser (`doc/html/index.html`).

## Documentation
- [TD1](./td1.html)
- [TD2](./td2.html)
- [TD3](./td3.html)
- [TD4](./td4.html)
- [TD6](./td6.html)
