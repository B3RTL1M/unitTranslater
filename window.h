#ifndef DEF_WINDOW
#define DEF_WINDOW

#include <QApplication>
#include <QWidget>
#include <QPushButton>

class Window : public QWidget
{
	public:
	Window();
	
	private:
	QPushButton *m_quitButton;
	QtabWidget *m_tabWidget;
}