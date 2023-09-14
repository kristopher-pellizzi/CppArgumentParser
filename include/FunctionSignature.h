#ifndef FUNC_SIG
#define FUNC_SIG

#include <map>
#include <string>
#include "IArgumentProperties.h"
#include "ArgumentProperties.h"

using std::string;

namespace NA{
    class FunctionSignature{
        friend class NamedArgumentsParser;

        private:
            std::map<string, IArgumentProperties*> signature;

        public:
            FunctionSignature();

            ~FunctionSignature();

            void register_argument(string name);

            template <typename T>
            void register_argument(string name, T default_val){
                signature.insert(std::pair<string, IArgumentProperties*>(name, new ArgumentProperties<T>(false, default_val)));
            }
    };
}

#endif // FUNC_SIG