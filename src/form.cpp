#include "form.h"

#include "ui_form.h"

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form) {
  ui->setupUi(this);
}

Form::~Form() { delete ui; }

void Form::Graph(char str[3000], double x_min, double x_max, double y_min,
                 double y_max) {
  ui->widget->clearGraphs();  // удаление графика
  x.clear();
  y.clear();

  x_begin = x_min;
  x_end = x_max;
  ui->widget->xAxis->setRange(x_min, x_max);
  ui->widget->yAxis->setRange(y_min, y_max);

  h = (x_end - x_begin) / 100;
  N = (x_end - x_begin) / h + 2;
  char tmp_str[3000] = {0};
  memcpy(tmp_str, str, 3000);
  for (x_tmp = x_begin; x_tmp <= x_end; x_tmp += h) {
    x.push_back(x_tmp);
    char string_x[3000] = {0};
    memcpy(string_x, std::to_string(x_tmp).c_str(),
           std::to_string(x_tmp).size());
    double tmp_result = 0;
    int tmp_flag = s21_smart_calc(str, &tmp_result, string_x);
    memcpy(str, tmp_str, 3000);
    if (tmp_flag == 1)
      x.pop_back();
    else
      y.push_back(tmp_result);
  }

  ui->widget->addGraph();               // добавление графика
  ui->widget->graph(0)->addData(x, y);  // установка значений графика
  ui->widget->replot();                 // рисование графика
}