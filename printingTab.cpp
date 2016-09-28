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
