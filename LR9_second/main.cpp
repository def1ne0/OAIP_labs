#include <QApplication>
#include "src/MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Настраиваем стиль
    app.setStyle("Fusion");

    MainWindow window;
    window.show();

    return app.exec();
}