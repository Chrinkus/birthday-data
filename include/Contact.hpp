#ifndef BIRTHDAY_CONTACT_HPP
#define BIRTHDAY_CONTACT_HPP

#include <string>

class Contact {
public:
    Contact() = default;
    Contact(const std::string& f, const std::string& l, const std::string& b);

    int id() const { return i; }
    const std::string& first() const { return fn; }
    const std::string& last()  const { return ln; }
    const std::string& email() const { return em; }
    const std::string& phone() const { return ph; }
    const std::string& birth() const { return bd; }

    void id(int ii) { i = ii; }
    void first(const std::string& s) { fn = s; }
    void last (const std::string& s) { ln = s; }
    void email(const std::string& s) { em = s; }
    void phone(const std::string& s) { ph = s; }
    void birth(const std::string& s) { bd = s; }
private:
    int i = -1;
    std::string fn;
    std::string ln;
    std::string bd;
    std::string em;
    std::string ph;
};

#endif  // BIRTHDAY_CONTACT_HPP
