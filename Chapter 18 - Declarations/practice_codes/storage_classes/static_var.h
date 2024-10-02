#ifndef STATIC_VAR_H
#define STATIC_VAR_H

extern int count;

extern long int l_count;

void s_incrementor (void);

void total_func_count (void);

void r_checker (void);

void e_checker (void);

static void s_func (void);

void *get_static_function_address (void);

#endif 
