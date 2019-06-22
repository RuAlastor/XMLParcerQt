/* To add a new tag to read go to chooseInfoType function */

#include "parcer.h"

int main() {

    // Setting up parcer
    Parcer xmlParcer;
    QString filename = "/home/student/C++/XMLParcerQt/example.xml";
    if (xmlParcer.loadDocument(filename)) {
        return -1;
    }

    // Factory's working on a parced document
    if (xmlParcer.parceLoadedFile()) {
        return -1;
    }

    // Show parced document
    if (xmlParcer.printRecipe()) {
        return -1;
    }

    return 0;
}
