#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 300
#define NICE_SYMBOLS "0123456789= */+-()^."

typedef enum { OK = 0, ERROR = 1 } s21_status;

typedef struct s21_stack_string {
  int index_top;
  char items[255][MAX_LENGTH];
} s21_stack_string;

typedef struct s21_struct_number {
  int index_top;
  double items[MAX_LENGTH];
} s21_stack_number;

int s21_smart_calc(char string[MAX_LENGTH], double *result,
                   const char x[MAX_LENGTH]);

// s21_input_check
int s21_check_string(char string[MAX_LENGTH], const char x[MAX_LENGTH]);
int s21_remove_spaces(char string[MAX_LENGTH]);
int s21_insert_x(char string[MAX_LENGTH], const char x[MAX_LENGTH]);
int s21_check_spaces(char string[MAX_LENGTH]);
int s21_check_brackets(char string[MAX_LENGTH]);
int s21_check_equal(char string[MAX_LENGTH]);
int s21_check_words(char string[MAX_LENGTH]);
int s21_check_func(char string[MAX_LENGTH]);
int s21_check_digits(char string[MAX_LENGTH]);
int s21_check_order(char string[MAX_LENGTH]);
int s21_char_compare(char search, const char *symbols);

// s21_reverse_polish_notation
int s21_reverse_polish_notation(char string[MAX_LENGTH],
                                char output_string[255][MAX_LENGTH],
                                int *count);
void s21_create_stack_string(s21_stack_string *stack_string);
void s21_push_string(s21_stack_string *stack_string, char string[MAX_LENGTH]);
char *s21_pop_string(s21_stack_string *stack_string);
int s21_check_priority(char string[MAX_LENGTH]);

// s21_calculate
int s21_calculate(char output_string[255][MAX_LENGTH], int count,
                  double *result);
void s21_create_stack_number(s21_stack_number *stack_number);
void s21_push_number(s21_stack_number *stack_number, double number);
double s21_pop_number(s21_stack_number *stack_number);

#endif