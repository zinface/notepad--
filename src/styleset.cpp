#include "styleset.h"
#include "ccnotepad.h"
#include <QFile>
#include <QPalette>
#include <QApplication>
#include <QDebug>


QColor StyleSet::foldfgColor(0xe9, 0xe9, 0xe9, 100);
QColor StyleSet::foldbgColor(0xff, 0xff, 0xff);
QColor StyleSet::marginsBackgroundColor(0xf0f0f0);
QColor StyleSet::bookmarkBkColor(0xececec);

int StyleSet::m_curStyleId = 0;

StyleSet::StyleSet()
{}

StyleSet::~StyleSet()
{}

void StyleSet::setCommonStyle(QColor foldfgColor_, QColor foldbgColor_, QColor marginsBackgroundColor_, QString colorName)
{
	foldfgColor = foldfgColor_;
	foldbgColor = foldbgColor_;
	marginsBackgroundColor = marginsBackgroundColor_;

	QFile file(":/qss/lightbluestyle.qss"); //qss文件路径:/lightblue.qss
	QString styleSheet;
	if (file.open(QIODevice::Text | QIODevice::ReadOnly))
	{
		styleSheet = file.readAll();
		QPalette palette;
		palette.setColor(QPalette::Window, foldbgColor_);
		palette.setColor(QPalette::Base, foldbgColor_);
		palette.setColor(QPalette::Button, foldbgColor_);
		qApp->setPalette(palette);
		if (colorName != "#EAF7FF")
		{
			styleSheet.replace("#EAF7FF", colorName);
		}
		qApp->setStyleSheet(styleSheet);
	}
	file.close();
}

//void StyleSet::setBlackStyle()
//{
//	foldfgColor = QColor(57,58,60);
//	foldbgColor = QColor(57, 58, 60);
//	marginsBackgroundColor = QColor(57, 58, 60);
//
//	QFile file(":/qss/black.qss"); //qss文件路径:/lightblue.qss
//	QString styleSheet;
//	if (file.open(QIODevice::Text | QIODevice::ReadOnly))
//	{
//		QPalette palette;
//		palette.setColor(QPalette::Window, foldfgColor);
//		palette.setColor(QPalette::Base, foldbgColor);
//		palette.setColor(QPalette::Button, foldbgColor); 
//		//palette.setColor(QPalette::WindowText, QColor(0xff, 0xff, 0xff));
//		qApp->setPalette(palette);
//
//		styleSheet = file.readAll();
//		//styleSheet.replace("#EAF7FF", "0x394041");
//
//		qApp->setStyleSheet(styleSheet);
//	}
//	file.close();
//}

void StyleSet::setSkin(int id)
{
	switch (id)
	{
	case DEFAULT_SE:
		setDefaultStyle();
		break;
	case LIGHT_SE:
		setLightStyle();
		break;
	case THIN_BLUE_SE:
		setThinBlueStyle();
		break;
	case THIN_YELLOW_SE:
		setThinYellowStyle();
		break;
	case RICE_YELLOW_SE:
		setRiceYellowStyle();
		break;
	case SILVER_SE:
		setSilverStyle();
		break;
	case LAVENDER_SE:
		setLavenderBlushStyle();
		break;
	case MISTYROSE_SE:
		setMistyRoseStyle();
		break;
	default:
		id = 0;
		setDefaultStyle();
		break;
	}

	m_curStyleId = id;
}

void StyleSet::setDefaultStyle()
{
	m_curStyleId = DEFAULT_SE;

	foldfgColor = QColor(0xe9, 0xe9, 0xe9, 100);
	foldbgColor = QColor(0xff, 0xff, 0xff);
	marginsBackgroundColor = QColor(0xf0f0f0);
	bookmarkBkColor = QColor(0xececec);

	QFile file(":/qss/mystyle.qss"); //qss文件路径:/lightblue.qss
	QString styleSheet;
	if (file.open(QIODevice::Text | QIODevice::ReadOnly))
	{
		styleSheet = file.readAll();
		QPalette palette;
		palette.setColor(QPalette::Window, QColor(0xf0, 0xf0, 0xf0));
		palette.setColor(QPalette::Base, QColor(0xff, 0xff, 0xff));
		palette.setColor(QPalette::Button, QColor(0xf0, 0xf0, 0xf0));
		qApp->setPalette(palette);
		qApp->setStyleSheet(styleSheet);
	}
	file.close();
}

void StyleSet::setLightStyle()
{
	m_curStyleId = LIGHT_SE;
	bookmarkBkColor = QColor(0xE0F3Fc);
	setCommonStyle(QColor(0xea, 0xf7, 0xff, 100), QColor(0xeaf7ff), QColor(0xeaf7ff), "#EAF7FF");
}

void StyleSet::setThinBlueStyle()
{
	m_curStyleId = THIN_BLUE_SE;
	bookmarkBkColor = QColor(0xE3e0F0);
	setCommonStyle(QColor(0xd7, 0xe3, 0xf4, 100), QColor(0xd7e3f4), QColor(0xd7e3f4), "#D7E3F4");
}

//纸黄
void StyleSet::setThinYellowStyle()
{
	m_curStyleId = THIN_YELLOW_SE;
	bookmarkBkColor = QColor(0xF4F0E0);
	setCommonStyle(QColor(0xf9, 0xf0, 0xe1, 100), QColor(0xf9f0e1), QColor(0xf9f0e1), "#F9F0E1");
}

//宣纸黄
void StyleSet::setRiceYellowStyle()
{
	m_curStyleId = RICE_YELLOW_SE;
	bookmarkBkColor = QColor(0xF0F0E8);
	setCommonStyle(QColor(0xf6, 0xf3, 0xea, 100), QColor(0xf6f3ea), QColor(0xf6f3ea), "#F6F3EA");
}

//银色
void StyleSet::setSilverStyle()
{
	m_curStyleId = SILVER_SE;
	bookmarkBkColor = QColor(0xE4E4E4);
	setCommonStyle(QColor(0xe9, 0xe8, 0xe4, 100), QColor(0xe9e8e4), QColor(0xe9e8e4), "#E9E8E4");
}

//谈紫色#FFF0F5
void StyleSet::setLavenderBlushStyle()
{
	m_curStyleId = LAVENDER_SE;
	bookmarkBkColor = QColor(0xFCF0F0);
	setCommonStyle(QColor(0xff, 0xf0, 0xf5, 100), QColor(0xFFF0F5), QColor(0xFFF0F5), "#FFF0F5");
}

//MistyRose
void StyleSet::setMistyRoseStyle()
{
	m_curStyleId = MISTYROSE_SE;
	bookmarkBkColor = QColor(0xFCE0E0);
	setCommonStyle(QColor(0xff, 0xe4, 0xe1, 100), QColor(0xFFE4E1), QColor(0xFFE4E1), "#FFE4E1");
}
