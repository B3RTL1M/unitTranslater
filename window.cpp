#include "window.h"
#include "printingTab.h"

Window::Window() : QWidget()
{	
	// quitButton description
	m_quitButton = new QPushButton(this);
	m_quitButton->setText("Quit");
    m_quitButton->setToolTip("Quit the application");
	
	// tab group description
    m_tabWidget = new QTabWidget(this);
    m_tabWidget->addTab(new PrintingTab(m_tabWidget), "Printing");
	
    // layout
    m_layout = new QGridLayout;
    m_layout->addWidget(m_tabWidget,0,0,4,0);
    m_layout->addWidget(m_quitButton,4,1);

    this->setLayout(m_layout);

	// signal connection
	QObject::connect(m_quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}
