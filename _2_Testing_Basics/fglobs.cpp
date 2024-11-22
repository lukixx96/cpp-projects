
#include <iostream>
#include "globs.h"

   void fglob(){
      // glb = 16; //ocul
      // std::cout << "fglobs chiama: glb = " << glb << std::endl;
   }

   void sglob(){
      stglb += 200;
      std::cout << "sglob chiama: stglb = " << stglb << std::endl;
   }

   void xglob(){
   xtglb = 16; //ocul pure lui
   std::cout << "xglob chiama: xtglb = " << xtglb << std::endl;
   }