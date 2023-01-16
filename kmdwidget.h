#ifndef K_MD_WIDGET
#define K_MD_WIDGET

#include <QWidget>

class KMDWidget : public QWidget
{
	Q_OBJECT

public:
	KMDWidget(QWidget *parent = nullptr);
	~KMDWidget();
};
#endif // K_MD_WIDGET
