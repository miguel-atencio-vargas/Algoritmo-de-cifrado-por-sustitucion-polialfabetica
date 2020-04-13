#include <bits/stdc++.h>
using namespace std;

int main(){
   // Me base en la informacion de esta pagina: 
   //http://www.criptored.upm.es/crypt4you/temas/criptografiaclasica/leccion9.html
   // CREACION DE EL VECTOR CON EL ABECEDARIO CIRCULAR (SIN Ñ) DE 26 CARACTERES ASCII
   char alpha[52];
   int j=0;
   for (int i =0; i<sizeof(alpha); i++){
      if(j<26){ 
         alpha[i]=char(j+65);
         j++;
      }else{ j=0; i--;}
   }

   for (int i =0; i<sizeof(alpha); i++){
      cout<<alpha[i]<<endl;
   }

   //Creacion de la matriz:
   char vig[26][26];
   int p = 0;
   for(int i=0; i<26; i++){
      for(int j=0; j<26; j++){
         vig[i][j] = alpha[p+j];
      }
      p++;
   }
   // IMPRIME LA MATRIZ
   for(int i=0; i<26; i++){
      for(int j=0; j<26; j++){
         cout<<vig[i][j]<<" ";
      }
      cout<<endl;
   }

   //interaccion con el usuario
   string f, k, w;
   int col, fil, x = 0;
   cout<<"Ingrese la frase a ser cifrada: "<<endl;    getline(cin, f);
   cout<<"Ingrese la clave para cifrar: "  <<endl;    cin>>k;
   stringstream X(f); 
   cout<<"Su mensaje crifrado es: ";
   while (getline(X, w, ' ')) { 
      for(int i=0; i<w.size(); i++){
         if(x>=k.size()){  x=0;  }
         col = int(w[i])-65;
         fil = int(k[x])-65;
         //cout<<"fila: "<<fil<<" col: "<<col<<" ";
         cout<<vig[fil][col];
         x++;
      }
      cout<<" ";
   }
   cout<<endl;
   return 0;
}

