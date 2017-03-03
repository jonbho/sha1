/*
    sha1.hpp - header of

    ============
    SHA-1 in C++
    ============

    100% Public Domain.

    Original C Code
        -- Steve Reid <steve@edmweb.com>
    Small changes to fit into bglibs
        -- Bruce Guenter <bruce@untroubled.org>
    Translation to simpler C++ Code
        -- Volker Grabsch <vog@notjusthosting.com>
    Safety fixes
        -- Eugene Hopkinson <slowriot at voxelstorm dot com>
    Raw input and output support
        -- Jon Beltran de Heredia <jon at symnum dot com>
*/

#ifndef SHA1_HPP
#define SHA1_HPP


#include <cstdint>
#include <iostream>
#include <string>


class SHA1
{
public:
    struct raw_result_t { uint8_t bytes[20]; };

    SHA1();
    void update(const char *p, size_t size);
    void update(const uint8_t *p, size_t size) { return update((const char *)p, size); }
    void update(const std::string &s);
    void update(std::istream &is);
    std::string final();
    raw_result_t raw_final();
    static std::string from_file(const std::string &filename);

private:
    uint32_t digest[5];
    std::string buffer;
    uint64_t transforms;

    void finalize();
};


#endif /* SHA1_HPP */
