// Q. Write the following function:
//    void build_index_url (const char *domain, char *index_url);
// domain points to a string containing an Internet domain, such as "knking.com". The function should add "http://www." to the beginning of this string and "/index.html" to the end of the string, storing the result in the string pointed to by index_url. (In this example, the result will be "http://www.knking.com/index.html".) You may assume that index_url points to a variable that is long enough to hold the resulting string. Keep the function as simple as possible by having it use the strcat and strcpy functions.

#include <stdio.h>
#include <string.h>

#define DOMAIN_LEN 20
#define IURL_LEN 50

void build_index_url (const char *domain, char *index_url);
void s_build_index_url (const char *domain, char *index_url);

int main (void) {

  char domain[DOMAIN_LEN + 1];
  char iurl[IURL_LEN + 1];
  char s_iurl[IURL_LEN + 1];

  printf("Enter a domain: ");
  scanf("%s", domain);

  build_index_url(domain, iurl);

  printf("The index url is: %s\n", iurl);

  s_build_index_url(domain, s_iurl);

  printf("The secure index url is: %s\n", s_iurl);

  return 0;
}

void build_index_url (const char *d, char *iurl) {
  strcat(iurl, "http://");
  strcat(iurl, d);
  strcat(iurl, "/index.html");
}

void s_build_index_url (const char *d, char *iurl) {
  strcat(iurl, "https://");
  strcat(iurl, d);
  strcat(iurl, "/index.html");
}

