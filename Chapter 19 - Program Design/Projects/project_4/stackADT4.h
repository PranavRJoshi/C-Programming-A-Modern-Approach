/* stackADT.h (version 4) */
#ifndef STACKADT_4_H
#define STACKADT_4_H

#include <stdbool.h>        /* C99 only */

typedef struct stack_type_ll *Stack_ll;

Stack_ll create_ll      (void);
void     destroy_ll     (Stack_ll s);
void     make_empty_ll  (Stack_ll s);
bool     is_empty_ll    (Stack_ll s);
bool     is_full_ll     (Stack_ll s);
void     push_ll        (Stack_ll s, void *i);
void     *pop_ll        (Stack_ll s);

#endif

