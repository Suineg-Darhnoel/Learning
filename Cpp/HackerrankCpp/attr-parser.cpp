#include <iostream>
#include <sstream>
#include <map>
using namespace std;

/* Example
 * -----------------------------
    <tag1 value = "HelloWorld">
        <tag2 name = "Name1">
        </tag2>
    </tag1>
 * -----------------------------
 *  The attributes are referenced as
 *  tag1-value
 *  tag2-tag2-name
 *
 * Input Format
 * The first line consists of two separated integers, N and Q.
 * N specifies the number of lines in the HRML source program.
 * Q specifies the number of queries.
 * The following N lines consist of either an opening tag with zero
 * or more attributes or a closing tag.
 * There is a space after the tag-name, attribute-name, '=' and value.
 * There is no space after the last value.
 * If there is no attribute there is no space after the tag name.
 *
 * Q queries follow. Each query consists of string that references an
 * attribute in the source program.
 *
 *  Constraints
 *  1 <= N <= 20
 *  1 <= Q <= 20
*/
int main()
{
    int N, Q;
    cin >> N >> Q;
    cin.ignore();

    map <string, string> attrDB; // to store attr_value pairs
    string inputstr, tag_preamble="";

    // get each HRML line
    for (int i=0; i < N; i++){
        getline(cin, inputstr);

        // for each HRML line, break it up into token words
        stringstream ss(inputstr);
        string token, attr, val;
        size_t pos;
        while (getline(ss, token, ' ')){
            // for each token
            // tag detected -> adjust tag_preamble by +/- tag
            if (token[0] == '<'){
                string tag;
                if (token[1] == '/'){
                    // it's tag closing
                    tag = token.substr(2);
                    tag = tag.substr(0, tag.length()-1); // get rid of ">"
                    pos = tag_preamble.find("."+tag);
                    if (pos == string::npos) tag_preamble = "";
                    else tag_preamble = tag_preamble.substr(0, pos);
                }
                else{ // it's tag opening
                    tag = token.substr(1);
                    if (tag.find(">") != string::npos)
                        tag = tag.substr(0, tag.length()-1); // get rid of ">"
                    if (tag_preamble=="") tag_preamble = tag;
                    else tag_preamble = tag_preamble + "." + tag;
                }
            }
            // value detected
            else if (token[0] == '"'){
                pos = token.find_last_of('"');
                val = token.substr(1, pos-1);
                attrDB[attr] = val; // insert into DB
            }
            else if (token[0] != '='){
                attr = tag_preamble + "~" + token;
            }
        }
    }

    /* process the queries */
    for (int i = 0; i < Q; i++){
        getline(cin, inputstr);
        if (attrDB.find(inputstr) == attrDB.end())
            cout << "Not Found!" << endl;
        else
            cout << attrDB[inputstr] << endl;
    }
    return 0;
}
