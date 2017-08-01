/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sat 5. Nov 08:20:46 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QCalendarWidget *calendarWidget;
    QTableWidget *tableWidget;
    QPushButton *neweventbutton;
    QTextEdit *textEdit;
    QCheckBox *completedcheckbox;
    QPushButton *saveeditbutton;
    QDateEdit *dateEdit;
    QSlider *horizontalSlider;
    QPushButton *finishbutton;
    QPushButton *deletebutton;
    QLabel *labelcurrentday;
    QCheckBox *entercheckbox;
    QPushButton *todaybutton;
    QPushButton *yesterdaybutton;
    QPushButton *tomorrowbutton;
    QPushButton *nextweekbutton;
    QLineEdit *searchtext;
    QPushButton *searchbutton;
    QLabel *informationlabel;
    QLabel *messageidlabel;
    QPushButton *gotoday;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 440);
        Widget->setMinimumSize(QSize(800, 440));
        Widget->setMaximumSize(QSize(800, 440));
        calendarWidget = new QCalendarWidget(Widget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 20, 231, 181));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Narrow"));
        font.setPointSize(10);
        calendarWidget->setFont(font);
        calendarWidget->setMouseTracking(false);
        calendarWidget->setMinimumDate(QDate(2011, 8, 1));
        calendarWidget->setMaximumDate(QDate(2199, 12, 31));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(true);
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::ISOWeekNumbers);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);
        tableWidget = new QTableWidget(Widget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(250, 20, 431, 320));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(12);
        tableWidget->setFont(font1);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setRowCount(1);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(false);
        neweventbutton = new QPushButton(Widget);
        neweventbutton->setObjectName(QString::fromUtf8("neweventbutton"));
        neweventbutton->setGeometry(QRect(10, 210, 231, 121));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(14);
        neweventbutton->setFont(font2);
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(250, 340, 431, 100));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(10);
        textEdit->setFont(font3);
        completedcheckbox = new QCheckBox(Widget);
        completedcheckbox->setObjectName(QString::fromUtf8("completedcheckbox"));
        completedcheckbox->setGeometry(QRect(590, 0, 111, 18));
        completedcheckbox->setFont(font3);
        saveeditbutton = new QPushButton(Widget);
        saveeditbutton->setObjectName(QString::fromUtf8("saveeditbutton"));
        saveeditbutton->setGeometry(QRect(690, 330, 101, 81));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(18);
        saveeditbutton->setFont(font4);
        dateEdit = new QDateEdit(Widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(690, 300, 101, 25));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        dateEdit->setFont(font5);
        dateEdit->setFrame(true);
        dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit->setMaximumDate(QDate(2099, 12, 31));
        dateEdit->setMinimumDate(QDate(2011, 8, 1));
        dateEdit->setCalendarPopup(false);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(690, 280, 101, 10));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(5);
        horizontalSlider->setPageStep(25);
        horizontalSlider->setOrientation(Qt::Horizontal);
        finishbutton = new QPushButton(Widget);
        finishbutton->setObjectName(QString::fromUtf8("finishbutton"));
        finishbutton->setGeometry(QRect(690, 230, 101, 41));
        finishbutton->setFont(font1);
        deletebutton = new QPushButton(Widget);
        deletebutton->setObjectName(QString::fromUtf8("deletebutton"));
        deletebutton->setGeometry(QRect(10, 415, 21, 21));
        deletebutton->setFont(font5);
        labelcurrentday = new QLabel(Widget);
        labelcurrentday->setObjectName(QString::fromUtf8("labelcurrentday"));
        labelcurrentday->setGeometry(QRect(250, 0, 321, 21));
        labelcurrentday->setFont(font2);
        labelcurrentday->setAlignment(Qt::AlignCenter);
        entercheckbox = new QCheckBox(Widget);
        entercheckbox->setObjectName(QString::fromUtf8("entercheckbox"));
        entercheckbox->setGeometry(QRect(690, 420, 101, 18));
        entercheckbox->setFont(font3);
        entercheckbox->setChecked(true);
        todaybutton = new QPushButton(Widget);
        todaybutton->setObjectName(QString::fromUtf8("todaybutton"));
        todaybutton->setGeometry(QRect(720, 200, 41, 23));
        todaybutton->setFont(font5);
        yesterdaybutton = new QPushButton(Widget);
        yesterdaybutton->setObjectName(QString::fromUtf8("yesterdaybutton"));
        yesterdaybutton->setGeometry(QRect(690, 200, 31, 23));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setBold(true);
        font6.setWeight(75);
        yesterdaybutton->setFont(font6);
        tomorrowbutton = new QPushButton(Widget);
        tomorrowbutton->setObjectName(QString::fromUtf8("tomorrowbutton"));
        tomorrowbutton->setGeometry(QRect(760, 200, 31, 23));
        tomorrowbutton->setFont(font6);
        nextweekbutton = new QPushButton(Widget);
        nextweekbutton->setObjectName(QString::fromUtf8("nextweekbutton"));
        nextweekbutton->setGeometry(QRect(740, 180, 51, 12));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Arial"));
        font7.setPointSize(7);
        nextweekbutton->setFont(font7);
        searchtext = new QLineEdit(Widget);
        searchtext->setObjectName(QString::fromUtf8("searchtext"));
        searchtext->setGeometry(QRect(690, 20, 101, 23));
        searchtext->setFont(font3);
        searchbutton = new QPushButton(Widget);
        searchbutton->setObjectName(QString::fromUtf8("searchbutton"));
        searchbutton->setGeometry(QRect(740, 50, 51, 24));
        informationlabel = new QLabel(Widget);
        informationlabel->setObjectName(QString::fromUtf8("informationlabel"));
        informationlabel->setGeometry(QRect(150, 410, 101, 31));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Arial"));
        font8.setPointSize(8);
        informationlabel->setFont(font8);
        messageidlabel = new QLabel(Widget);
        messageidlabel->setObjectName(QString::fromUtf8("messageidlabel"));
        messageidlabel->setGeometry(QRect(180, 340, 61, 16));
        messageidlabel->setFont(font8);
        messageidlabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        gotoday = new QPushButton(Widget);
        gotoday->setObjectName(QString::fromUtf8("gotoday"));
        gotoday->setGeometry(QRect(10, 2, 231, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Nehemiah", 0, QApplication::UnicodeUTF8));
        neweventbutton->setText(QApplication::translate("Widget", "NEW", 0, QApplication::UnicodeUTF8));
        completedcheckbox->setText(QApplication::translate("Widget", "Show 100%", 0, QApplication::UnicodeUTF8));
        saveeditbutton->setText(QApplication::translate("Widget", "SAVE", 0, QApplication::UnicodeUTF8));
        finishbutton->setText(QApplication::translate("Widget", "FINISH", 0, QApplication::UnicodeUTF8));
        deletebutton->setText(QApplication::translate("Widget", "del", 0, QApplication::UnicodeUTF8));
        labelcurrentday->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        entercheckbox->setText(QApplication::translate("Widget", "Save on enter", 0, QApplication::UnicodeUTF8));
        todaybutton->setText(QApplication::translate("Widget", "Today", 0, QApplication::UnicodeUTF8));
        yesterdaybutton->setText(QApplication::translate("Widget", "<<", 0, QApplication::UnicodeUTF8));
        tomorrowbutton->setText(QApplication::translate("Widget", ">>", 0, QApplication::UnicodeUTF8));
        nextweekbutton->setText(QApplication::translate("Widget", "next week", 0, QApplication::UnicodeUTF8));
        searchtext->setInputMask(QString());
        searchtext->setText(QString());
        searchbutton->setText(QApplication::translate("Widget", "Search", 0, QApplication::UnicodeUTF8));
        informationlabel->setText(QApplication::translate("Widget", "total = 9999/99999\n"
"today = 999/999", 0, QApplication::UnicodeUTF8));
        messageidlabel->setText(QApplication::translate("Widget", "ID=n/a", 0, QApplication::UnicodeUTF8));
        gotoday->setText(QApplication::translate("Widget", "go to today", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
