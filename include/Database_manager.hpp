#ifndef DATABASE_MANAGER_HPP
#define DATABASE_MANAGER_HPP

#include <string>

#include "Contact_dao.hpp"

namespace Sxy {
    class Database;
}

class Database_manager {
public:
    Database_manager(const std::string& db_name);
    Database_manager(const Database_manager& ) = delete;
private:
    std::unique_ptr<Sxy::Database> pdb;
public:
    const Contact_dao contact_dao;
};

#endif  // DATABASE_MANAGER_HPP
