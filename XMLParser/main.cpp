
#include "parser.h"

int main() {
    const char* fileloc = "/home/student/C++/example.xml";
    TestTask::Parser someParser(fileloc);
    someParser.loadDocument();
    someParser.parseDocument();
    someParser.printDocument();

    return 0;
}
