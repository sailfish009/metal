// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/optional.hpp>

#include "example.hpp"

ANONYMOUS
{
/// [is_just]
struct none
{};

struct some
{
    struct type;
};

static_assert(!metal::is_just<none>::value, "");
static_assert(metal::is_just<some>::value, "");
/// [is_just]
}
