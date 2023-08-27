#include "ArgumentsMap.h"
#include "errors/ArgKeyException.h"

AP::ArgumentsMap::ArgumentsMap(const std::map<string, Argument>& init){
    args = std::map<string, Argument>(init.begin(), init.end());
}

const AP::Argument& AP::ArgumentsMap::operator[](const string& key){
    auto found = args.find(key);

    if (found != args.end())
        return found->second;

    throw ArgKeyException(key);
}

std::map<string, AP::Argument>::iterator AP::ArgumentsMap::begin(){
    return args.begin();
}

std::map<string, AP::Argument>::iterator AP::ArgumentsMap::end(){
    return args.end();
}