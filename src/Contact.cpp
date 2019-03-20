#include "Contact.hpp"

using namespace boost::gregorian;

Contact::Contact(const std::string& f, const std::string& l,
        const std::string& b)
    : fn{f}, ln{l}, bd{from_simple_string(b)}
{
}

std::string Contact::birth() const
{
    static date null_date {not_a_date_time};

    if (bd == null_date) {
        return std::string{};
    }
    return to_simple_string(bd);
}

void Contact::birth(const std::string& s)
{
    bd = from_simple_string(s);
}
