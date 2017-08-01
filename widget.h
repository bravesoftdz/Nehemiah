#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDate>
#include <QTextCharFormat>
#include <QList>
#include <QKeyEvent>
#include <QMessageBox>

#include <QIODevice>
#include <QFile>
#include <QDataStream>


namespace Ui {
    class Widget;
}

const int maxrecords=5000;
const int maxdayrecords=200;
const int newmessageedit=maxrecords+10;
const int groupselected=maxrecords+999;

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Widget *ui;

    QString messagetext[maxrecords];
    QDate messagedate[maxrecords];
    qint8 completed[maxrecords];
    qint16 n;

    int currentedit;
    qint16 currentdayevents[maxdayrecords];
    qint16 currentday;

//    QTextCharFormat boldtext;
    QTextCharFormat normaltext;
    QTextCharFormat strongtext;

    void enablecontrols(bool enableflag);
    void savedata();
    void loaddata();

private slots:
    void datechanged();
    void newevent();
    void eventselected();
    void saveevent();
    void finishevent();
    void deleteevent();

    void gotoday();
    void gotomorrow();
    void goyesterday();
    void gonextweek();

    void gototoday();

    void search();
    //void checkifsearch();

protected:
    bool eventFilter(QObject *object, QEvent *event);
//    void keyPressEvent(QKeyEvent *event);
};

#endif // WIDGET_H
