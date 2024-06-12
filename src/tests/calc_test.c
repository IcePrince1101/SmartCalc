#include <check.h>

#include "../s21_smart_calc.h"

START_TEST(test_s21_smart_calc_1) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "3+3=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 6.0);
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_2) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "(2.33+2.33)*10=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 46.6);
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_3) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "0+0.234=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0.234);
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_4) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "10-1+2*10-5*5=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 4);
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_5) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "cos(tan(1))=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(0.0133882) <= 0.00001, "test-5 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_6) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "sin(log(2))=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(0.296504) <= 0.00001, "test-6 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_7) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "log(ln(2))/10^2=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(-0.001591) <= 0.00001, "test-7 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_8) {
  double result = 0;
  const char x[MAX_LENGTH] = "1";
  char str[MAX_LENGTH] = "atan(x)=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(0.785398) <= 0.00001, "test-8 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_9) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "1++=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_10) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "1+2+=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_11) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "10mod7=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 3);
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_12) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "sqrt(6)=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(2.449489) <= 0.00001, "test-12 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_13) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "sqrt(0)=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_14) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "1.22*2+(6-3.33)/log(3)=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(8.03606174235) <= 0.00001,
                "test-3_1 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_15) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "asin(1)=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(1.570796) <= 0.00001, "test-15 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_16) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "acos(0)=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(1.570796) <= 0.00001, "test-16 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_17) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "-2+3+(-2)-3-(+2)=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, -6);
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_18) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] =
      "cos(0.48) ( * ) sqrt(0.24) ()  + asin(acos(0.28)) ^ 0.33 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_19) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] =
      "cos(0.48) *     sqrt(0.24)  + asin(acos(0.28)) ^ 0.33 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_float_nan(result);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_20) {
  double result = 0;
  const char x[MAX_LENGTH] = "0.280000";
  char str[MAX_LENGTH] = "cos(0.48) *     sqrt(x-0.04)  + asin(x) ^ 0.33 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(1.0944567) <= 0.00001, "test-20 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_21) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "2^3^4.4 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(6.9074441e37) <= 0.00001, "test-21 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_22) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] =
      "log(-0.20) ^ asin(-0.55) ()  ()  + asin(0.12) - 0.58 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_23) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "log(-0.20) ^ asin(-0.55)  + asin(0.12) - 0.58   =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_float_nan(result);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_24) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "log(0.20) * asin(-0.55)  + asin(0.12) +12.58   =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(13.6375689) <= 0.00001, "test-24 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_25) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "0.62 mod )  (0.97 ^ sin(-0.44) + 0.54 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_26) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "0.62 mod 1  (0.97 ^ sin(-0.44) + 0.54 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_27) {
  double result = 0;
  const char x[MAX_LENGTH] = "1.23.4";
  char str[MAX_LENGTH] = "2 mod 1 + (0.97 ^ sin(-0.44) + x =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_28) {
  double result = 0;
  const char x[MAX_LENGTH] = "1.234";
  char str[MAX_LENGTH] = "12.2 mod 2 + (0.97 ^ sin(-0.44)) + x =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(2.4470583) <= 0.00001, "test-28 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_29) {
  double result = 0;
  const char x[MAX_LENGTH] = "1.234";
  char str[MAX_LENGTH] = "12.2 mod 2 + (0.97 ^ sin(-0.44) + =x =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_30) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "asin(-0.04) *  (-0.68)  ^ -0.14 / -0.12 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_float_nan(result);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_31) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "asin(-0.04)) *  (-0.68)  ^ -0.14 / -0.12 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_32) {
  double result = 0;
  const char x[MAX_LENGTH] = "1234";
  char str[MAX_LENGTH] = "asin(-0.04) *  (x)  ^ -0.14 / (x/3) =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(-0.0000359) <= 0.00001, "test-32 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_33) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] =
      "log(tan(0.28)) / sqrt(0.26) / atan(0.04) / atan(0.18) mod log(0.59) =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(-0.3403307) <= 0.00001, "test-33 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_34) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] =
      "log(tan(0.28)) / ()sqrt(0.26) / atan(0.04) / atan(0.18) mod log(0.59) =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_35) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] =
      "log(tan(0.28)) / sqrt(-0.26) / atan(0.04) / atan(0.18) mod log(0.59) =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_float_nan(result);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_36) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] =
      "log(tan(0.28)) / sqrt(-0.26) / atan(0.04) / atan(0.18) mod =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_37) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "-0.58 ^ 0.97 ^  () 0.86 / 0.85 * -0.36 = =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_38) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "-0.58 ^ 0.97 ^ 0.86 / 0.85 * -0.36 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_float_nan(result);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_39) {
  double result = 0;
  const char x[MAX_LENGTH] = "12";
  char str[MAX_LENGTH] = "0.58 ^ 0.97 ^ 0.86 / x * -(x/0) =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_float_nan(result);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_40) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "0.58 ^ 0.97 ^ 0.86 / 0.85 * -0.36 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(-0.2491311) <= 0.00001, "test-40 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_41) {
  double result = 0;
  const char x[MAX_LENGTH] = "12";
  char str[MAX_LENGTH] = "0.58 ^ 0.97 ^ 0.86 / x * -(x/4.5) =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(-0.130717) <= 0.00001, "test-41 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_42) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "-0.93)  ( + 0.67  =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_43) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "(-0.93) + ( + 0.6712111)  =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(-0.2587889) <= 0.00001, "test-43 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_44) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "/tan(-0.32) / atan(0.17) =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_45) {
  double result = 0;
  const char x[MAX_LENGTH] = "0.014";
  char str[MAX_LENGTH] = "tan(-0.32) / atan(x) =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(-23.6722) <= 0.0001, "test-45 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_46) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "-0.98 mod cos(-0.69) * ( - ln(0.84))  =  ";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(0.0957548) <= 0.0001, "test-46 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_47) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "-0.98 mod cos(-0.69)  ( - ln(0.84)  =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_48) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] =
      "0.56 - acos(ln(0.74)) mod acos(log(-0.48)) - tan(-0.60)  =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_float_nan(result);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_49) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] =
      "0.56 - acos(ln(0.74)) mod acos(log(-0.48))) - tan(-0.60)  =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_50) {
  double result = 0;
  const char x[MAX_LENGTH] = "0.48";
  char str[MAX_LENGTH] =
      "        0.56 - acos(ln(0.74)) mod acos(log(x)) - tan(-0.60)  =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_msg(fabs(result) - fabs(1.7624331) <= 0.0001, "test-50 failed");
  ck_assert_int_eq(flag, OK);
}
END_TEST

