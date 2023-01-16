#include "kmdwidget.h"
#include "kmdedit.h"
#include <QVBoxLayout>


KMDWidget::KMDWidget(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout* vBox = new QVBoxLayout(this);
	KMDEdit* mdEdit = new KMDEdit(this);

	vBox->addWidget(mdEdit);

	this->setLayout(vBox);
}

KMDWidget::~KMDWidget()
{
}

