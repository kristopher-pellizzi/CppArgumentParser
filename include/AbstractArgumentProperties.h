#ifndef ABSTR_ARG_PROPS
#define ABSTR_ARG_PROPS

namespace NA{
    class AbstractArgumentProperties{
        public: 
            virtual ~AbstractArgumentProperties() = 0;

            virtual bool is_required() = 0;
            virtual void* get_default_val() = 0;
    };
}

#endif // ABSTR_ARG_PROPS