#include "Database_manager.hpp"

#include <memory>

#include <shixxy/Sxy_Database.hpp>

Database_manager::Database_manager(const std::string& db_name)
    : pdb{std::make_unique<Sxy::Database>()},
    contact_dao{*pdb}
{
    pdb->open(db_name);

    contact_dao.init();
}
