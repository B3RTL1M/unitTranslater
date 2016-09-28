#include "window.h"

Window::Window() : QWidget()
{
	setFixedSize(200,100);
	
	// quitButton description
	m_quitButton = new QPushButton(this);
	m_quitButton->setText("Quit");
	m_quitButton->setToolTip("Quit the application")
	
	// tab group description
	m_tabWidget = new QTabWidget(this);
	m_tabWidget->addTab(new PrintingTab(m_tabWidget), "Printing");
	
	// signal connection
	QObject::connect(m_quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}