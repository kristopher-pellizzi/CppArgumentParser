#include "NamedArgumentsParser.h"
#include "errors/UnknownNamedArgException.h"
#include "errors/MissingRequiredNamedArgumentException.h"

using namespace NA;

void NamedArgumentsParser::check_args(){
    for(auto iter = args.begin(); iter != args.end(); ++iter){
        auto found = sig.signature.find(iter->first);

        if (found == sig.signature.end())
            throw UnknownNamedArgumentException(iter->first);
    }

    for(auto iter = sig.signature.begin(); iter != sig.signature.end(); ++iter){
        AbstractArgumentProperties* arg_props = iter->second;
        if (arg_props->is_required()){
            auto found = args.find(iter->first);

            if (found == args.end())
                throw MissingRequiredNamedArgumentException(iter->first);
        }
    }
}

NamedArgumentsParser::NamedArgumentsParser(FunctionSignature& sig, std::map<string, void*>& args) :
    sig(sig),
    args(args)
{
    check_args();
}