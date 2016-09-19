//
// Created by joshua on 8/24/16.
//

#ifndef JLEXX_RESTBUILDER_H
#define JLEXX_RESTBUILDER_H
#include <JLexx/RegexToDFABuilder.h>
#include <JLexx/FileLoader.h>
#include "RestGenerator.h"
#include "RestToken.h"
namespace Rest{
    class RestBuilder : public RegexToDFABuilder{
    public:
        RestGenerator & rg;

        std::vector<std::string> lexRegexList;
        RestBuilder() = delete;
        RestBuilder(RestGenerator & rgg,std::string fileName): RegexToDFABuilder(),rg(rgg){

            lexRegexList = {
                    "[gG][eE][tT]",
                    "[pP][uU][tT]",
                    "[pP][oO][sS][tT]",
                    "[dD][eE][lL][eE][tT][eE]",
                    "POST_PARAMS",
                    "file",
                    "[a-zA-Z][a-zA-Z0-9]*[.][a-zA-Z]+",
                    "string",
                    "array",
                    "return",
                    "\\\"[sS]uccess\\\"", // 10
                    "\\\"[eE]rror\\\"",
                    "dictionary",
                    ":",
                    "\\|",
                    "\\-\\>",
                    ";",
                    "http://[^/]*/",
                    "[\t\n ]+",
                    "[a-zA-Z][a-zA-Z0-9]*",
                    "[^\t\n ]"


            };

            for(auto t : lexRegexList){
                this->add(t);
            }
            this->create(true);
            std::string str = FileLoader::fileToString(fileName,false);
            this->match(str,true,false,nullptr);
        }




        virtual bool match(const string  &s, bool verbose = true, bool shortestMatch= false,JLexx::DataHandler * handler = nullptr) override{

            if(shortestMatch){throw std::invalid_argument("I need to implement that feat");}
            unsigned int curr = 0;
            unsigned int start = 0;
            unsigned int lastState =0;
            JLexx::State & last = this->uncompressedStateList[0];
            bool toReturn = false;
            // start of match end of match regex number
            //Lexx::Data d = {0,0,0};

            while(start  < s.length()){
                while((uncompressedStateList[lastState][s[curr]]) != JLexx::STATE_SENTINEL){
                    lastState = uncompressedStateList[lastState][s[curr++]];
                }
                if(uncompressedStateList[lastState].isAccepting()){
                    if(verbose) {
                        printf("\n@BEGIN MATCH\n");
                        printf("\tMatched     : %s \n", s.substr(start, curr - start).c_str());
                        printf("\tWith Regex  : %u and token string %s\n", uncompressedStateList[lastState].acceptingState,lexRegexList[uncompressedStateList[lastState].acceptingState].c_str());
                        printf("@END   MATCH\n");
                    }

                    RestToken t = {uncompressedStateList[lastState].acceptingState,s.substr(start, curr - start)};
                    rg.handleToken(std::move(t));
                   //d.startOfMatch = start;
                   //d.endOfMatch = curr;
                   //d.regexNumber =stateList[lastState].acceptingState;
                    //generator.handleData(d);

                    start+=(curr-start) - 1;
                }

                last = uncompressedStateList[0];
                lastState = 0;
                start++;
                curr = start;
            }

            return toReturn;
        }



    };



};
#endif //JLEXX_RESTBUILDER_H
