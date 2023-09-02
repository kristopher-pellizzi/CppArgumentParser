#ifndef NAMEDARG
#define NAMEDARG

#include <string>
#include <iostream>

using std::string;

namespace NA{
    template <typename T>
    class NamedArgument{
        private:
            string name;
            T* value;

        public:
            NamedArgument<T>(string name, T value) : name(name), value(new T(value)){}
            NamedArgument<T>(const NamedArgument<T>& other) : name(other.name), value(new T(*other.value)){}
            NamedArgument<T>& operator=(const NamedArgument<T>& other){
                name = other.name;
                value = new T(*other.value);

                return *this;
            }

            ~NamedArgument<T>(){
                delete value;
            }

            const string& getName() const{
                return name;
            }

            const T* getValue() const{
                return value;
            }

            bool operator==(const NamedArgument<T>& other){
                name == other.name;
            }
    };

    NamedArgument<void*> ENDL("__NA::endl__", NULL);

}


#endif // NAMEDARG