/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _AUTH_SARC4_H
#define _AUTH_SARC4_H

#include "Define.h"
#include <array>
#include <openssl/evp.h>

namespace Acore::Crypto
{
    class AC_COMMON_API ARC4
    {
    public:
        ARC4();
        ~ARC4();

        void Init(uint8 const* seed, std::size_t len);

        template <typename Container>
        void Init(Container const& c) { Init(std::data(c), std::size(c)); }

        void UpdateData(uint8* data, std::size_t len);

        template <typename Container>
        void UpdateData(Container& c) { UpdateData(std::data(c), std::size(c)); }
    private:
        EVP_CIPHER* _cipher;
        EVP_CIPHER_CTX* _ctx;
    };
}

#endif
