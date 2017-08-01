#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->calendarWidget, SIGNAL(selectionChanged()), this, SLOT(datechanged()));
    //connect(ui->calendarWidget, SIGNAL(clicked()), this, SLOT(datechanged()));
    connect(ui->neweventbutton, SIGNAL(clicked()), this, SLOT(newevent()));
    connect(ui->saveeditbutton, SIGNAL(clicked()), this, SLOT(saveevent()));
    connect(ui->finishbutton, SIGNAL(clicked()), this, SLOT(finishevent()));
    connect(ui->deletebutton, SIGNAL(clicked()), this, SLOT(deleteevent()));
    connect(ui->gotoday, SIGNAL(clicked()), this, SLOT(gototoday()));
    connect(ui->tomorrowbutton, SIGNAL(clicked()), this, SLOT(gotomorrow()));
    connect(ui->todaybutton, SIGNAL(clicked()), this, SLOT(gotoday()));
    connect(ui->yesterdaybutton, SIGNAL(clicked()), this, SLOT(goyesterday()));
    connect(ui->nextweekbutton, SIGNAL(clicked()), this, SLOT(gonextweek()));
    connect(ui->searchbutton, SIGNAL(clicked()), this, SLOT(search()));
    //connect(ui->searchtext, SIGNAL(clicked()), this, SLOT(checkifsearch()));


    connect(ui->tableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(eventselected()));
    connect(ui->completedcheckbox, SIGNAL(stateChanged(int)), this, SLOT(datechanged()));

    ui->tableWidget->setColumnWidth(0,50);
    ui->tableWidget->setColumnWidth(1,265);
    ui->tableWidget->setColumnWidth(2,90);

    ui->textEdit->installEventFilter(this);

    enablecontrols(false);

    n=-1;

    loaddata();

    normaltext.setFontUnderline(false);
    normaltext.setFontWeight(0);
    strongtext.setFontUnderline(true);
    strongtext.setFontWeight(99);

    if (n>-1) for (int i=0; i<=n; i++) if (completed[i]<100) { ui->calendarWidget->setDateTextFormat(messagedate[i],strongtext);}

    datechanged();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::enablecontrols(bool enableflag)
{
  ui->textEdit->setEnabled(enableflag);
  ui->finishbutton->setEnabled(enableflag);
  ui->horizontalSlider->setEnabled(enableflag);
  ui->dateEdit->setEnabled(enableflag);
  ui->saveeditbutton->setEnabled(enableflag);
  ui->deletebutton->setEnabled(enableflag);
  ui->todaybutton->setEnabled(enableflag);
  ui->tomorrowbutton->setEnabled(enableflag);
  ui->yesterdaybutton->setEnabled(enableflag);
  ui->nextweekbutton->setEnabled(enableflag);
  ui->messageidlabel->setVisible(enableflag);
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widget::search()
{
  if (ui->searchtext->text().length()>0) {
  //ui->calendarWidget->setSelectedDate(QDate::currentDate().addYears(-100));
  //make that clicking on calendar makes it emit signal
//  connect(ui->calendarWidget, SIGNAL(clicked()), this, SLOT(datechanged()));
  //check if no edits unsaved
  ui->tableWidget->clear();
  ui->tableWidget->setRowCount(0);
  currentday=0;
  bool emergency=false;
  if (n>-1) for (int i=0; i<=n; i++) if (!emergency) {
  if ((messagetext[i].toLower().indexOf(ui->searchtext->text().toLower())>-1) && ((completed[i]<100) || (ui->completedcheckbox->checkState()!=false))) {
    ui->tableWidget->setRowCount(currentday+1);
    ui->tableWidget->setRowHeight(currentday,24);
    if (currentday==maxdayrecords) {emergency=true;};
    if (!emergency)
      {
        ui->tableWidget->setItem(currentday,1,new QTableWidgetItem(messagetext[i]));
        ui->tableWidget->setItem(currentday,0,new QTableWidgetItem(QString::number(completed[i])+"%"));
        ui->tableWidget->setItem(currentday,2,new QTableWidgetItem(messagedate[i].toString("dd.MM.yyyy")));
      }
    else
      {ui->tableWidget->setItem(currentday,1,new QTableWidgetItem("-=(( Too many items!!! ))=-"));}

    currentdayevents[currentday]=i;
    currentday++;

    }
  }
 enablecontrols(false);
  ui->labelcurrentday->setText("SEARCH:"+ui->searchtext->text());
  ui->informationlabel->setText("Total = "+QString::number(n)+"/"+QString::number(maxrecords)+"\n Search = "+QString::number(currentday)+"/"+QString::number(maxdayrecords));
  ui->gotoday->setText("Go to today ("+QDate::currentDate().toString("dd.MM.yyyy")+")");
  ui->gotoday->setEnabled(true);

}  
}


void Widget::datechanged()
{
    //check if no edits unsaved
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    currentday=0;
    bool emergency=false;
    if (n>-1) for (int i=0; i<=n; i++) if (!emergency) {
    if (messagedate[i]==ui->calendarWidget->selectedDate() && ((completed[i]<100) || (ui->completedcheckbox->checkState()!=false))) {
      ui->tableWidget->setRowCount(currentday+1);
      ui->tableWidget->setRowHeight(currentday,24);
      if (currentday==maxdayrecords) {emergency=true;};
      if (!emergency)
        {
          ui->tableWidget->setItem(currentday,1,new QTableWidgetItem(messagetext[i]));
          ui->tableWidget->setItem(currentday,0,new QTableWidgetItem(QString::number(completed[i])+"%"));
          ui->tableWidget->setItem(currentday,2,new QTableWidgetItem(messagedate[i].toString("dd.MM.yyyy")));
        }
      else
        {ui->tableWidget->setItem(currentday,1,new QTableWidgetItem("-=(( Too many items!!! ))=-"));}

      currentdayevents[currentday]=i;
      currentday++;

      }
    }
    enablecontrols(false);
    ui->labelcurrentday->setText(ui->calendarWidget->selectedDate().toString("dd.MM.yyyy"));
    ui->informationlabel->setText("Total = "+QString::number(n)+"/"+QString::number(maxrecords)+"\n Today = "+QString::number(currentday)+"/"+QString::number(maxdayrecords));
    ui->gotoday->setText("Go to today ("+QDate::currentDate().toString("dd.MM.yyyy")+")");
    if (QDate::currentDate()==ui->calendarWidget->selectedDate()) {ui->gotoday->setEnabled(false);} else {ui->gotoday->setEnabled(true);}
  }

void Widget::newevent()
{
    ui->textEdit->clear();
    ui->dateEdit->setDate(ui->calendarWidget->selectedDate()); //QDate::currentDate()
    ui->horizontalSlider->setValue(0);
    currentedit=newmessageedit;
    enablecontrols(true);
    ui->deletebutton->setEnabled(false);
    ui->textEdit->setFocus();
    ui->messageidlabel->setVisible(false);
}

void Widget::eventselected()
{
    QList<QTableWidgetItem *> listofselected;
    listofselected=ui->tableWidget->selectedItems();
    ui->textEdit->clear();
    if (listofselected.size()==1) {
      enablecontrols(true);
      currentedit=currentdayevents[listofselected[0]->row()];
      if (messagedate[currentedit]==QDate::currentDate().addDays(-1)) ui->yesterdaybutton->setEnabled(false);
      if (messagedate[currentedit]==QDate::currentDate()) ui->todaybutton->setEnabled(false);
      if (messagedate[currentedit]==QDate::currentDate().addDays(1)) ui->tomorrowbutton->setEnabled(false);
      if (messagedate[currentedit]==QDate::currentDate().addDays(7)) ui->nextweekbutton->setEnabled(false);
      ui->textEdit->setText(messagetext[currentedit]);
      ui->dateEdit->setDate(messagedate[currentedit]);
      ui->horizontalSlider->setValue(completed[currentedit]);
      ui->messageidlabel->setText("ID = "+QString::number(currentedit));
    } else {
        enablecontrols(false);
        if (listofselected.size()>0) {
            currentedit=groupselected;
            ui->dateEdit->setEnabled(true);
            ui->saveeditbutton->setEnabled(true);
            ui->todaybutton->setEnabled(true);
            ui->tomorrowbutton->setEnabled(true);
            ui->yesterdaybutton->setEnabled(true);
            ui->nextweekbutton->setEnabled(true);

            ui->messageidlabel->setVisible(true);
            ui->messageidlabel->setText("<group>");
        }
    }
}

void Widget::saveevent()
{
  if ((currentedit<=n) || (currentedit==newmessageedit)){
    QDate olddate;
    if (currentedit==newmessageedit) {
      n++;
      currentedit=n;
      olddate=QDate::currentDate();
      //markundoaction
    } else {
      olddate=messagedate[currentedit];
    }

    messagetext[currentedit]=ui->textEdit->toPlainText(); //tohtml
    messagedate[currentedit]=ui->dateEdit->date();
    completed[currentedit]=ui->horizontalSlider->value();

    if (completed[currentedit]<100) {ui->calendarWidget->setDateTextFormat(messagedate[currentedit],strongtext);}
    bool flg=false;
    for (int i=0; i<=n; i++) { if ((messagedate[i]==olddate) && (completed[i]<100)) {flg=true;} }
    if (flg==false) ui->calendarWidget->setDateTextFormat(olddate,normaltext);

    //if ((olddate==ui->calendarWidget->selectedDate()) || (messagedate[currentedit]==ui->calendarWidget->selectedDate()))  datechanged(); else enablecontrols(false);
    //saveundo
  } else if (currentedit==groupselected) {
    QList<QTableWidgetItem *> listofselected;
    listofselected=ui->tableWidget->selectedItems();

    int currentitem;
    for (int i=0; i<listofselected.size(); i++) {
      currentitem=currentdayevents[listofselected[i]->row()];
      QDate olddate=messagedate[currentitem];

      messagedate[currentitem]=ui->dateEdit->date();
      if (completed[currentitem]<100) {ui->calendarWidget->setDateTextFormat(messagedate[currentitem],strongtext);}
      bool flg=false;
      for (int j=0; j<=n; j++) { if ((messagedate[j]==olddate) && (completed[j]<100)) {flg=true;} }
      if (flg==false) ui->calendarWidget->setDateTextFormat(olddate,normaltext);
    }
  }
  enablecontrols(false);
  savedata();
  datechanged();
}

void Widget::finishevent()
{
  ui->horizontalSlider->setValue(100);
  saveevent();
}

void Widget::deleteevent()
{
  QDate olddate=messagedate[currentedit];
  if ((n>0) && (currentedit!=n)) for (int i=currentedit; i<=n-1; i++)
  {
    messagedate[i]=messagedate[i+1];
    messagetext[i]=messagetext[i+1];
    completed[i]=completed[i+1];
  }
  n--;

  bool flg=false;
  if (n>-1) for (int i=0; i<=n; i++) { if (messagedate[i]==olddate) flg=true; }
  if (flg==false) ui->calendarWidget->setDateTextFormat(olddate,normaltext);
  enablecontrols(false);

  if ((olddate==ui->calendarWidget->selectedDate()) || (messagedate[currentedit]==ui->calendarWidget->selectedDate()))  datechanged(); else enablecontrols(false);
  //saveundo
  savedata();
}

void Widget::savedata()
{
  QFile file("~book.nmx");
  file.open(QIODevice::WriteOnly);
  QDataStream out(&file);
  out.setVersion(QDataStream::Qt_4_1);
  out << n;
  for (int i=0; i<=n; i++) {
    out << messagedate[i] << messagetext[i] << completed[i];
  }
  file.close();
  if (file.error()==0) {
    QFile::remove("book.nmx");
    QFile::rename("~book.nmx","book.nmx");
  } else {
    QMessageBox msgBox;
    msgBox.setText("FileWrite failed!!!");
    msgBox.exec();
  }

  // backup one more time
  QFile file2("#book.nmx");
  file2.open(QIODevice::WriteOnly);
  QDataStream out2(&file2);
  out2.setVersion(QDataStream::Qt_4_1);
  out2 << n;
  for (int i=0; i<=n; i++) {
    out2 << messagedate[i] << messagetext[i] << completed[i];
  }
  file2.close();
  if (file.error()!=0) {
    QMessageBox msgBox;
    msgBox.setText("Backup FileWrite failed!!!");
    msgBox.exec();
  }
}

void Widget::loaddata()
{
  QFile file("book.nmx");
  if (file.open(QIODevice::ReadOnly)) {
    QDataStream in(&file);
    in >> n;
    for (int i=0; i<=n; i++) {
      in >> messagedate[i] >> messagetext[i] >> completed[i];
    }
    file.close();
  }
  if (file.error()==0) {
    QString backupfilename="backup"+QDate::currentDate().toString("yyyyMMdd")+".nmx";
    if (QFile::exists(backupfilename)) QFile::remove(backupfilename);
    QFile::copy("book.nmx",backupfilename);
  } else {
    QMessageBox msgBox;
    msgBox.setText("FileRead failed!!!");
    msgBox.exec();
  }

}

/*void Widget::keyPressEvent(QKeyEvent *event)
{
  int key = event->key();
  if (key == Qt::Key_Return || key == Qt::Key_Enter)
  {
     hitenter();
  }
}*/

bool Widget::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
       QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
       if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
       {
          if (ui->entercheckbox->isChecked()==true) {saveevent();}
       }

    }
    return false;
}

void Widget::gotoday()
{
    ui->dateEdit->setDate(QDate::currentDate());
    saveevent();
}
void Widget::gotomorrow()
{
    ui->dateEdit->setDate(QDate::currentDate().addDays(1));
    saveevent();
}
void Widget::goyesterday()
{
    ui->dateEdit->setDate(QDate::currentDate().addDays(-1));
    saveevent();
}
void Widget::gonextweek()
{
    ui->dateEdit->setDate(QDate::currentDate().addDays(7));
    saveevent();
}
void Widget::gototoday()
{
    if (ui->calendarWidget->selectedDate()==QDate::currentDate()) datechanged();
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
}

/*void Widget::checkifsearch()
{
 // if (ui->searchtext->text()=="Search")
  {ui->searchtext->setText("");}
}*/
