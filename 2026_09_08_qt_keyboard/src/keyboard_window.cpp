#include "keyboard_window.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

#include <iostream>

using biv::KeyBoardWindow;

KeyBoardWindow::KeyBoardWindow(QWidget* parent) : QWidget(parent) {
	const int keyboard_width = 1160;
	resize(keyboard_width, 710);
    setWindowTitle("Весёлая Клавиатура");
	
	QPixmap pixmap("img/veseli_smail.png");
	QLabel* image = new QLabel(this);
	image->setFixedSize(200, 200);
	image->setPixmap(pixmap);
	image->setScaledContents(true);
	
	QHBoxLayout* smail_layout = new QHBoxLayout();
	smail_layout->addWidget(image);

    display = new QLineEdit();
	display->setMinimumHeight(80);
	display->setFont(QFont("Roboto", 40));
    display->setReadOnly(true);
  display->setFocusPolicy(Qt::NoFocus);
	display->setText("Я работаю лучше!");

	keyboard = new KeyBoard(keyboard_width);
	connect(keyboard, &KeyBoard::key_pressed, this, &KeyBoardWindow::keyClickedEvent);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
	main_layout->addLayout(smail_layout);
    main_layout->addWidget(display);
    main_layout->addWidget(keyboard);
}

void KeyBoardWindow::keyClickedEvent(const int key) {
	handle_key_interaction(key);
}


void KeyBoardWindow::handle_key_interaction(const int key) {
	if (keyboard->is_key_allowed(key)) {
		QString text = display->text();
		if (key == 16777220) {
			display->setText("");
			return;
		} else if (key == Qt::Key_Space) {
			display->setText(text + " ");
			return;
		} else if (key == Qt::Key_Backspace) {
			text.chop(1);
			display->setText(text);
			return;
		}
		display->setText(display->text() + keyboard->get_key_text(key));
	}
}


void KeyBoardWindow::keyPressEvent(QKeyEvent* event) {
	const int key = event->key();
	handle_key_interaction(key);
}
