#ifndef CONTACT_DAO_HPP
#define CONTACT_DAO_HPP

#include <vector>
#include <memory>

namespace Sxy {
    class Database;
}
class Contact;

class Contact_dao {
public:
    Contact_dao(Sxy::Database& database);

    void init() const;
    bool create_contact(Contact& contact) const;
    bool delete_contact(int id) const;
    bool update_contact(const Contact& contact) const;
    std::vector<std::unique_ptr<Contact>> contacts() const;
private:
    Sxy::Database& db;
};

#endif  // CONTACT_DAO_HPP
