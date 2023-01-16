#include "kmdrange.h"

#include <QDebug>

namespace
{
	constexpr int NormalFontSize = 22;
	constexpr int Heading1FontSize = 48;
	constexpr int Heading2FontSize = 32;
	constexpr int Heading3FontSize = 28;
	constexpr int Heading4FontSize = 22;
	constexpr int CodeFontSize = 10;
}

//这个结构体，可以带一些数据结构
class KTextBlockData : public QTextBlockUserData
{
public:
	enum class MDBlockType
	{
		NormalText = 0,
		Heading1 = 1,
		Heading2 = 2,
		Heading3 = 3,
		Heading4 = 4,
		Code = 5,
		Image = 6,
	};
	KTextBlockData(int type)
	{
		m_type = type;
	}
	virtual ~KTextBlockData()
	{

	}

	int m_type = 1;
};


KMDRange::KMDRange(QObject *parent)
	: QObject(parent)
{

}

KMDRange::KMDRange(QTextCursor* textCursor, QTextBlock* textBlock) : m_textCursor(textCursor), m_textBlock(textBlock)
{
}

KMDRange::~KMDRange()
{
}

bool KMDRange::InitRange()
{
	if (m_textBlock == nullptr || m_textCursor == nullptr)
		return false;

	QTextBlockUserData* userData = m_textBlock->userData();
	KTextBlockData* kUserData = static_cast<KTextBlockData*>(userData);
	if (kUserData != nullptr)
	{
		qDebug() << "test---" << kUserData->m_type;
	}
	int nPosition = m_textCursor->position();
	int npositionInBlock = m_textCursor->positionInBlock();

	if (m_textCursor->positionInBlock() == 2 && m_textBlock->text().startsWith("# "))
	{
		KTextBlockData* userData = new KTextBlockData(2);
		m_textBlock->setUserData(userData);

		m_textCursor->beginEditBlock(); // 这个东西是合并事务的
		int nBlock = m_textBlock->position();
		int nTextCur = m_textCursor->position();
		m_textCursor->setPosition(m_textBlock->position());
//		m_textCursor->setPosition(m_textBlock->position() + 1, QTextCursor::KeepAnchor);
		m_textCursor->select(QTextCursor::BlockUnderCursor);
//		m_textCursor->movePosition(QTextCursor::StartOfBlock, QTextCursor::MoveAnchor);
		m_textCursor->removeSelectedText();
		m_textCursor->endEditBlock();

		QFont font;
		font.setBold(true);
		font.setPixelSize(10);

		QTextCharFormat charFormat = m_textCursor->charFormat();
		charFormat.setFont(font);
		
		m_textCursor->setBlockCharFormat(charFormat);
		m_textCursor->setPosition(0);

	}

	return false;
}

