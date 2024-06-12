#include "s21_smart_calc.h"

int s21_reverse_polish_notation(char string[MAX_LENGTH],
                                char output_string[255][MAX_LENGTH],
                                int *count) {
  s21_stack_string *stack_string =
      (s21_stack_string *)calloc(1, sizeof(s21_stack_string));
  s21_create_stack_string(stack_string);
  char tmp_string[MAX_LENGTH] = {0};
  char tmp_number[MAX_LENGTH] = {0};
  char tmp_operation[MAX_LENGTH] = {0};
  s21_status status = OK, exit_status = OK;
  s21_status flag_number = ERROR, flag_operation = ERROR;
  int index_number = 0, index_operation = 0;
  int len = strlen(string);
  for (int i = 0; i < len && status == OK && exit_status == OK; ++i) {
    flag_number = ERROR;
    flag_operation = ERROR;
    index_number = 0;
    memset(tmp_number, 0, MAX_LENGTH * sizeof(char));
    while ((i < len) && (isdigit(string[i]) || (string[i] == '.'))) {
      flag_number = OK;
      tmp_number[index_number++] = string[i++];
    }
    if (flag_number == OK) {
      tmp_number[index_number] = '\0';
      strcpy(output_string[*count], tmp_number);
      (*count)++;
      i--;
    }
    if (string[i] == '(') {
      memset(tmp_string, 0, MAX_LENGTH * sizeof(char));
      tmp_string[0] = string[i];
      tmp_string[1] = '\0';
      s21_push_string(stack_string, tmp_string);
    }
    if (string[i] == ')') {
      char *string_in_stack = s21_pop_string(stack_string);
      memset(tmp_string, 0, MAX_LENGTH * sizeof(char));
      strcpy(tmp_string, string_in_stack);
      while (strcmp(tmp_string, "(") != 0 && stack_string->index_top >= 0) {
        strcpy(output_string[*count], tmp_string);
        *count += 1;
        string_in_stack = s21_pop_string(stack_string);
        memset(tmp_string, 0, MAX_LENGTH * sizeof(char));
        strcpy(tmp_string, string_in_stack);
      }
      if (strcmp(tmp_string, "(") != 0) status = ERROR;
    }
    memset(tmp_operation, 0, MAX_LENGTH * sizeof(char));
    if ((string[i] == '+' || string[i] == '-') &&
        (i == 0 ||
         (i - 1 > 0 && s21_char_compare(string[i - 1], "(+-*/^%") == OK))) {
      tmp_operation[0] = 'o';
      tmp_operation[1] = string[i];
      tmp_operation[2] = '\0';
      flag_operation = OK;
    } else if (s21_char_compare(string[i], "+-*/^%") == OK) {
      tmp_operation[0] = string[i];
      tmp_operation[1] = '\0';
      flag_operation = OK;
    }
    index_operation = 0;
    if (isalpha(string[i])) {
      while (isalpha(string[i]) && i < len)
        tmp_operation[index_operation++] = string[i++];
      --i;
      tmp_operation[index_operation] = '\0';
      flag_operation = OK;
    }
    if (flag_operation == OK) {
      int priority_tmp_operation = s21_check_priority(tmp_operation);
      int priority_stack = -1;
      if (stack_string->index_top >= 0)
        priority_stack =
            s21_check_priority(stack_string->items[stack_string->index_top]);
      while (stack_string->index_top >= 0 &&
             (priority_stack > priority_tmp_operation ||
              (priority_stack == priority_tmp_operation &&
               strcmp(tmp_operation, "^") != 0))) {
        char *string_in_stack = s21_pop_string(stack_string);
        memset(tmp_string, 0, MAX_LENGTH * sizeof(char));
        strcpy(tmp_string, string_in_stack);
        strcpy(output_string[*count], tmp_string);
        (*count)++;
        if (stack_string->index_top >= 0)
          priority_stack =
              s21_check_priority(stack_string->items[stack_string->index_top]);
        else
          priority_stack = -1;
      }
      s21_push_string(stack_string, tmp_operation);
    }
    if (string[i] == '=') exit_status = ERROR;
  }
  while (stack_string->index_top != -1) {
    char *string_in_stack = s21_pop_string(stack_string);
    memset(tmp_string, 0, MAX_LENGTH * sizeof(char));
    strcpy(tmp_string, string_in_stack);
    if (strcmp(tmp_string, "(") == 0) status = ERROR;
    strcpy(output_string[*count], tmp_string);
    (*count)++;
  }
  free(stack_string);
  return status;
}

void s21_create_stack_string(s21_stack_string *stack_string) {
  stack_string->index_top = -1;
}

void s21_push_string(s21_stack_string *stack_string, char string[MAX_LENGTH]) {
  if (stack_string->index_top < MAX_LENGTH - 1) {
    stack_string->index_top++;
    strcpy(stack_string->items[stack_string->index_top], string);
  }
}

char *s21_pop_string(s21_stack_string *stack_string) {
  if (stack_string->index_top >= 0) {
    stack_string->index_top--;
  }
  return stack_string->items[stack_string->index_top + 1];
}

int s21_check_priority(char string[MAX_LENGTH]) {
  int result = 0;
  if (strcmp(string, "(") == 0) {
    result = 1;
  } else if (strcmp(string, "+") == 0 || strcmp(string, "-") == 0) {
    result = 2;
  } else if (strcmp(string, "*") == 0 || strcmp(string, "/") == 0 ||
             strcmp(string, "%") == 0) {
    result = 3;
  } else if (strcmp(string, "^") == 0) {
    result = 4;
  } else if (strcmp(string, "o+") == 0 || strcmp(string, "o-") == 0 ||
             strcmp(string, "sin") == 0 || strcmp(string, "cos") == 0 ||
             strcmp(string, "tan") == 0 || strcmp(string, "acos") == 0 ||
             strcmp(string, "asin") == 0 || strcmp(string, "atan") == 0 ||
             strcmp(string, "mod") == 0 || strcmp(string, "sqrt") == 0 ||
             strcmp(string, "ln") == 0 || strcmp(string, "log") == 0) {
    result = 5;
  }
  return result;
}