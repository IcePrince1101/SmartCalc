#ifndef FORM_H
#define FORM_H

#include <QVector>
#include <QWidget>

#include "qcustomplot.h"

extern "C" {
#include "s21_smart_calc.h"
}

namespace Ui {
class Form;
}

class Form : public QWidget {
  Q_OBJECT

 public:
  explicit Form(QWidget *parent = nullptr);
  ~Form();
  void Graph(char str[3000], double x_min, double x_max, double y_min,
             double y_max);

 private:
  Ui::Form *ui;
  double x_begin, x_end, h, x_tmp;
  int N;  // количество точек
  QVector<double> x, y;
};

#endif  // FORM_H
