#include "Window.h"

#include <QVBoxLayout>
#include <QPushButton>

Window::Window() {
    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    QPushButton* button = new QPushButton();
    button->setText("Hello");
    layout->addWidget(button);
    widget->setLayout(layout);
    setCentralWidget(widget);
}
