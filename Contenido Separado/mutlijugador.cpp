#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Personaje {
    string nombre;
    int vida;
    int maxVida;
};

struct Mochila {
    int pociones;
};

int generarDanio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void mostrarEstado(const Personaje& p1, const Personaje& p2) {
    cout << "\n======= ESTADO =======\n";
    cout << p1.nombre << " - Vida: " << p1.vida << endl;
    cout << p2.nombre << " - Vida: " << p2.vida << endl;
    cout << "======================\n";
}

void mostrarArte(const string& nombre, bool perspectiva) {
    cout << "\n------ PERSONAJE ------\n";
    if (nombre == "garrobo") {
        if (perspectiva) {
            cout << R"(#####     
                         ###### -   
                       ###+======== 
                     *###===-=======
                     ###============
                   ###==-=======+=
                 ####++==+=======++ 
            ####+==+++==-===-=-   
       ###==+++=++=======------   
    ##+++==+===+===========-----    
  ###===+===========-:--====+===-=  
 ####+===--=====------- ===  +=+=== 
#####    +====           +===+      
===      +=====           +=====    
+====       +               +       
  +##***               #*=++        
     ##+======+##
)";
        } else {
            cout << R"(%#*###@@@@@                              
  #++=+@*=+@@@@                             
   +=+++++=+%@@@                            
    %+=-=++++%@@@                           
      *=++++==+#@@@@                        
       +==++=====*%@@                       
       +=+=======++@@@       %#+##*%  
       #+==============*#@@@      @@%#++#@  
       #++=-===============+++%%+=+#%+%   
       #++%+=-=+=++===========+*%#++#%@     
       #++#++#==+#=========+==+%#         
       #+=*   %+=+% %%##++*%        
     %+%##*+=+               %@         
         @  @@%#@
)";
        }
    }
    else if (nombre == "torogoz") {
        if (perspectiva) {
            cout << R"(---------=                                       
                   ---====------=+#                                    
                 ---=======++%%%%#                                   
                 ---==========%@%%###%%%#######                       
               ---==========%++===-#@@@@@@@@@@%%#                     
                --=================----                                  
              -----===============--=-                                   
            -----===============---                                    
             -------==========+====--                                   
           -=---=====-==============-
)";
