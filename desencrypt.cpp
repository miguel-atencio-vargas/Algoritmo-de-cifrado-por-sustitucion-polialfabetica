#include <bits/stdc++.h>
using namespace std;

int main(){
    string f,k,w;
    int mi, ci, ki,x = 0;
    cout<<"Ingrese la frase a ser des-cifrada: "<<endl; getline(cin, f);
    cout<<"Ingrese la clave secreta: "<<endl;           cin>>k;
    stringstream X(f); 
    // JMVXCUW = f( HERMOSO, CIELO )
    while (getline(X, w, ' ')) {
        for(int i = 0; i<w.size(); i++){
            if(x>=k.size()){ x=0; }
            ci = int(w[i])-65;
            ki = int(k[x])-65;
            //mi = (ci - ki)%26; ecuacion generica propensa a errores
            mi = (ci + (26 - ki)) % 26; 
            x++;
            //cout<<ci<<" - "<<ki<<" = "<<mi<<" ";
            cout<<char(mi+65);
        }
        cout<<" ";
    }
    cout<<endl;
    return 0;
}