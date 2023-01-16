#include "kmdedit.h"

#include <QTextCursor>
#include <QTextDocument>
#include <QTextBlock>
#include <QTextLayout>
#include <QAbstractTextDocumentLayout>

#include "kmdrange.h"
#if _DEBUG
#include <QDebug>
#endif


KMDEdit::KMDEdit(QWidget *parent)
	: QTextEdit(parent)
{
	m_doc = this->document();

	connect(this, &QTextEdit::textChanged, this, &KMDEdit::onDealInput);
	connect(m_doc, &QTextDocument::blockCountChanged, this, &KMDEdit::onBlockChange);

	_init();
	setFocus();
	setFocusPolicy(Qt::StrongFocus);
//	insertPlainText("123");
}

void KMDEdit::_init()
{
// 	QTextCursor textCursor = this->textCursor();
// 	QTextCharFormat charFormat = _getNormalFormat();
// 	textCursor.select(QTextCursor::BlockUnderCursor);
// 	textCursor.setBlockCharFormat(charFormat);
// 	textCursor.setPosition(0);

	QFont font;
	font.setBold(false);
	font.setPixelSize(22);

	m_doc->setDefaultFont(font);
}

KMDEdit::~KMDEdit()
{
}

void KMDEdit::inputMethodEvent(QInputMethodEvent*e)
{
	//�������Ŀǰֻ���յ������뷨�ķ�����Ŀǰ����̫���С����Ժ��Ե�
	QString str = e->commitString();
	QString str1 = e->preeditString();
	qDebug() << str << str1;
	return QTextEdit::inputMethodEvent(e);
}

void KMDEdit::onInputEnter()
{

}

// ���ﴦ�����еĻس���
/*
markdown�������ʱ���м���case
1. �����б����س����Ļ�ԭ��ԭʼ״̬

*/


void KMDEdit::onBlockChange(int newIndex)
{
	QTextBlock curBlock = m_doc->findBlockByNumber(newIndex);
	QTextBlockFormat blockFormat = curBlock.blockFormat();
	int index = blockFormat.headingLevel();

	QTextCursor textCursor = this->textCursor();

	QTextCharFormat charFormat;

	QFont font;
	font.setBold(false);
	font.setPixelSize(22);
	charFormat.setFont(font);

	textCursor.select(QTextCursor::BlockUnderCursor);
	textCursor.setBlockCharFormat(charFormat);
	qDebug() << index;
}

void KMDEdit::onDealInput()
{
	QTextCursor textCursor = this->textCursor();
	QTextBlock curTextBlock = textCursor.block();

	KMDRange range(&textCursor, &curTextBlock);
	range.InitRange();

	this->setTextCursor(textCursor);

	//���Դ����Զ�������
}

void KMDEdit::testOutAllBlock() 
{
	QTextFrame* frame = m_doc->rootFrame();
	auto f = frame->begin();
	for (auto iter = f; f != frame->end(); f++)
	{
		QTextBlock textBlock = f.currentBlock();
		qDebug() << textBlock.text();
	}
}
