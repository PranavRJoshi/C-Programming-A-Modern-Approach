// Q. Write a function that, when given a string as its argument, searches the following array of structures for a matching command name, then calls the function associated with that name.
//    struct {
//      char *cmd_name;
//      void (*cmd_pointer)(void);
//    } file_cmd[] =  {
//                      {"new",         new_cmd},
//                      {"open",        open_cmd},
//                      {"close",       close_cmd},
//                      {"close all",   close_all_cmd},
//                      {"save",        save_cmd},
//                      {"save as",     save_as_cmd},
//                      {"save all",    save_all_cmd},
//                      {"print",       print_cmd},
//                      {"exit",        exit_cmd}
//                    };

#include <stdio.h>

#define CMD_LEN 10

void new_cmd          (void);
void open_cmd         (void);
void close_cmd        (void);
void close_all_cmd    (void);
void save_cmd         (void);
void save_as_cmd      (void);
void save_all_cmd     (void);
void print_cmd        (void);
void exit_cmd         (void);

int check_command (const char *cmd);

int my_strcmp (const char *str_1, const char *str_2);

int read_line(char *str, int n);

int main () {

  char command[CMD_LEN + 1];
  
  printf("The following commands are available:\n"                            \
         "Command                 Usage\n"                                    \
         "-------                 ------\n"                                   \
         "new                     new command\n"                              \
         "open                    open command\n"                             \
         "close                   close command\n"                            \
         "close all               close all command\n"                        \
         "save                    save command\n"                             \
         "save as                 save as command\n"                          \
         "save all                save all command\n"                         \
         "print                   print command\n"                            \
         "exit                    exit command\n"                             \
         ">> Enter command: ");
  read_line(command, CMD_LEN + 1);

  if (check_command(command)) {
    fprintf(stderr, "[ERROR] %s Command Not Found.\n", command);
  }

  return 0;
}

void new_cmd (void) {
  printf("Invoked the new_cmd function.\n");
}
void open_cmd (void) {
  printf("Invoked the open_cmd function.\n");
}

void close_cmd (void) {
  printf("Invoked the close_cmd function.\n");
}

void close_all_cmd (void) {
  printf("Invoked the close_all_cmd function.\n");
}

void save_cmd (void) {
  printf("Invoked the save_cmd function.\n");
}

void save_as_cmd (void) {
  printf("Invoked the save_as_cmd function.\n");
}

void save_all_cmd (void) {
  printf("Invoked the save_all_cmd function.\n");
}

void print_cmd (void) {
  printf("Invoked the print_cmd function.\n");
}

void exit_cmd (void) {
  printf("Invoked the exit_cmd function.\n");
}

int check_command (const char *cmd) {
  struct {
    char *cmd_name;
    void (*cmd_pointer)(void);
  } file_cmd[] =  {
                    {"new",         new_cmd},
                    {"open",        open_cmd},
                    {"close",       close_cmd},
                    {"close all",   close_all_cmd},
                    {"save",        save_cmd},
                    {"save as",     save_as_cmd},
                    {"save all",    save_all_cmd},
                    {"print",       print_cmd},
                    {"exit",        exit_cmd}
                 };
  
  for (int i = 0; i < (int) ((sizeof(file_cmd)) / sizeof(file_cmd[0])); i++) {
    if (my_strcmp(file_cmd[i].cmd_name, cmd) == 0) {
      file_cmd[i].cmd_pointer();
      return 0;
    }
  }
  return 1;
}

int my_strcmp (const char *str_1, const char *str_2) {
  for (; *str_1 == *str_2; str_1++, str_2++) {
    if (*str_1 == '\0') {
      return 0;
    }
  }
  return *str_1 - *str_2;
}

int read_line(char *str, int n) {
  int len = 0;
  int ch;

  while ((ch = getchar()) != '\n') {
    if (len < (n - 1)) {
      *(str+len) = ch;
      len++;
    }
  }

  *(str + len) = '\0';
  return len;
}
