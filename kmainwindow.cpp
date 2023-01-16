#include "kmainwindow.h"
#include "kmdwidget.h"

KMainWindow::KMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	KMDWidget* kmd = new KMDWidget(this);
	setCentralWidget(kmd);
	resize(800, 800);
}

KMainWindow::~KMainWindow()
{
}

