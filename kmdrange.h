#ifndef K_MD_RANGE
#define K_MD_RANGE

#include <QObject>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextBlock>

class KMDRange : public QObject
{
	Q_OBJECT
public:
	KMDRange(QObject *parent = nullptr);
	KMDRange(QTextCursor* textCursor = nullptr, QTextBlock* textBlock = nullptr);
	~KMDRange();

public:
	bool InitRange();
	QTextCursor* test() { return m_textCursor; }

private:
	QTextCursor* m_textCursor = nullptr;
	QTextBlock* m_textBlock = nullptr;
};
#endif // K_MD_WIDGET
