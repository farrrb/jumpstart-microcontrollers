# GDB Commands
| Command                       | Description                               | Comment                        |
|-------------------------------|-------------------------------------------|--------------------------------|
| target remote localhost:3333  | Connect to local gdb server at port 3333  |                                |
| load 'filename.elf'           | Download elf file to target               |                                |
| set  disassemble-next-line on | Enables dissassembly for the next line(s) |                                |
| monitor reset halt            | Reset target and halt immediately         | Earliest possible break        |
| info register                 | Show the registers content                | Short version: "i r"           |
| where                         | Displays the current point of execution   |                                |
| examine 'address'             | Examine memory at 'address'               | Short version: "x 'addr'"      |
| backtrace                     | Backtrace: stack trace                    | Short version: "bt"            |
|                               |                                           |                                |
|                               |                                           |                                |
