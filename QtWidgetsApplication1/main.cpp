#include <QtWidgets>

int main(int argc, char* argv[]) {
    QApplication* app = new QApplication(argc, argv);

    QWidget* mainWindow = new QWidget();
    QPushButton* mainButton = new QPushButton("Open Dialog", mainWindow);
    mainButton->move(mainWindow->width() / 2 - mainButton->width() / 2,
        mainWindow->height() / 2 - mainButton->height() / 2);

    QWidget* dialog = new QWidget();
    dialog->hide();
    QPushButton* dialogButton = new QPushButton("Create File", dialog);
    dialogButton->move(dialog->width() / 2 - dialogButton->width() / 2,
        dialog->height() / 2 - dialogButton->height() / 2);

    QObject::connect(mainButton, &QPushButton::clicked, [=]() {
        dialog->show();
        });

    QObject::connect(dialogButton, &QPushButton::clicked, [=]() {
        QFile file("output.txt");
        file.open(QIODevice::WriteOnly);

        QTextStream stream(&file);

        QTextCodec* codec = QTextCodec::codecForName("Windows-1252");
        stream.setCodec(codec);

        stream << "Миру мир!";

        file.close();
        app->quit();
    });

    mainWindow->show();

    return app->exec();
}