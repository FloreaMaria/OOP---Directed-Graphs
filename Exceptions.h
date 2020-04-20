
#include <exception>

class Exceptions : public std :: exception
{
    public:
        Exceptions() noexcept{}
        Exceptions(const Exceptions&) noexcept = default;
        Exceptions& operator = (const Exceptions&) noexcept = default;

        virtual const char* what() const noexcept{ return "Invalid value";}

        virtual ~Exceptions() noexcept = default;


};


