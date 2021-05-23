#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;


void showstack(stack <string> s)
{
    while (!s.empty())
    {
        cout << "\t" << s.top();
        s.pop();
    }
    cout << endl;
}

string stack_content(stack <string> s)
{
   string  v = "";
    while (!s.empty())
    {
        v = v + s.top();
        s.pop();
    }
    reverse(v.begin(), v.end());

    return v;
}




int main()
{

    cout<<"Adja meg a levezetesi szabalyokat!" << endl <<
        "Minden terminalis/nemterminalis utan nyomjon entert!"<<endl;
    int N;
    cout<< "Adja meg a szabalyok szamat: ";   cin >> N;
    string grammar[N][2];
    string bal, jobb;
    for(int i=0; i<N; i++){
        cout << i+1 << ". szabaly bal oldala: ";
        cin >> bal;
        grammar[i][0] = bal;
        cout << "\t" << "jobb oldala: ";
        cin >> jobb;
        grammar[i][1] = jobb;
    }

    cout << "A beolvasott szabalyok: " << endl;
    for(int i=0; i<N; i++){
        cout << i+1 << ". " << grammar[i][0] << " --> " << grammar[i][1] <<endl;
    }
    cout<<"Adja meg az ellenorizni kivant szot: "<<endl;
    string szo;
    cin >> szo;


    vector <string> levezetesek;
    stack <string> verem;
    string tartalom = "";
    string x;
    string act_bal = "";
    string act_tartalom = "";
    for(int c=0; c<szo.length(); c++){
        string act(1, szo[c]);
        verem.push(act);
        x = verem.top();
        showstack(verem);

        for(int i=0; i<N; i++){
            act_bal = grammar[i][0];
            if(x == grammar[i][1]){
                levezetesek.push_back(grammar[i][0]+" --> "+grammar[i][1]);
                verem.pop();
                verem.push(act_bal);
                showstack(verem);
            }
        }

        tartalom = stack_content(verem);
        act_tartalom = "";
        for(int j=0; j<tartalom.length(); j++){
            act_tartalom = act_tartalom + tartalom[j];
            for(int k=0; k<N; k++){
                act_bal = grammar[k][0];
                if(act_tartalom == grammar[k][1]){
                    levezetesek.push_back(grammar[k][0]+" --> "+grammar[k][1]);
                    cout << "levezetheto: "<<act_tartalom<<endl;
                    for(int g=0; g<act_tartalom.length();g++){
                        verem.pop();
                    }
                    verem.push(act_bal);
                    showstack(verem);
                }
            }
        }
    }

    tartalom = stack_content(verem);
    cout << "-------------------------------------" << endl;
    cout << "A verem tartalma: "<< tartalom<<endl;
    if(tartalom == "S"){
        cout<<"A szo levezetheto." << endl << "Jobboldali levezetes: " <<endl;
        for(int i=levezetesek.size()-1 ;i>=0 ;i--){
            cout<<levezetesek.at(i) << endl;
        }
    }
    else    cout <<"A szo nem vezetheto le." <<endl;
    cout << "-------------------------------------" << endl;


    return 0;

}
