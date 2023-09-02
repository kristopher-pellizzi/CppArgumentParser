#include "FunctionSignature.h"

using namespace NA;

FunctionSignature::FunctionSignature(){}

FunctionSignature::~FunctionSignature(){
    for(auto iter = signature.begin(); iter != signature.end(); ++iter){
        AbstractArgumentProperties* props = iter->second;
        delete props;
    }
}

void FunctionSignature::register_argument(string name){
    signature.insert(std::pair<string, AbstractArgumentProperties*>(name, new ArgumentProperties<void*>(true, NULL)));
}
