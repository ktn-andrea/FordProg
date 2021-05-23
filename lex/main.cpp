#include <iostream>
#include <vector>

using namespace std;
    vector<string> Elemez(string input, vector<string> &output){
        for (int i=0; i<input.size(); i++){
        if( isdigit(input[i]) ){
            while ( isdigit(input[i+1]) ){
                i++;
            }
            output.push_back("<konstans>");
        }
        else if( isalpha(input[i]) ){
            while ( isalpha(input[i+1]) || isdigit(input[i+1]) ){
                i++;
            }
            output.push_back("<azonosito>");
        }
        else if( input[i] == '{' ){
            do {
                i++;
            } while (input[i] != '}' && i<input.size() );

            if ( input[i] == '}' ){
                output.push_back("<kommentar-1>");
            }
            else {output.push_back("Error "); break;}

        }
        else if( input[i] == '(' && input[i+1] == '*' ){
            do {
                i++;
            } while ( (input[i+1] != '*' && input[i+2] != ')') && i+2<input.size() );
            if ( input[i+1] == '*' && input[i+2] == ')' ){
                output.push_back("<kommentar-2>");
            }
            else {output.push_back("Error");cout<<i; break;}
            i+=2;
        }
        else if( input[i] == ':' ){
            if ( input[i+1] == '=' ){
                output.push_back("<ertekadasjel>");
                i++;
            }
            else {output.push_back("Error"); break;}
        }
        else if( input[i] == '<' ){
            if ( input[i+1] == '=' ){
                output.push_back("< <= >");
                i++;
            }
            else if ( input[i+1] == '>' ){
                output.push_back("< <> >");
                i++;
            }
            else {output.push_back("Error"); break;}
        }
        else if( input[i] == '>' ){
            if ( input[i+1] == '=' ){
                output.push_back("< >= >");
                i++;
            }
            else {output.push_back("Error"); break;}
        }
        else if( input[i] == '$' ){
            output.push_back("<programvege>");
        }
        else if( isspace(input[i]) ){
            continue;
        }
        else {output.push_back("Error"); break;}
        }

        return output;

    }


int main()
{
    string lex;
    cin >> lex;
    vector<string> eredmeny;
    Elemez(lex, eredmeny);

    for (int i=0; i<eredmeny.size(); i++){
        cout << eredmeny.at(i);
    }


    return 0;
}
