#include "element.h"
#include "parser.h"
#include "attribute.h"
#include "reader.h"
#include "render.h"

main() {
    Reader r("index.html");
    Parser p(r.getText());
    Element e = p.parseDocument();
    Renderer render(e);
    render.init();
    
    return 0;
}