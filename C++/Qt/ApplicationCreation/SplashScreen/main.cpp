#include <QApplication>
#include <QtWidgets>
#include <QTime>

void loadModules(QSplashScreen *pSplash)
{
  QTime time;
  time.start();

  for (int i = 0; i < 100; ) {
    if (time.elapsed() > 40) {
      time.start();
      i++;
    }

  pSplash->showMessage("Loading modules:" +
                       QString::number(i) + "%",
                       Qt::AlignCenter | Qt::AlignBottom,
                       Qt::black);
  qApp->processEvents();
  }
}

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QSplashScreen splash(QPixmap(":/img/Linux.png"));

  splash.show();

  QLabel lbl("<H1><CENTER>Application<BR>Is Ready!</CENTER></H1>");

  loadModules(&splash);

  lbl.resize(250, 250);
  lbl.show();
  return a.exec();
}
