// simpleshell.c
#include "uart.h"
#include "string.h"

/*.global*/
#define BUFFER_MAX_SIZE 5

void read_command(char* buffer);
void parse_command(char* buffer);

void shell() {
  while (1) {
    char buffer[BUFFER_MAX_SIZE];

    // Read command from target
    read_command(buffer);

    // Parse and execute command on host
    parse_command(buffer);
  }
}

void read_command(char* buffer) {
  int index = 0;
  // Print prompt
  //uart_puts("[Waiting target's command]\n");
  uart_puts("# ");
  while (1) {
    buffer[index] = uart_getc(); // get 對方之輸入
    uart_send(buffer[index]); // send回去且-serial stdio會顯示在terminal
    if (buffer[index] == '\n') {
      buffer[index] = '\0';
      buffer[index + 1] = '\n';
      break;
    }
    index++;
  }
}

void parse_command(char* buffer) {
  char* input_string = buffer;
 
  //uart_puts("[Parsing command from host]\n");
  if (strcmp(input_string, "help") == 0) { // command
    //uart_puts("[Responding from host]\n");
    uart_puts("help  : list available commands\n");
    uart_puts("hello : print Hello World!\n");
    // Add more commands here
  } else if (strcmp(input_string, "hello") == 0) {
    uart_puts("Hello World!\n");
  } else {
    uart_puts("Unknown command\n");
  }
}
