# CPUs, MCUs, Processors and other Terms of Interest
Modern computing terms like **Processor**, **CPU**, and **MCU** are poorly defined so I thought it would be smart to write down my own definitions of them right at front of this book.

- **SoC** - System on a Chip - An integrated circuit that contains all components of a system on a single chip (substrate).
- **CPU** - Central Processing Unit - The central processing core, obviously (e.g. Cortex-M0).
- **MCU** - Microcontroller Unit - A SoC containing a CPU, memory, peripherals.
- **Processor** - This is the most generic term (e.g. A microcontroller contains a processor, a CPU is a processor, a Intel(R) Core(TM) i5 is a processor, a SoC may contain a procesor, ...)

# Special Sections
While reading this book you'll run into **"Special Sections"** which are there to increase the readability.

The following examples demonstrate the purpose of these sections:

!!! info
    An additional information.

!!! tip
    A helpful tip.

!!! attention
    This part needs attention.


!!! example
    A short example.


!!! quote
    "A famous quote." - A. Guy


# Code Highlighting

## Shell / Command Line
Commands which are intended to be input in the shell or command line are prefixed by a "$" sign.

For example if i want you to get the version of the current gcc the following should be entered in the command line / bash:
```bash
$ gcc --version
```

## C-Code
You'll find a lot of C-Code on your way which will look like this:

```C
int main(void)
{
  return 0;
}
```

## Assembly
And hopefully only a small amount of assembly, which will look like this:

```asm
.section  .text
.global   _start

_start:
    bkpt
```
