#include <QApplication>
#include <QTextDocumentWriter>
#include <QTextEdit>
#include <QtPrintSupport/QPrinter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextEdit text("<h1>This is test text</h1><b>Hello World!!!</b>");
    QTextDocumentWriter docWrite("testfile.odf");
    docWrite.write(text.document());

    QTextEdit textToPrint("This is text to print: <hr><b>I like Qt!</b>");
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("file.pdf");
    textToPrint.document()->print(&printer);

    return a.exec();
}
