#pragma once

#include <cstddef>

#include <QKeyEvent>
#include <QLineEdit>
#include <QWidget>

#include "keyboard.hpp"

namespace biv {
	class KeyBoardWindow : public QWidget {
			Q_OBJECT
		private:
			QLineEdit* display;
			KeyBoard* keyboard;

		public:
			KeyBoardWindow(QWidget* parent = nullptr);

		public slots:
			void keyClickedEvent(int code);
			
		protected:
			void keyPressEvent(QKeyEvent* event) override;
	};
}
