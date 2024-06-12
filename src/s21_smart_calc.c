#include "s21_smart_calc.h"

int s21_smart_calc(char string[MAX_LENGTH], double *result,
                   const char x[MAX_LENGTH]) {
  s21_status status = OK;
  char output_string[255][MAX_LENGTH] = {0};
  if (strlen(string) > 255)
    status = ERROR;
  else if (s21_check_string(string, x) == ERROR)
    status = ERROR;
  else {
    int count = 0;  // кол-во строк в output_string
    if (s21_reverse_polish_notation(string, output_string, &count) == ERROR)
      status = ERROR;
    else if (s21_calculate(output_string, count, result) == ERROR)
      status = ERROR;
  }
  if (isnan(*result)) status = ERROR;
  return status;
}
