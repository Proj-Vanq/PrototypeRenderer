// PrototypeRenderer BSD Source Code
// Copyright (c) 2013-2016, Daemon Developers
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the Daemon developers nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL DAEMON DEVELOPERS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "gtest/gtest.h"

#include "vkcpp/Vulkan.h"

using Color = vk::ColorComponentFlags;

TEST(BitmaskTests, BasicOperations) {
    Color test1 = Color::R | Color::G;
    ASSERT_EQ(1 | 2, static_cast<uint32_t>(test1));

    Color test2 = test1 ^ (Color::R | Color::A);
    ASSERT_EQ(2 | 8, static_cast<uint32_t>(test2));

    Color test3 = test2 & Color::A;
    ASSERT_EQ(8, static_cast<uint32_t>(test3));

    Color test4 = ~test3;
    ASSERT_EQ(~uint32_t(8), static_cast<uint32_t>(test4));
}

TEST(BitmaskTests, AssignOperations) {
    Color test1 = Color::R;
    test1 |= Color::G;
    ASSERT_EQ(1 | 2, static_cast<uint32_t>(test1));

    Color test2 = test1;
    test2 ^= (Color::R | Color::A);
    ASSERT_EQ(2 | 8, static_cast<uint32_t>(test2));

    Color test3 = test2;
    test3 &= Color::A;
    ASSERT_EQ(8, static_cast<uint32_t>(test3));
}

TEST(BitmaskTests, BoolConversion) {
    bool test1 = Color::R | Color::G;
    ASSERT_TRUE(test1);

    bool test2 = Color::R & Color::G;
    ASSERT_FALSE(test2);

    bool test3 = Color::R ^ Color::G;
    ASSERT_TRUE(test3);

    if (Color::R & ~Color::R) {
        ASSERT_TRUE(false);
    }
}

TEST(BitmaskTests, ThreeOrs) {
    using Flags = vk::QueueFlags;
    Flags f = Flags::Graphics | Flags::Compute | Flags::Transfer;
    ASSERT_EQ(7, static_cast<uint32_t>(f));
}
