#pragma once
namespace Kangaroo
{
namespace Util
{

class Noncopyable
{
public:
    Noncopyable(const Noncopyable&) = delete;
    void operator=(const Noncopyable&) = delete;

protected:
    Noncopyable() = default;
    ~Noncopyable() = default;
};

}   // namespace Util
}   // namespace Kangaroo