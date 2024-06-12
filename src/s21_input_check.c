#include "s21_smart_calc.h"

// all checks
int s21_check_string(char string[MAX_LENGTH], const char x[MAX_LENGTH]) {
  s21_status status = s21_remove_spaces(string);
  if (status == OK) status = s21_insert_x(string, x);
  if (status == OK) status = s21_check_spaces(string);
  if (status == OK) status = s21_check_brackets(string);
  if (status == OK) status = s21_check_equal(string);
  if (status == OK) status = s21_check_words(string);
  if (status == OK) status = s21_check_digits(string);
  if (status == OK) status = s21_check_order(string);
  return status;
}

/*
Removes double space and check for indeclarated symbols. Changes "mod" to '%'
input:
 - char string[MAX_LENGTH]
output:
 - status code (OK or ERROR)
*/
int s21_remove_spaces(char string[MAX_LENGTH]) {
  s21_status status = OK;
  int len = strlen(string);
  char new_string[MAX_LENGTH] = {0};
  int index = 0;
  int k = 0;
  // remove spaces in start string
  while (string[k] == ' ' && k < len) k++;
  if (k > 0) k--;
  for (int i = k; i < len; ++i) {
    // Check for "nice" symbols
    if ((string[i] >= 'a' && string[i] <= 'z') ||
        s21_char_compare(string[i], NICE_SYMBOLS) == OK) {
      // check for extra space
      if ((string[i] == ' ' && string[i + 1] != ' ') || string[i] != ' ') {
        // check for "mod"
        if (i + 2 < len && strncmp(&string[i], "mod", 3) == 0) {
          new_string[index++] = '%';
          i += 2;
        } else
          new_string[index++] = string[i];
      }
    } else
      status = ERROR;
  }
  if (status == OK) {
    // remove spaces after '='
    if (new_string[index - 1] == ' ')
      new_string[index - 1] = '\0';
    else
      new_string[index] = '\0';
    memset(string, 0, MAX_LENGTH * sizeof(char));
    memcpy(string, new_string, strlen(new_string));
  }
  return status;
}

/*
Changes "x" to value in x. Checks for left and right symbols from x (Need to be
operands.) input:
 - char string[MAX_LENGTH]
 - const char x[MAX_LENGTH]
output:
 - status code (OK or ERROR)
*/
int s21_insert_x(char string[MAX_LENGTH], const char x[MAX_LENGTH]) {
  s21_status status = OK, change_status = ERROR;
  char new_string[MAX_LENGTH] = {0};
  int index = 0;
  char *ptr;
  // Check for correct x
  if (strtod(x, &ptr) == 0 && ptr == string) status = ERROR;
  // search for x and change it
  for (size_t i = 0; i < strlen(string) && status == OK; ++i) {
    if (string[i] == 'x') {
      if ((i > 0 && (isdigit(string[i - 1]) || string[i - 1] == 'x')) ||
          (i + 1 < strlen(string) &&
           (isdigit(string[i + 1]) || string[i + 1] == 'x')))
        status = ERROR;
      else {
        change_status = OK;
        for (size_t j = 0; j < strlen(x); ++j) new_string[index++] = x[j];
      }
    } else
      new_string[index++] = string[i];
  }
  // and copy new string to string
  if (change_status == OK) {
    new_string[index] = '\0';
    memset(string, 0, MAX_LENGTH * sizeof(char));
    memcpy(string, new_string, strlen(new_string));
  }
  return status;
}

/*
Check for corect spaces between functions, numbers and operators.
input:
 - char string[MAX_LENGTH]
output:
 - status code (OK or ERROR)
*/
int s21_check_spaces(char string[MAX_LENGTH]) {
  s21_status status = OK;
  int len = strlen(string), index = 0;
  char new_string[MAX_LENGTH] = {0};
  for (int i = 0; i < len && status == OK; ++i) {
    // check for no spaces left and right from point (in double numbers) and
    // after functions
    if (i > 0 && string[i] == ' ' &&
        (((isdigit(string[i - 1]) || string[i - 1] == '.') && i + 1 < len &&
          (isdigit(string[i + 1]) || string[i + 1] == '.')) ||
         isalpha(string[i - 1])))
      status = ERROR;
    else if (string[i] != ' ')
      new_string[index++] = string[i];
  }
  // copy new_string to string
  if (status == OK) {
    new_string[index] = '\0';
    memset(string, 0, MAX_LENGTH * sizeof(char));
    memcpy(string, new_string, strlen(new_string));
  }
  return status;
}

/*
Check brackets for correct. "()" - is not allowed.
input:
 - char string[MAX_LENGTH]
output:
 - status code (OK or ERROR)
*/
int s21_check_brackets(char string[MAX_LENGTH]) {
  s21_status status = OK;
  int len = strlen(string);
  for (int i = 0; i < len - 1; ++i) {
    if (string[i] == '(' && string[i + 1] == ')') status = ERROR;
  }
  return status;
}

