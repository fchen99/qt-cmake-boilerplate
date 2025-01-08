#include "Widget.h"
#include <QApplication>
#include <controls/Slider.h>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    app.setStyle("fusion");

    Widget w;
    w.show();

    return QApplication::exec();
}