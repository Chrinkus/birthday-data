#include "Contact_model.hpp"
#include "Contact.hpp"
#include "Database_manager.hpp"

Contact_model::Contact_model(Database_manager& db_mgr)
    : db{db_mgr},
    cache{db.contact_dao.contacts()}
{
}

int Contact_model::num_records() const
{
    return static_cast<int>(cache.size());
}

const Contact* Contact_model::record(int i) const
{
    if (!is_valid_index(i)) {
        return nullptr;
    }
    return cache[i].get();
}

bool Contact_model::is_valid_index(int i) const
{
    if (i < 0 || num_records() <= i) {
        return false;
    }
    return true;
}

bool Contact_model::add_contact(const Contact& contact)
{
    auto pcontact = std::make_unique<Contact>(contact);
    if (db.contact_dao.create_contact(*pcontact)) {
        cache.push_back(std::move(pcontact));
        return true;
    }
    return false;
}
