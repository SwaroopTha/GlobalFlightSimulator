#include "readdat.h"

using namespace std;

vector<string> readline(stringstream & ss, char delim) {
    vector<string> fields;
    string field = "";
    char c;
    bool inQuote = false;
    while (ss.get(c)) {
        if (c == '"') {
            inQuote = !inQuote;
        } else if (c == delim && !inQuote) {
            fields.push_back(field);
            field = "";
        } else {
            field += c;
        }
    }
    fields.push_back(field);
    return fields;
}
