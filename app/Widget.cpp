#include "Widget.h"
#include "ui_Widget.h"
#include <QApplication>
#include <QDebug>
#include <QTranslator>

Widget::Widget(QWidget *parent) : QWidget(parent), UI(new Ui::Widget) {
    UI->setupUi(this);
    UI->retranslateUi(this);
}

void Widget::exitApp() {
    qDebug() << tr("About to exit app");
    QApplication::exit();
}

void Widget::applyEnglishLang(bool enable) {
    if (!enable) return;
    applyLang(0);
}

void Widget::applyChineseLang(bool enable) {
    if (!enable) return;
    applyLang(1);
}

void Widget::applyLang(int langId) {
    QTranslator translator;
    auto qm = langId == 0 ? "app_en.qm" : "app_zh.qm";
    Q_UNUSED(translator.load(qm));
    qApp->installTranslator(&translator);

    UI->retranslateUi(this);
}
