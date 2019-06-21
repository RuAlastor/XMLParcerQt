#include <QtCore>
#include <QtXml>
#include <iostream>



int main() {
    QDomDocument xmlParcer;
    QFile file("/home/student/C++/XMLParcerQt/example.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Failed to open \"example.xml\".\n";
        return -1;
    }
    if (!xmlParcer.setContent(&file)) {
        std::cout << "Failed to parce \"example.xml\".\n";
        file.close();
        return -1;
    }

    std::cout << "File was successfully parced!\n";

    return 0;
}
