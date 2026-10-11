#include "welcome_window.hpp"
#include "keyboard_window.hpp"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

using biv::WelcomeWindow;

WelcomeWindow::WelcomeWindow(QWidget* parent) : QWidget(parent) {
    setWindowTitle("Добро пожаловать");
    resize(400, 300);

    QLabel* greeting = new QLabel("Привет! Это весёлая клавиатура!", this);
    greeting->setFont(QFont("Roboto", 20));
    greeting->setAlignment(Qt::AlignCenter);
    greeting->setWordWrap(true);

    QPushButton* go_button = new QPushButton("Перейти к клавиатуре", this);
    go_button->setFont(QFont("Roboto", 16));

    connect(go_button, &QPushButton::clicked, this, [this]() {
        KeyBoardWindow* keyboard_window = new KeyBoardWindow();
        keyboard_window->setAttribute(Qt::WA_DeleteOnClose);
        keyboard_window->show();
        this->close();
    });

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addStretch();
    layout->addWidget(greeting);
    layout->addSpacing(20);
    layout->addWidget(go_button, 0, Qt::AlignCenter);
    layout->addStretch();
}
