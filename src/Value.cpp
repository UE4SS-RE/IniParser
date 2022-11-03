#include <IniParser/Value.hpp>

namespace RC::Ini
{

    auto Value::get_ref() const -> const Value*
    {
        if (!m_ref)
        {
            throw std::runtime_error{"[Ini::Value::get_ref] Tried to access 'Value.ref' but it was nullptr"};
        }
        else
        {
            return m_ref;
        }
    }

    auto Value::set_ref(const Value* new_ref) -> void
    {
        m_ref = new_ref;
    }

    auto Value::get_string_value() const -> const File::StringType&
    {
        return m_string_value;
    }

    auto Value::get_int64_value() const -> int64_t
    {
        return m_int64_value;
    }

    auto Value::get_bool_value() const -> bool
    {
        return m_bool_value;
    }

    auto Value::add_string_value(File::StringViewType data) -> void
    {
        m_string_value = data;

        if (!m_ref)
        {
            m_ref = this;
        }

        add_type<Type::String>();
    }

    auto Value::add_int64_value(const StringType& data, int base) -> void
    {
        m_int64_value = std::stoi(data, nullptr, base);

        if (!m_ref)
        {
            m_ref = this;
        }

        add_type<Type::Int64>();
    }

    auto Value::add_bool_value(bool data) -> void
    {
        m_bool_value = data;

        if (!m_ref)
        {
            m_ref = this;
        }

        add_type<Type::Bool>();
    }
}
