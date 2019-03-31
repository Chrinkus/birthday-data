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
        Sxy::Query query {db};
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
    Sxy::Query query {db};
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

bool Contact_dao::delete_contact(int id) const
{
    Sxy::Query query {db};
    query.prepare("DELETE FROM contacts WHERE id=:id;");
    query.bind_value(":id", id);
    return query.exec();
}

bool Contact_dao::update_contact(const Contact& contact) const
{
    Sxy::Query query {db};
    query.prepare("UPDATE contacts SET "
            "first_name = :first_name, "
            "last_name = :last_name, "
            "birthday = :birthday, "
            "email = :email, "
            "phone_number = :phone_number "
            "WHERE id = :id;");
    query.bind_value(":first_name", contact.first());
    query.bind_value(":last_name", contact.last());
    query.bind_value(":birthday", contact.birth());
    query.bind_value(":email", contact.email());
    query.bind_value(":phone_number", contact.phone());
    query.bind_value(":id", contact.id());
    return query.exec();
}

std::vector<std::unique_ptr<Contact>> Contact_dao::contacts() const
{
    std::vector<std::unique_ptr<Contact>> vpc;
    Sxy::Query query {db};
    query.prepare("SELECT * FROM contacts;");
    while (query.step()) {
        auto pcontact = std::make_unique<Contact>();
        pcontact->id(query.value("id").to_int());
        pcontact->first(query.value("first_name").to_string());
        pcontact->last(query.value("last_name").to_string());
        pcontact->birth(query.value("birthday").to_string());
        pcontact->email(query.value("email").to_string());
        pcontact->phone(query.value("phone_number").to_string());
        vpc.push_back(std::move(pcontact));
    }
    return vpc;
}
