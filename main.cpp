#include "element.h"
#include "parser.h"
#include "attribute.h"
#include "reader.h"

main() {
    Reader r("index.html");
    Parser p(r.getText());
    Element e = p.parseDocument();
    std::cout << "new element: " << e.stringifySelf() << std::endl;
    
    return 0;
}