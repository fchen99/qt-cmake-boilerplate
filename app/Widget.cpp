#include "Widget.h"
#include "ui_Widget.h"
#include <QApplication>

Widget::Widget(QWidget *parent) : QWidget(parent), UI(new Ui::Widget) { UI->setupUi(this); }

void Widget::exitApp() { QApplication::exit(); }