/*
check for correct '='
input:
 - char string[MAX_LENGTH]
output:
 - status code (OK or ERROR)
*/
int s21_check_equal(char string[MAX_LENGTH]) {
  s21_status status = OK;
  int len = strlen(string);
  int count = 0;
  // check for only 1 '='
  for (int i = 0; i < len && status == OK; ++i) {
    if (string[i] == '=') count++;
    if (count > 1) status = ERROR;
  }
  // check for '=' in the end
  if (count == 0 && string[len - 1] != '=') status = ERROR;
  return status;
}

/*
check for correct words (bracket after word, correct word)
input:
 - char string[MAX_LENGTH]
output:
 - status code (OK or ERROR)
*/
int s21_check_words(char string[MAX_LENGTH]) {
  s21_status status = OK, find_func = ERROR;
  int len = strlen(string);
  char function_word[MAX_LENGTH] = {0};
  int index = 0;
  for (int i = 0; i < len && status == OK; ++i) {
    index = 0;
    // Write word in function_word
    while (isalpha(string[i])) {
      function_word[index++] = string[i++];
      find_func = OK;
    }
    // if find word, check it
    if (find_func == OK) {
      function_word[index] = '\0';
      if (s21_check_func(function_word) == OK && string[i] == '(') {
        find_func = ERROR;
        memset(function_word, 0, MAX_LENGTH * sizeof(char));
      } else
        status = ERROR;
    }
  }
  return status;
}

/*
Check for correct words
input:
 - char string[MAX_LENGTH]
output:
 - status code (OK or ERROR)
*/
int s21_check_func(char string[MAX_LENGTH]) {
  s21_status status = ERROR;
  if (strcmp(string, "sin") == 0 || strcmp(string, "cos") == 0 ||
      strcmp(string, "tan") == 0 || strcmp(string, "atan") == 0 ||
      strcmp(string, "asin") == 0 || strcmp(string, "acos") == 0 ||
      strcmp(string, "sqrt") == 0 || strcmp(string, "ln") == 0 ||
      strcmp(string, "log") == 0 || strcmp(string, "mod") == 0)
    status = OK;
  return status;
}

/*
check for correct digits (1 point max, right and left from point numbers)
input:
 - char string[MAX_LENGTH]
output:
 - status code (OK or ERROR)
*/
int s21_check_digits(char string[MAX_LENGTH]) {
  s21_status status = OK, find_digit = ERROR;
  int len = strlen(string), count = 0;
  for (int i = 0; i < len && status == OK; ++i) {
    count = 0;
    find_digit = ERROR;
    while ((i < len) && (isdigit(string[i]) || (string[i] == '.'))) {
      find_digit = OK;
      if (string[i] == '.') count++;
      if (count > 1 ||
          (string[i] == '.' && (i - 1 < 0 || !isdigit(string[i - 1]) ||
                                i + 1 >= len || !isdigit(string[i + 1]))))
        status = ERROR;
      ++i;
    }
    if (find_digit == OK) i--;
  }
  return status;
}

/*
Check for correct order of operations, digits, brackets, etc.
input:
 - char string[MAX_LENGTH]
output:
 - status code (OK or ERROR)
*/
int s21_check_order(char string[MAX_LENGTH]) {
  s21_status status = OK;
  int len = strlen(string);
  // flags: 1 - digits, 2 - binary, 3 - unary
  int flag = 0;
  for (int i = 0; i < len && status == OK; ++i) {
    // check for digits before
    if (isdigit(string[i]) || string[i] == '.') {
      if (flag == 1)
        status = ERROR;
      else {
        while (i < len && (isdigit(string[i]) || string[i] == '.')) ++i;
        --i;
        flag = 1;
      }
    }
    // check for operations */^%
    if (s21_char_compare(string[i], "*/^%") == OK) {
      if (flag == 2 || flag == 0)
        status = ERROR;
      else
        flag = 2;
    }
    // check for '-' and '+'
    if (string[i] == '+' || string[i] == '-') {
      if (i == 0 ||
          (i - 1 >= 0 && s21_char_compare(string[i - 1], "+-*/^%") == OK)) {
        if (flag == 3)
          status = ERROR;
        else
          flag = 3;
      } else
        flag = 2;
    }
  }
  if (flag == 2 || flag == 3) status = ERROR;
  return status;
}

/*
Search for symbol in string
input:
 - char search - symbol for search
 - char *symbols - string with symbols
output:
 - status code (OK or ERROR)
*/
int s21_char_compare(char search, const char *symbols) {
  s21_status status = ERROR;
  for (size_t i = 0; i < strlen(symbols) && status == ERROR; ++i) {
    if (search == symbols[i]) status = OK;
  }
  return status;
}
