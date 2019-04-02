#ifndef CONTACT_MODEL_HPP
#define CONTACT_MODEL_HPP

#include <vector>
#include <memory>

class Contact;
class Database_manager;

class Contact_model {
public:
    Contact_model(Database_manager& db_mgr);

    int num_records() const;
    const Contact* record(int i) const;
    bool is_valid_index(int i) const;

    bool add_contact(const Contact& contact);

private:
    Database_manager& db;
    std::vector<std::unique_ptr<Contact>> cache;
};

#endif  // CONTACT_MODEL_HPP
