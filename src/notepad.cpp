#include <QFile>
#include <QFileDialog>
//#include <QTextStream>
#include <QMessageBox>
#if defined(QT_PRINTSUPPORT_LIB)
  #include <QtPrintSupport/qtprintsupportglobal.h>
  #if QT_CONFIG(printer)
    #if QT_CONFIG(printdialog)
      #include <QPrintDialog>
    #endif
    #include <QPrinter>
  #endif
#endif
#include <QFont>
#include <QString>
#include <QtGlobal>
#include <QFontMetrics>
#include <QDir>
#include <QStatusBar>
#include <QTextDocument>
#include <QDateTime>
#include <QDesktopServices>

#include "notepad.h"
#include "ui_notepad.h"

#include "config.h"
#include "version.h"

Notepad::Notepad(QWidget *parent):
  QMainWindow(parent),
  ui(new Ui::Notepad) {
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    setWindowTitle(QString("[*]") + default_file_name + QString(" — Notepad"));

    createStatusBar();

    connect(ui->actionNew, &QAction::triggered, this, &Notepad::newDocument);
    connect(ui->actionOpen, &QAction::triggered, this, &Notepad::open);
    connect(ui->actionSave, &QAction::triggered, this, &Notepad::save);
    connect(ui->actionSave_as, &QAction::triggered, this, &Notepad::saveAs);
    connect(ui->actionPrint, &QAction::triggered, this, &Notepad::print);
    connect(ui->actionExit, &QAction::triggered, this, &Notepad::exit);
    connect(ui->actionCopy, &QAction::triggered, this, &Notepad::copy);
    connect(ui->actionCut, &QAction::triggered, this, &Notepad::cut);
    connect(ui->actionPaste, &QAction::triggered, this, &Notepad::paste);
    connect(ui->actionUndo, &QAction::triggered, this, &Notepad::undo);
    connect(ui->actionRedo, &QAction::triggered, this, &Notepad::redo);
    connect(ui->actionZoomOut, &QAction::triggered, this, &Notepad::zoomOut);
    connect(ui->actionZoomIn, &QAction::triggered, this, &Notepad::zoomIn);
    connect(ui->actionInsertTimeDate, &QAction::triggered, this, &Notepad::insertTimeDate);
    connect(ui->actionOpenGitHub, &QAction::triggered, this, &Notepad::openGitHub);
    connect(ui->actionAbout, &QAction::triggered, this, &Notepad::about);
    connect(ui->textEdit->document(), &QTextDocument::contentsChanged, this, &Notepad::documentWasModified);

    QFont font;

    font.setFamily(font_family);
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    font.setPointSize(font_size);

    ui->textEdit->setFont(font);

    ui->textEdit->setAcceptRichText(false);

    // Open file from command line argument
    if (QApplication::arguments().size() > 1) {
      QString fileName = QApplication::arguments().at(1);
      QFile file(fileName);
      currentFile = fileName;
      if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
      }
      //QTextStream in(&file);
      //QString text = in.readAll();
      QString text = QString::fromUtf8(file.readAll());
      ui->textEdit->setText(text);
      ui->textEdit->document()->setModified(false);
      setWindowModified(false);
      setWindowTitle(QString("[*]") + fileName + QString(" — Notepad"));
      file.close();
      statusBar()->showMessage("File opened", status_bar_message_timeout);
    }

    #if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
      ui->textEdit->setTabStopDistance(tab_size * 10);
    #else
      QFontMetrics metrics(font);

      ui->textEdit->setTabStopWidth(tab_size * metrics.width(" "));
    #endif

    #if !QT_CONFIG(printer)
      ui->actionPrint->setEnabled(false);
    #endif

    #if !QT_CONFIG(clipboard)
      ui->actionCut->setEnabled(false);
      ui->actionCopy->setEnabled(false);
      ui->actionPaste->setEnabled(false);
    #endif
  }

Notepad::~Notepad() {
  delete ui;
}

void Notepad::createStatusBar() {
  statusBar()->showMessage("Notepad");
}

void Notepad::newDocument() {
  currentFile.clear();
  ui->textEdit->setText(QString());
}

