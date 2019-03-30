#include "Contact_dao.hpp"
#include "Contact.hpp"

#include <shixxy/Sxy_Database.hpp>
#include <shixxy/Sxy_Query.hpp>

Contact_dao::Contact_dao(Sxy::Database& database)
    : db{database}
{
}

void Contact_dao::init() const
{
    if (!db.has_table("contacts")) {
        Sxy::Query query{db};
        query.exec("CREATE TABLE contacts ("
                "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "first_name TEXT, "
                "last_name TEXT, "
                "birthday TEXT, "
                "email TEXT, "
                "phone_number TEXT);");
    }
}

bool Contact_dao::create_contact(Contact& contact) const
{
    Sxy::Query query{db};
    query.prepare("INSERT INTO contacts "
            "(first_name, last_name, birthday, email, phone_number) "
            "VALUES "
            "(:first_name, :last_name, :birthday, :email, :phone_number);");
    query.bind_value(":first_name", contact.first());
    query.bind_value(":last_name", contact.last());
    query.bind_value(":birthday", contact.birth());
    query.bind_value(":email", contact.email());
    query.bind_value(":phone_number", contact.phone());
    bool res = query.exec();
    contact.id(static_cast<int>(query.last_insert_id()));
    return res;
}
