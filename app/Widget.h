#pragma once

#include <QWidget>

namespace Ui {
class Widget;
}// namespace Ui

class Widget : public QWidget {
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() = default;

private slots:
    void exitApp();

private:
    Ui::Widget *UI;
};