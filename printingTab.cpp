#include "printingTab.h"

PrintingTab::PrintingTab(QWidget *parent)
    : QWidget(parent)
{
    // widgets
    m_distGroupBox = new QGroupBox("Distance", this);
    m_resGroupBox = new QGroupBox("Resolution", this);
    m_pxGroupBox = new QGroupBox("Pixels", this);

    m_dist_mm = new QLineEdit;
    m_dist_inch = new QLineEdit;
    m_res_dpi = new QLineEdit;
    m_res_mmpx = new QLineEdit;
    m_res_pxmm = new QLineEdit;
    m_px_px = new QLineEdit;
	
	m_dist_mm->setValidator(new QDoubleValidator(this));
	m_dist_inch->setValidator(new QDoubleValidator(this));
	m_res_dpi->setValidator(new QDoubleValidator(this));
	m_res_mmpx->setValidator(new QDoubleValidator(this));
	m_res_pxmm->setValidator(new QDoubleValidator(this));
	m_px_px->setValidator(new QIntValidator(this));
	
	QObject::connect(m_dist_mm, SIGNAL(textChanged()),this, SLOT(calculDistFromMm()));
	QObject::connect(m_dist_inch, SIGNAL(textChanged()),this, SLOT(calculDistFromInch()));
	QObject::connect(m_res_dpi, SIGNAL(textChanged()),this, SLOT(calculResFromDpi()));
	QObject::connect(m_res_mmpx, SIGNAL(textChanged()),this, SLOT(calculResFromMmpx()));
	QObject::connect(m_res_pxmm, SIGNAL(textChanged()),this, SLOT(calculResFromPxmm()));
	QObject::connect(m_px_px, SIGNAL(textChanged()),this, SLOT(calculPxFromPx()));

    // layout
    m_distLayout = new QFormLayout;
    m_distLayout->addRow("[mm]", m_dist_mm);
    m_distLayout->addRow("[inch]", m_dist_inch);

    m_resLayout = new QFormLayout;
    m_resLayout->addRow("[dpi]", m_res_dpi);
    m_resLayout->addRow("[mm/px]", m_res_mmpx);
    m_resLayout->addRow("[px/mm]", m_res_pxmm);

    m_pxLayout = new QFormLayout;
    m_pxLayout->addRow("[px]", m_px_px);

    m_distGroupBox->setLayout(m_distLayout);
    m_resGroupBox->setLayout(m_resLayout);
    m_pxGroupBox->setLayout(m_pxLayout);

    m_mainLayout = new QHBoxLayout;
    m_mainLayout->addWidget(m_distGroupBox);
    m_mainLayout->addWidget(m_resGroupBox);
    m_mainLayout->addWidget(m_pxGroupBox);
    this->setLayout(m_mainLayout);
}

void PrintingTab::recalculPx()
{
	Qstring resolution = m_res_pxmm->text();
	Qstring distance  = m_dist_mm->text();
	int result = round(distance.toDouble*resolution.toDouble);
	m_px_px->setText(QString::number(result));
}

void PrintingTab::recalculDist()
{
	Qstring resolution = m_res_mmpx->text();
	Qstring px  = m_px_px->text();
	double result = px.toDouble*resolution.toDouble;
	m_dist_mm->setText(QString::number(result));
}

void PrintingTab::calculDistFromMm()
{
	Qstring dist = m_dist_mm->text();
	double result = dist.toDouble/25.4;
	m_dist_inch->setText(QString::number(result));
	recalculPx();
}

void PrintingTab::calculDistFromInch()
{
	Qstring dist = m_dist_inch->text();
	double result = dist.toDouble*25.4;
	m_dist_mm->setText(QString::number(result));
	recalculPx();
}

void PrintingTab::calculResFromDpi()
{
	Qstring dpi = m_res_dpi->text();
	double mmpx = 25.4/dpi.toDouble;
	double pxmm = dpi.toDouble/25.4;
	m_res_mmpx->setText(QString::number(mmpx));
	m_res_pxmm->setText(QString::number(pxmm));
	recalculPx();
}

void PrintingTab::calculResFromMmpx()
{
	Qstring mmpx = m_res_mmpx->text();
	double dpi = 25.4/mmpx.toDouble;
	double pxmm = dpi/25.4;
	m_res_dpi->setText(QString::number(dpi));
	m_res_pxmm->setText(QString::number(pxmm));
	recalculPx();
}

void PrintingTab::calculResFromPxmm()
{
	Qstring pxmm = m_res_pxmm->text();
	double dpi = pxmm.toDouble*25.4;
	double mmpx = 25.4/dpi.toDouble;
	m_res_mmpx->setText(QString::number(mmpx));
	m_res_dpi->setText(QString::number(dpi));
	recalculPx();
}

void PrintingTab::calculPxFromPx()
{
	recalculDist();
}