#include <QApplication>
#include <QtWidgets>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  QFileSystemWatcher fsWatcher;

  QStringList args = a.arguments();
  args.removeFirst();

  fsWatcher.addPaths(args);

  w.append("Watchig files: " + fsWatcher.files().join(";"));
  w.append("Watchig dirs: " + fsWatcher.directories().join(";"));

  QObject::connect(&fsWatcher, SIGNAL(directoryChanged(const QString&)),
                   &w, SLOT(slotDirectoryChanged(const QString&)));
  QObject::connect(&fsWatcher, SIGNAL(fileChanged(const QString&)),
                   &w, SLOT(slotFileChanged(const QString&)));

  w.show();
  return a.exec();
}
