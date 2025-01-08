#include "Widget.h"
#include "ui_Widget.h"
#include <QApplication>
#include <QDebug>
#include <QTranslator>

Widget::Widget(QWidget *parent) : QWidget(parent), UI(new Ui::Widget) {
    UI->setupUi(this);
    UI->retranslateUi(this);

    UI->toolButton->addAction(tr("User manual"));
    UI->toolButton->addAction(tr("Help"));
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

    // 非 .ui 上的文本需要自行处理语言切换。
    // 在 .ts 文件中，出现多次的翻译，只会添加一条，并纪录其出现的多个位置。
    UI->toolButton->actions()[0]->setText(tr("User manual"));
    UI->toolButton->actions()[1]->setText(tr("Help"));
}
