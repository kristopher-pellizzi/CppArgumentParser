#include "ArgumentsMap.h"
#include "errors/ArgKeyException.h"

AP::ArgumentsMap::ArgumentsMap(const std::map<string, IArgument*>& init){
    args = std::map<string, IArgument*>(init.begin(), init.end());
}

AP::IArgument* AP::ArgumentsMap::operator[](const string& key){
    auto found = args.find(key);

    if (found != args.end())
        return found->second;

    throw ArgKeyException(key);
}

std::map<string, AP::IArgument*>::iterator AP::ArgumentsMap::begin(){
    return args.begin();
}

std::map<string, AP::IArgument*>::iterator AP::ArgumentsMap::end(){
    return args.end();
}