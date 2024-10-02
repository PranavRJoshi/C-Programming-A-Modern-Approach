#include "pointer_fiesta.h"
#include <stdio.h>
#include <stdlib.h>

#define MALLOC_IS_NULL(x)                                               \
if(!(x)) {                                                              \
  fprintf(stderr, "Memory Allocation Failed at line %d\n", __LINE__);   \
  exit(EXIT_FAILURE);                                                   \
}

void initialize_unity_matrix (int n) {

  printf("\n\n*** Calling from %s function ***\n\n", __func__);

  int unity_mat[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        /* type of unity_mat is: int (*)[n], which is a pointer to an array of n elements of type int. */
        *(*(unity_mat + i) + j) = 1;
      } else {
        *(*(unity_mat + i) + j) = 0;
      }
    }
  }

  printf("The initialized matrix is: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d  ", *(*(unity_mat + i) + j));
    }
    printf("\n");
  }

  printf("\n\n*** End of Calling from %s function ***\n\n", __func__);
}

void initialize_space (int length, int breadth, int height) {
  /* One thing to note about allocating memory for elements for a multi-dimensional array
   * is that when allocating storage, we possibly have two ways to allocate memory (as shown
   * below). 
   *
   * The first way allocates memory for length * breadth * height elements of integer
   * type. 
   *
   * The alternative approach is to allocate length * size of a dereferenced pointer which 
   * points to an multi-dimensional array of "row" = breadth, and "column" = height.
   * 
   * The code below shows that sizeof(*p), where p is a pointer to a multi-dimensional array
   * of "row" = breadth and "column" = height. If we use sizeof(p), we most probably would
   * get 8 as the result, as p is a pointer which is--usually--8 bytes in size. But after the
   * indirection operator, it would provide (sizeof(int) * breadth * height) as the result. Be 
   * wary that p initailly does not point to a valid address where we can store a multi-dimensional
   * array of size breadth * height. We need to dynamically allocate the memory before p can be used.
  */
  int (*p)[breadth][height];
  // printf("[LOG] Before memory allocation, the address of p is: %p\n", (void *) p);
  p = (int (*)[breadth][height]) malloc(sizeof(int) * length * breadth * height);
  // p = (int (*)[breadth][height]) malloc(sizeof(*p) * length);    // Alternative
  // printf("[LOG] The size of the dereferenced pointer pointing to %d x %d elements of integers is: %zu\n", breadth, height, sizeof(*p));
  // printf("[LOG] After memory allocation, the address of p is: %p\n", (void *) p);
  if (p == NULL) {
    fprintf(stderr, "Sufficient memory allocation failed. Exiting.\n");
    exit(EXIT_FAILURE);
  }
  printf("The size of the three-dimensional array is: %zu\n", sizeof(*p));

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < breadth; j++) {
      for (int k = 0; k < height; k++) {
        if (i == j && i == k) {
          // p[i][j][k]              = 1;    /* Alternative */
          // (*(p + i))[j][k]        = 1;    /* Alternative */
          // (*(*(p + i) + j))[k]    = 1;    /* Alternative */
          *(*(*(p + i) + j) + k)  = 1;
        } else {
          // p[i][j][k]              = 0;    /* Alternative */
          // (*(p + i))[j][k]        = 0;    /* Alternative */
          // (*(*(p + i) + j))[k]    = 0;    /* Alternative */
          *(*(*(p + i) + j) + k)  = 0;
        }
      }
    }
  }

  /* Printing out the elements of variable p */
  for (int i = 0; i < length; i++) {
    printf("> Row %d (length): \n", i + 1);
    for (int j = 0; j < breadth; j++) {
      printf(">> Sub-row %d (breadth): \n", j + 1);
      for (int k = 0; k < height; k++) {
        // printf("%d  ", p[i][j][k]);
        printf("%d  ", *(*(*(p + i) + j) + k));
      }
      printf("\n");
    }
    printf("\n");
  }

  /* Freeing up dynamically allocated memory */
  /* No need to free individual inner rows like the one below as the 
   * memory allocated is a single contigious block of memory
  */
  free(p);
  /* Avoid dangling pointer */
  p = NULL;
}

