//
// Created by joshua on 8/26/16.
//




#include "RestBuilder.h"

// argv[1] == outputDirectory
// argv[2] == fileLocation
// argv[3] == idedebug==(true|false)
int main(int argc, char * argv[]){
    // output to this directory
    // read from this file vvvv


    if(argc  < 2){
        printf("Error Usage : \nargv[1] == outputDirectory\n"
                       "argv[2] == fileLocation\n"
                       "argv[3] == idedebug==(true|false)\n");
    } else {


            Rest::RestGenerator rg(argv[1]);
            Rest::RestBuilder b(rg, argv[2]);
            rg.generateCode();


    }
}