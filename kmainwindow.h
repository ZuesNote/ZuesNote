#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class KMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	KMainWindow(QWidget *parent = nullptr);
	~KMainWindow();
};
#endif // MAINWINDOW_H
