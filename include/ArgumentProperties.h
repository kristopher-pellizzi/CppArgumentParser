#ifndef ARG_PROPS
#define ARG_PROPS

#include "AbstractArgumentProperties.h"

namespace NA{
    template <typename T>
    class ArgumentProperties : public AbstractArgumentProperties{
        private:
            bool required;
            T* default_val;

        public:
            ArgumentProperties(bool required, T default_val) :
                required(required),
                default_val(new T(default_val))
            {}

            ~ArgumentProperties(){
                if (default_val != NULL)
                    delete default_val;
            }

            bool is_required(){
                return required;
            }
            
            void* get_default_val(){
                return (void*) default_val;
            }
    };
}

#endif // ARG_PROPS