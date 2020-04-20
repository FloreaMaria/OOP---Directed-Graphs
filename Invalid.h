#include <exception>

class Invalid : public std :: exception
{

public:

    Invalid() noexcept {}
    Invalid(const Invalid&) noexcept = default;
    Invalid& operator = (const Invalid&) noexcept = default;

    virtual const char* what() const noexcept
    {
        return "Invalid values of graph";
    }

    virtual ~Invalid() noexcept = default;
};


