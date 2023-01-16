#ifndef K_MD_EDIT
#define K_MD_EDIT

#include <QTextEdit>

class QTextDocument;

class KMDEdit : public QTextEdit
{
	Q_OBJECT
public:
	KMDEdit(QWidget *parent = nullptr);
	~KMDEdit();

	enum class BlockType
	{
		Normal = 0,
		Heading1 = 1
	};
public:
	virtual void inputMethodEvent(QInputMethodEvent*);

 private:
	void _init();

	void testOutAllBlock();


Q_SIGNALS:
	void inputEnter();

public slots:
	void onDealInput();
	void onInputEnter();
	void onBlockChange(int newIndex);

private:
	QTextDocument* m_doc = nullptr;
};
#endif // K_MD_EDIT