void initialize_quartic (int first, int second, int third, int fourth) {
  // printf("[LOG] first: %d, second: %d, third: %d, fourth: %d\n", first, second, third, fourth);
  /* Dynamically allocating memory */
  /* Allocating "first" amount of pointer to a pointer to a pointer to an integer. */
  int ****test = malloc(sizeof(int ***) * first);
  MALLOC_IS_NULL(test);
  for (int i = 0; i < first; i++) {
    /* Allocating "second" amount of pointer to a pointer to an integer */
    // test[i] = malloc(sizeof(int **) * second);         // Alternative
    // MALLOC_IS_NULL(test[i]);                           // Alternative
    *(test + i) = malloc(sizeof(int **) * second);
    MALLOC_IS_NULL(*(test + i));
    for (int j = 0; j < second; j++) {
      /* Allocating "third" amount of pointer to an integer */
      // test[i][j] = malloc(sizeof(int *) * third);      // Alternative
      // MALLOC_IS_NULL(test[i][j]);                      // Alternative
      *(*(test + i) + j) = malloc(sizeof(int *) * third);
      MALLOC_IS_NULL(*(*(test + i) + j));
      for (int k = 0; k < third; k++) {
        /* Allocating "fourth" amount of integers. */
        // test[i][j][k] = malloc(sizeof(int) * fourth);  // Alternative
        // MALLOC_IS_NULL(test[i][j][k]);                 // Alternative
        *(*(*(test + i) + j) + k) = malloc(sizeof(int) * fourth);
        MALLOC_IS_NULL(*(*(*(test + i) + j) + k));
      }
    }
  }

  /* Adding numbers to the dynamically allocated memory */
  int n = 1;
  for (int i = 0; i < first; i++) {
    for (int j = 0; j < second; j++) {
      for (int k = 0; k < third; k++) {
        for (int l = 0; l < fourth; l++) {
          // test[i][j][k][l] = n;      // Alternative
          *(*(*(*(test + i) + j) + k) + l) = n;
          n++;
        }
      }
    }
  }

  /* Printing the numbers */
  for (int i = 0; i < first; i++) {
    printf("> Row %d (first): \n", i + 1);
    for (int j = 0; j < second; j++) {
      printf(">> Sub-row %d (second): \n", j + 1);
      for (int k = 0; k < third; k++) {
        printf(">>> Sub-sub-row %d (third): \n", k + 1);
        for (int l = 0; l < fourth; l++) {
          // printf("%d  ", test[i][j][k][l]);      // Alternative
          printf("%d  ", *(*(*(*(test + i) + j) + k) + l));
        }
        printf("\n");
      }
      printf("\n");
    }
    printf("\n");
  }


  /* Freeing up the dynamically allocated memory */
  for (int i = 0; i < first; i++) {
    for (int j = 0; j < second; j++) {
      for (int k = 0; k < third; k++) {
        // free(test[i][j][k]);               // Alternative
        free((*(*(*(test + i) + j) + k)));
      }
      // free(test[i][j]);                    // Alternative
      free((*(*(test + i) + j)));
    }
    // free(test[i]);                         // Alternative
    free((*(test + i)));
  }
  free(test);
  /* Avoid dangling pointer */
  test = NULL;
}

