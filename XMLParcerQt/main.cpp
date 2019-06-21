#include <iostream>
#include <QtCore>
#include <QtXml>

int main() {
    QDomDocument xmlParcer;
    QFile file("/home/student/C++/XMLParcerQt/example.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Failed to open the file.";
        return -1;
    }
    QString errorMsg;
    int errorLine;
    int errorColumn;
    if (!xmlParcer.setContent(&file, NULL, &errorMsg, &errorLine, &errorColumn)) {
        std::cout << "Failed to parce the file.\n" << errorMsg.toStdString() << " Line: " << errorLine << " Column: " << errorColumn;
        file.close();
        return -1;
    }
    file.close();


    return 0;;
}
