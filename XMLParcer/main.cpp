/* To add a new tag to read go to chooseInfoType function */

#include "parcer.h"

int main() {

    // Setting up parcer
    Parcer xmlParcer;
    QString filename = "/home/student/C++/XMLParcerQt/example.xml";
    xmlParcer.loadDocument(filename);

    // Factory's working on a parced document
    xmlParcer.parceLoadedFile();

    // Show parced document
    xmlParcer.printRecipe();

    return 0;
}
