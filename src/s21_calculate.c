#include "s21_smart_calc.h"

int s21_calculate(char output_string[255][MAX_LENGTH], int count,
                  double *result) {
  s21_status status = OK;
  s21_stack_number *stack_number =
      (s21_stack_number *)calloc(1, sizeof(s21_stack_number));
  s21_create_stack_number(stack_number);
  double number = 0, left = 0, right = 0;
  for (int i = 0; i < count && status == OK; ++i) {
    if (isdigit(output_string[i][0]))
      s21_push_number(stack_number, strtod(output_string[i], NULL));
    else {
      if (s21_check_priority(output_string[i]) <= 3 ||
          strcmp(output_string[i], "^") == 0 ||
          strcmp(output_string[i], "%") == 0) {
        left = s21_pop_number(stack_number);
        right = s21_pop_number(stack_number);
        if (strcmp(output_string[i], "+") == 0)
          *result = right + left;
        else if (strcmp(output_string[i], "-") == 0)
          *result = right - left;
        else if (strcmp(output_string[i], "*") == 0)
          *result = right * left;
        else if (strcmp(output_string[i], "/") == 0) {
          if (left == 0)
            *result = NAN;
          else
            *result = right / left;
        } else if (strcmp(output_string[i], "^") == 0)
          *result = pow(right, left);
        else if (strcmp(output_string[i], "%") == 0)
          *result = fmod(right, left);
      } else {
        number = s21_pop_number(stack_number);
        if (strcmp(output_string[i], "o-") == 0)
          *result = (-1) * number;
        else if (strcmp(output_string[i], "o+") == 0)
          *result = number;
        else if (strcmp(output_string[i], "sin") == 0)
          *result = sin(number);
        else if (strcmp(output_string[i], "cos") == 0)
          *result = cos(number);
        else if (strcmp(output_string[i], "tan") == 0)
          *result = tan(number);
        else if (strcmp(output_string[i], "acos") == 0)
          *result = acos(number);
        else if (strcmp(output_string[i], "asin") == 0)
          *result = asin(number);
        else if (strcmp(output_string[i], "atan") == 0)
          *result = atan(number);
        else if (strcmp(output_string[i], "sqrt") == 0)
          *result = sqrt(number);
        else if (strcmp(output_string[i], "ln") == 0)
          *result = log(number);
        else if (strcmp(output_string[i], "log") == 0)
          *result = log10(number);
      }
      s21_push_number(stack_number, *result);
      if (isnan(*result)) status = ERROR;
    }
  }
  *result = s21_pop_number(stack_number);
  free(stack_number);
  return status;
}

void s21_create_stack_number(s21_stack_number *stack_number) {
  stack_number->index_top = -1;
}

void s21_push_number(s21_stack_number *stack_number, double number) {
  if (stack_number->index_top < MAX_LENGTH - 1) {
    stack_number->index_top++;
    stack_number->items[stack_number->index_top] = number;
  }
}

double s21_pop_number(s21_stack_number *stack_number) {
  double number = 0;
  if (stack_number->index_top >= 0) {
    number = stack_number->items[stack_number->index_top];
    stack_number->index_top--;
  }
  return number;
}