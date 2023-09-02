#ifndef NAMED_ARGS_PARSER
#define NAMED_ARGS_PARSER

#include <map>
#include <string>
#include "FunctionSignature.h"

using std::string;

namespace NA{
    class NamedArgumentsParser{
        private:
            FunctionSignature& sig;
            std::map<string, void*>& args;

            void check_args();

        public:
            NamedArgumentsParser(FunctionSignature& sig, std::map<string, void*>& args);

            template <typename T>
            void get(T* var, string k){
                auto args_found = args.find(k);

                if (args_found != args.end()){
                    *var = *(T*) args_found->second;
                    return;
                }

                auto sig_found = sig.signature.find(k);
                *var = *(T*) (sig_found->second)->get_default_val();
                return;
            }
    };
}

#endif // NAMED_ARGS_PARSER