# GDB Commands

| Command                       | Description                               | Comment                        |
|-------------------------------|-------------------------------------------|--------------------------------|
| arm-none-eabi-gdb file.elf    | Start gdb with file "file.elf"            |                                |
| target remote localhost:3333  | Connect to local gdb server at port 3333  | Short version: "tar rem :3333" |
| load 'filename.elf'           | Download elf file to target               | File name is optional          |
| set  disassemble-next-line on | Enables dissassembly for the next line(s) |                                |
| monitor reset halt            | Reset target and halt immediately         | Earliest possible break        |
| info register                 | Show the registers content                | Short version: "i r"           |
| where                         | Displays the current point of execution   |                                |
| examine 'address'             | Examine memory at 'address'               | Short version: "x 'addr'"      |
| backtrace                     | Backtrace: stack trace                    | Short version: "bt"            |
| continue                      | continue execution                        | Short version: "c"             |
| break main.c:55               | set breakpoint in main.c at line 55       |                                |
| clear main.c:55               | clr breakpoint in main.c at line 55       |                                |
| delete                        | clears every breakpoint                   | Short version: "del"           |
| info break                    | show information for every breakpoint     | Short version: "i b"           |
| print 'var'                   | prints variable "var"                     | Short version: "p 'var'"       |
