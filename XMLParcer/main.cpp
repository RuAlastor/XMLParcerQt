
#include "parcer.h"

int main() {

    // Setting up parcer
    Parcer xmlParcer;
    QString filename = "/home/student/C++/example.xml";
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
