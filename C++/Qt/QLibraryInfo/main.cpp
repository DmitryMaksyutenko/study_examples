#include <QtCore>

int main()
{

    qDebug() << "----- LOCATIONS -----";
    qDebug() << "	Headers:		" << QLibraryInfo::location(QLibraryInfo::HeadersPath);
    qDebug() << "	Libraries:		" << QLibraryInfo::location(QLibraryInfo::LibrariesPath);
    qDebug() << "	Binaries:		" << QLibraryInfo::location(QLibraryInfo::BinariesPath);
    qDebug() << "	Prefix:			" << QLibraryInfo::location(QLibraryInfo::PrefixPath);
    qDebug() << "	Documentation:		" << QLibraryInfo::location(QLibraryInfo::DocumentationPath);
    qDebug() << "	Plugins:		" << QLibraryInfo::location(QLibraryInfo::PluginsPath);
    qDebug() << "	Data:			" << QLibraryInfo::location(QLibraryInfo::DataPath);
    qDebug() << "	Settings:		" << QLibraryInfo::location(QLibraryInfo::SettingsPath);
    qDebug() << "	Examples:		" << QLibraryInfo::location(QLibraryInfo::ExamplesPath);

    return 0;
}
