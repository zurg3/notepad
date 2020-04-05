#include <QApplication>
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QString>
#include <QSysInfo>

#include "notepad.h"
#include "version.h"

int main(int argc, char *argv[]) {
  QApplication EditorApp(argc, argv);
  EditorApp.setWindowIcon(QIcon(":/images/app_icon.png"));

  QCoreApplication::setApplicationName("Notepad");
  QCoreApplication::setApplicationVersion(QString("version ") + app_full_version);

  QCommandLineParser cli_parser;
  cli_parser.addVersionOption();
  cli_parser.process(EditorApp);
  const QStringList args = cli_parser.positionalArguments();

  Notepad Editor;
  Editor.show();

  return EditorApp.exec();
}
