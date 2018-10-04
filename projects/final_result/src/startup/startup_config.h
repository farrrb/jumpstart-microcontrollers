///< Startup Configuration

#ifndef STARTUP_CONFIG_H
#define STARTUP_CONFIG_H

#define HEAP_SIZE   (1024)        ///< [Byte]
#define STACK_SIZE  (1024)        ///< [Byte]

#define HEAP_MAGIC  (0xDEADBEEF)  ///< A magic word to examine heap usage
#define STACK_MAGIC (0xFEEDC0DE)  ///< A magic word to examine stack usage

#endif
