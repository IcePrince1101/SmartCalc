#include "mainwindow.h"

#include "ui_mainwindow.h"

int flag_input = 0, flag_change_x = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(input_char()));

  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(input_char()));

  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(input_func()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(input_func()));

  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(input_char()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(input_char()));

  connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this,
          SLOT(input_char()));
  connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this,
          SLOT(input_char()));

  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(input_char()));

  connect(ui->pushButton_ac, SIGNAL(clicked()), this, SLOT(delete_all()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(equal()));
  connect(ui->pushButton_plot, SIGNAL(clicked()), this, SLOT(build_plot()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::input_char() {
  if (flag_input == 0) clear();
  flag_input = 1;
  // Получаем ту кнопку, которая нажата
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->label_result->text() + button->text();
  ui->label_result->setText(new_label);
}

void MainWindow::input_func() {
  if (flag_input == 0) clear();
  flag_input = 1;
  QPushButton *button = (QPushButton *)sender();
  QString new_label = ui->label_result->text() + button->text() + "(";
  ui->label_result->setText(new_label);
}

void MainWindow::equal() {
  flag_input = 0;
  flag_change_x = 0;
  double result = 0;
  char str[MAX_LENGTH] = {0};
  QPushButton *button = (QPushButton *)sender();
  QString label = ui->label_result->text() + button->text();
  QByteArray arr = label.toLocal8Bit();
  memcpy(str, arr.data(), arr.size());
  QString x = ui->textEdit_x->toPlainText();
  QByteArray arr_x = x.toLocal8Bit();
  if (arr_x.size() == 0) {
    ui->label_result->setText("Не задано значение х!");
    flag_input = 0;
  } else {
    char x_str[MAX_LENGTH] = {0};
    memcpy(x_str, arr_x.data(), arr_x.size());
    if (s21_smart_calc(str, &result, x_str) == 0) {
      QString res = QString::number(result, 'g', 10);
      ui->label_result->setText(res);
    } else {
      if (std::isnan(result))
        ui->label_result->setText("nan");
      else
        ui->label_result->setText("Неверный ввод!");
      flag_input = 0;
    }
  }
}

void MainWindow::build_plot() {
  bool x_min_ok, x_max_ok, y_min_ok, y_max_ok;
  double x_min = ui->lineEdit_x_min->text().toDouble(&x_min_ok);
  double x_max = ui->lineEdit_x_max->text().toDouble(&x_max_ok);
  double y_min = ui->lineEdit_y_min->text().toDouble(&y_min_ok);
  double y_max = ui->lineEdit_y_max->text().toDouble(&y_max_ok);
  if (!x_min_ok || !x_max_ok || !y_min_ok || !y_max_ok) {
    printf("%f\n", x_min + x_max + y_min + y_max);
    ui->label_result->setText("Неверный ввод!");
    flag_input = 0;
  } else {
    char str[MAX_LENGTH] = {0};
    char x_str[MAX_LENGTH] = "0";
    QString label = ui->label_result->text() + '=';
    QByteArray arr = label.toLocal8Bit();
    memcpy(str, arr.data(), arr.size());
    char tmp[MAX_LENGTH] = {0};
    memcpy(tmp, str, MAX_LENGTH);
    char output[255][MAX_LENGTH];
    int count = 0;
    if (x_min < -1000000 || x_max > 1000000 || y_min < -1000000 ||
        y_max > 1000000 || x_min >= x_max || y_min >= y_max ||
        s21_check_string(tmp, x_str) == 1 ||
        s21_reverse_polish_notation(tmp, output, &count) == 1) {
      ui->label_result->setText("Неверный ввод!");
    } else {
      form.Graph(str, x_min, x_max, y_min, y_max);
      form.setWindowTitle("График");
      form.show();
    }
    flag_input = 0;
  }
}

void MainWindow::change_x() {
  if (flag_change_x == 0) {
    QString label;
    ui->textEdit_x->setText(label);
  }
  flag_change_x = 1;
}

void MainWindow::delete_all() {
  QString label = "0";
  ui->label_result->setText(label);
  flag_input = 0;
}

void MainWindow::clear() {
  QString label;
  ui->label_result->setText(label);
}