void Notepad::open() {
  QString fileName = QFileDialog::getOpenFileName(this, "Open the file", QDir::homePath(), "Text files (*.txt);;All files (*)");
  QFile file(fileName);
  currentFile = fileName;
  if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
    return;
  }
  //QTextStream in(&file);
  //QString text = in.readAll();
  QString text = QString::fromUtf8(file.readAll());
  ui->textEdit->setText(text);
  ui->textEdit->document()->setModified(false);
  setWindowModified(false);
  setWindowTitle(QString("[*]") + fileName + QString(" — Notepad"));
  file.close();
  statusBar()->showMessage("File opened", status_bar_message_timeout);
}

void Notepad::save() {
  QString fileName;
  if (currentFile.isEmpty()) {
    fileName = QFileDialog::getSaveFileName(this, "Save", QDir::homePath(), "Text files (*.txt);;All files (*)");
    currentFile = fileName;
  }
  else {
    fileName = currentFile;
  }
  QFile file(fileName);
  if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
    QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
    return;
  }
  //QTextStream out(&file);
  //QString text = ui->textEdit->toPlainText();
  file.write(ui->textEdit->toPlainText().toUtf8());
  //out << text;
  ui->textEdit->document()->setModified(false);
  setWindowModified(false);
  setWindowTitle(QString("[*]") + fileName + QString(" — Notepad"));
  file.close();
  statusBar()->showMessage("File saved", status_bar_message_timeout);
}

void Notepad::saveAs() {
  QString fileName = QFileDialog::getSaveFileName(this, "Save as", QDir::homePath(), "Text files (*.txt);;All files (*)");
  QFile file(fileName);

  if (!file.open(QFile::WriteOnly | QFile::Text)) {
    QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
    return;
  }

  currentFile = fileName;
  //QTextStream out(&file);
  //QString text = ui->textEdit->toPlainText();
  file.write(ui->textEdit->toPlainText().toUtf8());
  //out << text;
  ui->textEdit->document()->setModified(false);
  setWindowModified(false);
  setWindowTitle(QString("[*]") + fileName + QString(" — Notepad"));
  file.close();
  statusBar()->showMessage("File saved", status_bar_message_timeout);
}

void Notepad::print() {
  #if QT_CONFIG(printer)
    QPrinter printDev;
    #if QT_CONFIG(printdialog)
      QPrintDialog dialog(&printDev, this);
      if (dialog.exec() == QDialog::Rejected) {
        return;
      }
    #endif
    ui->textEdit->print(&printDev);
  #endif
}

void Notepad::exit() {
  QCoreApplication::quit();
}

void Notepad::copy() {
  #if QT_CONFIG(clipboard)
    ui->textEdit->copy();
  #endif
}

void Notepad::cut() {
  #if QT_CONFIG(clipboard)
    ui->textEdit->cut();
  #endif
}

void Notepad::paste() {
  #if QT_CONFIG(clipboard)
    ui->textEdit->paste();
  #endif
}

void Notepad::undo() {
  ui->textEdit->undo();
}

void Notepad::redo() {
  ui->textEdit->redo();
}

void Notepad::zoomOut() {
  ui->textEdit->zoomOut(zoom_range);
}

void Notepad::zoomIn() {
  ui->textEdit->zoomIn(zoom_range);
}

void Notepad::insertTimeDate() {
  QDateTime current_time_date = QDateTime::currentDateTime();
  QString current_time_date_string = current_time_date.toString("hh:mm:ss dd.MM.yyyy");

  ui->textEdit->insertPlainText(current_time_date_string);
}

void Notepad::openGitHub() {
  QDesktopServices::openUrl(QUrl("https://github.com/zurg3/notepad"));
}

void Notepad::about() {
  QString about_message = QString("<h3>Notepad</h3>")
                        + QString("<span style='color: #707070;'>version ")
                        + app_full_version
                        + QString("</span>")
                        + QString("<br><br><br>Simple text editor. Based on <a href='https://code.qt.io/cgit/qt/qtbase.git/tree/examples/widgets/tutorials/notepad?h=6.3'>official Qt6 Notepad example</a>.")
                        + QString("<br><br>This software is licensed under <a href='https://www.gnu.org/licenses/gpl-3.0.html'>GNU GPL v3</a>.")
                        + QString("<br><br>Source code is available on <a href='https://github.com/zurg3/notepad'>GitHub</a>.")
                        + QString("<br><br><br>Qt version: ")
                        + QT_VERSION_STR;

  QMessageBox::about(this, "About", about_message);
}

void Notepad::documentWasModified() {
  setWindowModified(ui->textEdit->document()->isModified());
}
