#ifndef DEF_WINDOW
#define DEF_WINDOW

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTabWidget>
#include <QGridLayout>

class Window : public QWidget
{
	public:
    Window();
	
	private:
	QPushButton *m_quitButton;
    QTabWidget *m_tabWidget;
    QGridLayout *m_layout;
};
#endif
