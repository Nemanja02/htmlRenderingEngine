#include <iostream>
#include <fstream>

class Reader {
    private:
        std::string file;
    public:
        Reader(std::string file) {
            this->file = file;
        }

        std::string getText() {
            std::ifstream ifs (file);
            std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
            return content;
        }
};