#ifndef DEF_PRINTINGTAB
#define DEF_PRINTINGTAB

#include <QApplication>
#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QDoubleValidator>
#include <math.h>

class PrintingTab : public QWidget
{
	Q_OBJECT
	
	public:
    PrintingTab(QWidget *parent = 0);
	
	protected:
	void recalculPx();
	void recalculDist();
	
	public slots:
	void calculDistFromMm();
	void calculDistFromInch();
	void calculResFromDpi();
	void calculResFromMmpx();
	void calculResFromPxmm();
	void calculPxFromPx();
	
	private:
    QGroupBox *m_distGroupBox;
    QGroupBox *m_resGroupBox;
    QGroupBox *m_pxGroupBox;

    QLineEdit *m_dist_mm;
    QLineEdit *m_dist_inch;
    QLineEdit *m_res_dpi;
    QLineEdit *m_res_mmpx;
    QLineEdit *m_res_pxmm;
    QLineEdit *m_px_px;

    QHBoxLayout *m_mainLayout;
    QFormLayout *m_distLayout;
    QFormLayout *m_resLayout;
    QFormLayout *m_pxLayout;
};
#endif
