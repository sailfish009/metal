// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_OPTIONAL_HPP
#define METAL_OPTIONAL_OPTIONAL_HPP

namespace metal
{
    namespace detail
    {
        template<typename opt, typename = void>
        struct optional_impl;
    }

    /// \ingroup optional
    /// \brief ...
    template<typename opt>
    using optional = typename detail::optional_impl<opt>::type;
}

#include <metal/optional/eval.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>
#include <metal/core/voider.hpp>

namespace metal
{
    namespace detail
    {
        template<typename opt, typename>
        struct optional_impl
        {
            using type = nothing;
        };

        template<typename opt>
        struct optional_impl<opt, voider_t<eval<opt>, void (opt::*)(void)>>
        {
            using type = just<eval<opt>>;
        };
    }
}

#endif
