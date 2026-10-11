#include <QApplication>

#include "welcome_window.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
	
    biv::WelcomeWindow welcome_window;
    welcome_window.show();

    return app.exec();
}