START_TEST(test_s21_smart_calc_51) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "12.321  + 12 mod 0.0 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_float_nan(result);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_52) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] =
      "12."
      "321111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111+"
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111111111111111111111111111111=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_53) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "12.321  + 12 MOD 0.0 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_54) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "12.321 11.1 + 12 + 0.0 =";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_55) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "12.321 = 11.1 + 12 + 0.0";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_56) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "sin64.4)=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_57) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "++1=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_58) {
  double result = 0;
  const char x[MAX_LENGTH] = "0";
  char str[MAX_LENGTH] = "1+++1=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

START_TEST(test_s21_smart_calc_59) {
  double result = 0;
  const char x[MAX_LENGTH] = "12";
  char str[MAX_LENGTH] = "1x=";
  printf("----------START TEST FOR: %s, x = %s----------\n", str, x);
  int flag = s21_smart_calc(str, &result, x);
  ck_assert_double_eq(result, 0);
  ck_assert_int_eq(flag, ERROR);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc_core = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc_core);

  tcase_add_test(tc_core, test_s21_smart_calc_1);
  tcase_add_test(tc_core, test_s21_smart_calc_2);
  tcase_add_test(tc_core, test_s21_smart_calc_3);
  tcase_add_test(tc_core, test_s21_smart_calc_4);
  tcase_add_test(tc_core, test_s21_smart_calc_5);
  tcase_add_test(tc_core, test_s21_smart_calc_6);
  tcase_add_test(tc_core, test_s21_smart_calc_7);
  tcase_add_test(tc_core, test_s21_smart_calc_8);
  tcase_add_test(tc_core, test_s21_smart_calc_9);
  tcase_add_test(tc_core, test_s21_smart_calc_10);
  tcase_add_test(tc_core, test_s21_smart_calc_11);
  tcase_add_test(tc_core, test_s21_smart_calc_12);
  tcase_add_test(tc_core, test_s21_smart_calc_13);
  tcase_add_test(tc_core, test_s21_smart_calc_14);
  tcase_add_test(tc_core, test_s21_smart_calc_15);
  tcase_add_test(tc_core, test_s21_smart_calc_16);
  tcase_add_test(tc_core, test_s21_smart_calc_17);
  tcase_add_test(tc_core, test_s21_smart_calc_18);
  tcase_add_test(tc_core, test_s21_smart_calc_19);
  tcase_add_test(tc_core, test_s21_smart_calc_20);
  tcase_add_test(tc_core, test_s21_smart_calc_21);
  tcase_add_test(tc_core, test_s21_smart_calc_22);
  tcase_add_test(tc_core, test_s21_smart_calc_23);
  tcase_add_test(tc_core, test_s21_smart_calc_24);
  tcase_add_test(tc_core, test_s21_smart_calc_25);
  tcase_add_test(tc_core, test_s21_smart_calc_26);
  tcase_add_test(tc_core, test_s21_smart_calc_27);
  tcase_add_test(tc_core, test_s21_smart_calc_28);
  tcase_add_test(tc_core, test_s21_smart_calc_29);
  tcase_add_test(tc_core, test_s21_smart_calc_30);
  tcase_add_test(tc_core, test_s21_smart_calc_31);
  tcase_add_test(tc_core, test_s21_smart_calc_32);
  tcase_add_test(tc_core, test_s21_smart_calc_33);
  tcase_add_test(tc_core, test_s21_smart_calc_34);
  tcase_add_test(tc_core, test_s21_smart_calc_35);
  tcase_add_test(tc_core, test_s21_smart_calc_36);
  tcase_add_test(tc_core, test_s21_smart_calc_37);
  tcase_add_test(tc_core, test_s21_smart_calc_38);
  tcase_add_test(tc_core, test_s21_smart_calc_39);
  tcase_add_test(tc_core, test_s21_smart_calc_40);
  tcase_add_test(tc_core, test_s21_smart_calc_41);
  tcase_add_test(tc_core, test_s21_smart_calc_42);
  tcase_add_test(tc_core, test_s21_smart_calc_43);
  tcase_add_test(tc_core, test_s21_smart_calc_44);
  tcase_add_test(tc_core, test_s21_smart_calc_45);
  tcase_add_test(tc_core, test_s21_smart_calc_46);
  tcase_add_test(tc_core, test_s21_smart_calc_47);
  tcase_add_test(tc_core, test_s21_smart_calc_48);
  tcase_add_test(tc_core, test_s21_smart_calc_49);
  tcase_add_test(tc_core, test_s21_smart_calc_50);
  tcase_add_test(tc_core, test_s21_smart_calc_51);
  tcase_add_test(tc_core, test_s21_smart_calc_52);
  tcase_add_test(tc_core, test_s21_smart_calc_53);
  tcase_add_test(tc_core, test_s21_smart_calc_54);
  tcase_add_test(tc_core, test_s21_smart_calc_55);
  tcase_add_test(tc_core, test_s21_smart_calc_56);
  tcase_add_test(tc_core, test_s21_smart_calc_57);
  tcase_add_test(tc_core, test_s21_smart_calc_58);
  tcase_add_test(tc_core, test_s21_smart_calc_59);

  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf ? 1 : 0;
}
