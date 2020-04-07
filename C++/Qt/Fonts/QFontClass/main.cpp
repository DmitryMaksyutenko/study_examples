#include <QApplication>
#include <QFont>
#include <QLabel>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QFont font;
    font.setFamily("Segoe UI");
    font.setStyle(QFont::Style::StyleItalic);
    font.setWeight(QFont::Weight::Bold);
    font.setPointSize(25);
    font.setUnderline(true);
    font.setOverline(true);
    font.setLetterSpacing(QFont::SpacingType::PercentageSpacing, 200.0);
    font.setWordSpacing(150.0);

    QLabel lab;
    lab.setGeometry(600, 400, 500, 200);
    lab.setText("Test text");

    lab.setFont(font);

    lab.show();

    return app.exec();
}
