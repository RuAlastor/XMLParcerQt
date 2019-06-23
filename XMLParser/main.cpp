
#include "parser.h"

int main() {
    const char* fileloc = "/home/student/C++/example.xml";
    TestTask::Parser someParser(fileloc);

    if (someParser.loadDocument()) {
        return -1;
    }

    if (someParser.parseDocument()) {
        return -2;
    }

    someParser.printDocument();

    return 0;
}
