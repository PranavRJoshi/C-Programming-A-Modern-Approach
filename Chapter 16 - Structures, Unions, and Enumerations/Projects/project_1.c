// Q. Write a program that asks the user to enter an international dialing code and then looks it up in the country_codes array (see Section 16.3). If it finds the code, the program should display the name of the corresponding country; if not, the program should print an error message.

#include <stdio.h>
#include <stdlib.h>

#define COUNTRY_NAME 30

struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[] = { {"Argentina",              54}, {"Bangladesh",         880},
                                              {"Brazil",                 55}, {"Burma (Myanmar)",     95},
                                              {"China",                  86}, {"Colombia",            57},
                                              {"Congo, Dem. Rep. of",   243}, {"Egypt",               20},
                                              {"Ethiopia",              251}, {"France",              33},
                                              {"Germany",                49}, {"India",               91},
                                              {"Indonesia",              62}, {"Iran",                98},
                                              {"Italy",                  39}, {"Japan",               81},
                                              {"Mexico",                 52}, {"Nigeria",            234},
                                              {"Pakistan",               92}, {"Philippines",         63},
                                              {"Poland",                 48}, {"Russia",               7},
                                              {"South Africa",           27}, {"South Korea",         82},
                                              {"Spain",                  34}, {"Sudan",              249},
                                              {"Thailand",               66}, {"Turkey",              90},
                                              {"Ukraine",               380}, {"United Kingdom",      44},
                                              {"United States",           1}, {"Vietnam",             84} };

/*
 * my_strlcpy:  Takes the destination (dst) and source (src)
 *              array along with the size of the destination
 *              array (dst_len). If the source is larger than the
 *              destination, then only dst_len characters
 *              will be stored, plus a null character at the end
 *              in the destination. The dst array should be initialized
 *              with dst_len + 1 character.
*/
int my_strlcpy (char *dst, const char *src, int dst_len);

void clear_input_stream (void);

int main (void) {

  int code;
  char country_name[COUNTRY_NAME + 1];

  int scanf_return_count = 0;

  for (;;) {
    printf("Enter the country code to get the corresponding country name: ");
    if ((scanf_return_count = scanf(" %d", &code)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided.\n");
      clear_input_stream();
      continue;
    }
    scanf_return_count = 0;
    clear_input_stream();
    break;
  }

  for (int i = 0; i < (int) (sizeof(country_codes) / sizeof(country_codes[0])); i++) {
    if (country_codes[i].code == code) {
      my_strlcpy(country_name, country_codes[i].country, COUNTRY_NAME);
      printf("[SUCCESS] %s is the country with the code %d\n", country_name, code);
      exit(EXIT_SUCCESS);
    }
  }

  printf("[FAILURE] %d does not correspond to any country.\n", code);
  exit(EXIT_FAILURE);
}

int my_strlcpy (char *d, const char *s, int d_len) {
  int d_i = 0;

  while (*s != '\0') {
    if (d_i < d_len) {
      *(d + d_i) = *s;
      d_i++;
    }
    s++;
  }
  *(d + d_i) = '\0';
  return d_i;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

