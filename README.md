# PM/0 Virtual Machine - UCF COP3402 Project

This project is an implementation of the PM/0 machine in C.

The specifications of the machine are provided in `docs/specification.pdf`.

To compile or run, first navigate to directory src:

```sh
$ cd src
```

## Compiling

Using GNU make:

```sh
$ make
```

Using gcc:

```sh
$ gcc -o pm0vm main.c pm0.c loader.c debug.c
```

## Running

Using shell

```sh
$ ./pm0vm (file-path)
```

Where `file-path` is the path to the source file you want to load into the virtual machine.
