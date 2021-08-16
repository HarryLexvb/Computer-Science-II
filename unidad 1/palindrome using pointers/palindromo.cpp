#include <iostream>
#include <cstring>
using namespace std;
bool palindromo(char *p){
    char cadenaf[50]={0},*parte;
    int c,len,pal=0;
    cout << "\n" << p;

    /*for(int  i = 0; palabra[i] != 0;++i)
        if(palabra[i] != 32)//32 significa espacio en codigo ascii!!
            cout<<palabra[i];*/


    /*char *ptr, *rev;
    ptr = p;
    while (*ptr != '\0' ) {
        ++ptr;
    }
    --ptr;
    for (rev = p; ptr >= rev;) {
        if (*ptr == *rev ) {
            --ptr;
            rev++;
        }
        else break;
    }
    if (rev > ptr ) cout<<" es palindromo";
    else cout<<" no es palindromo";*/
    parte=strtok(p," ");
    strcat(cadenaf,parte);
    while((parte=strtok(NULL," ")) != NULL)
    strcat(cadenaf,parte);

    len=strlen(cadenaf);
    for(c=0;c<=len-1;c++)
    {
    if(cadenaf[len-1-c]==cadenaf[c])
    pal++;
    }

    if(pal==len)
    cout<<"\tSi es palindromo!";
    else
    cout<<"\tNo es palindromo";

}
int main(){
    char A[5][100] = {{"amo la paloma"},
                {"roma se asoma"},
                {"ali tomo tila"},
                {"anita lava la tina"},
                {"ramona come mora"}};
    /*for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 100; ++j) {
            cout<<A[i][j];
        }
        cout << endl;
    }
    cout << "\n" << *A;
    cout << "\n" << *(A+1);
    cout << "\n" << *(A+2);
    cout << "\n" << *(A+3);
    cout << "\n" << *(A+4);*/


    //char (*p)[100]=A;
    //char *p;
    //p = &A[0][0];
    /*for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 100; ++j) {
            if(A[i][j] != 32)//32 significa espacio en codigo ascii!!
                A[i][j];
        }
    }*/
    for (int i = 0; i < 5; ++i) {
        palindromo(*(A + i));
    }
}