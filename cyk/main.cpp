#include <iostream>

using namespace std;


int main()
{
    cout<<"Adja meg a levezetesi szabalyokat!" << endl <<
            "Minden terminalis/nemterminalis utan nyomjon entert!"<<endl;
    int N;
    cout<< "Adja meg a szabalyok szamat: ";
    cin >> N;
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

    string table[szo.length()][szo.length()];

    //Elso sor kitoltese
    for(int c=0; c<szo.length(); c++){
        string act(1, szo[c]);
        for(int j=0; j<N; j++){
            bal = grammar[j][0];
            if( act == grammar[j][1]) {
            table[0][c] += bal;
            }
        }
    }

    //Tovabbi sorok kitoltese
    string B, C;
    string act_komb, eredmeny;
    string cella = "";
    for (int i = 1; i < szo.length(); i++){
        for (int j = 0; j <szo.length(); j++){
            for (int k = 0; k < i; k++){
                B = table[k][j];
                C = table[i-k-1][k+j+1];

                //Kombinációk előállítása
                eredmeny = "";
                for ( int m = 0; m < B.length(); m++){
                    for (int v = 0; v < C.length(); v++){
                        act_komb = eredmeny + B[m] + C[v];

                        //Levezethető-e
                        cella = "";
                        for(int g=0; g<N; g++){
                            if(act_komb == grammar[g][1]){
                                cella.append(grammar[g][0]);
                            }
                        }
                        table[i][j].append(cella);
                    }
                }
            }
        }
    }

    //Eredmeny tabla kirajzolasa
    for(int i=0; i<szo.length(); i++){
        cout<< szo[i] << "\t";
    }
    cout << endl;
    for(int i=0; i<szo.length(); i++){
        for(int j=0; j<szo.length(); j++){
            if(j<szo.length()-i){
                    if(table[i][j] == ""){
                        cout << "-" << "\t";
                    }
                    else{
                        cout<< table[i][j] << "\t";
                    }
            }
        }
        cout<<endl;
    }

    //Valasz kiirasa
    cout << "-------------------------------------" << endl;
    if(table[szo.length()-1][0].find('S') != string::npos){
        cout << "A szo levezetheto." << endl;
    }
    else{
        cout << "A szo nem vezetheto le." << endl;
    }
    cout << "-------------------------------------" << endl;


    return 0;

}