void initialize_quintic (int sizes[static 5]) {
  /* Assuming that the elements of the array sizes correspond to the ptr. Like the first element represents
   * the topmost row's size and so on...
  */

  /*
   * Consider a simple scenario, we need to declare a multi-dimensional array of form
   * a[1][2][3][4][5]. The array can have indices as a[0][<0-1>][<0-2>][<0-3>][<0-4>]
   *
   * quintic_ptr is a pointer to a pointer to a pointer to a multi-dimensional array
   * of size--in this example--major row of 4 and the second row of 5. 
   *
   * We first malloc 1 * (pointer to pointer to array of multi-dimensional array). 
   *
   * We then iterator through the malloc'd addresses, in each iteration, allocating 
   * 2 * pointer to array of multi-dimensional array. 
   *
   * For the above allocation, we then again initialize a loop and then, for each 
   * sub-iteration, we need to malloc 3 * (space for a multi-dimensional array)
   *
   * Considering that the last two indices are 4 and 5 and the elements are integer,
   * the size of the multi-dimensional array will be 4 * 5 * (4 bytes) = 80 bytes.
   *
   * Tracking back, we notice that each pointer to a multi-dimensional array will have 
   * space for 3 * 80 bytes = 240 bytes. There is one pointer to pointer which points to 
   * two pointer to multi-dimensional array. Since there are two of them, the total allocation
   * will have 2 * 240 bytes = 480 bytes.
  */
  int (***quintic_ptr)[sizes[3]][sizes[4]] = NULL;
  
  printf("The size of quintic_ptr is: %zu\n", sizeof(***quintic_ptr));
  quintic_ptr = malloc(sizeof(int (**)[sizes[3]][sizes[4]]) * sizes[0]);
  MALLOC_IS_NULL(quintic_ptr)
  for (int i = 0; i < sizes[0]; i++) {
    *(quintic_ptr + i) = malloc(sizeof(int (*)[sizes[3]][sizes[4]]) * sizes[1]);
    MALLOC_IS_NULL(*(quintic_ptr + i));
    for (int j = 0; j < sizes[1]; j++) {
      *(*(quintic_ptr + i) + j) = malloc(sizeof(***quintic_ptr) * sizes[2]);
      MALLOC_IS_NULL(*(*(quintic_ptr + i) + j));
    }
  }

  int n = 1;

  for (int i = 0; i < sizes[0]; i++) {
    for (int j = 0; j < sizes[1]; j++) {
      for (int k = 0; k < sizes[2]; k++) {
        for (int l = 0; l < sizes[3]; l++) {
          for (int m = 0; m < sizes[4]; m++) {
            *(*(*(*(*(quintic_ptr + i) + j) + k) + l) + m) = n;
            // quintic_ptr[i][j][k][l][m] = n;      // Alternative
            n++;
          }
        }
      }
    }
  }

  printf("Printing this obnixious whatever this is: \n");
  for (int i = 0; i < sizes[0]; i++) {
    printf("> Row %d: \n", i + 1);
    for (int j = 0; j < sizes[1]; j++) {
      printf(">> Row %d: \n", j + 1);
      for (int k = 0; k < sizes[2]; k++) {
        printf(">>> Row %d: \n", k + 1);
        for (int l = 0; l < sizes[3]; l++) {
          printf(">>>> Row %d: \n", l + 1);
          for (int m = 0; m < sizes[4]; m++) {
            printf("%d  ", *(*(*(*(*(quintic_ptr + i) + j) + k) + l) + m));
            // printf("%d  ", quintic_ptr[i][j][k][l][m]);    // Alternative
          }
          printf("\n");
        }
        printf("\n");
      }
      printf("\n");
    }
    printf("\n");
  }

  /* Freeing up the memory... */
  for (int i = 0; i < sizes[0] + 1; i++) {
    for (int j = 0; j < sizes[1]; j++) {
      /* Freeing up the pointer to multi-dimensional array */
      free(*(*(quintic_ptr + i) + j));
    }
    /* Freeing up the pointer to pointer to multi-dimensional array */
    free(*(quintic_ptr + i));
  }
  /* Freeing up the pointer to pointer to pointer to multi-dimensional array */
  free(quintic_ptr);
  /* Avoid dangling pointer */
  quintic_ptr = NULL;
}

