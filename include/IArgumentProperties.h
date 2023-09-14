#ifndef ABSTR_ARG_PROPS
#define ABSTR_ARG_PROPS

namespace NA{
    class IArgumentProperties{
        public: 
            virtual ~IArgumentProperties() = 0;

            virtual bool is_required() = 0;
            virtual void* get_default_val() = 0;
    };
}

#endif // ABSTR_ARG_PROPS