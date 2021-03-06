// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_CONTAINS_HPP
#define METAL_LIST_CONTAINS_HPP

#include <metal/config.hpp>

#include <metal/list/any_of.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/value/same.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// Checks whether a \value is contained in a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \value `val`
    /// \code
    ///     using result = metal::contains<l, val>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `val` is contained in `l`, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp contains
    ///
    /// ### See Also
    /// \see list, count, find
    template<typename seq, typename val>
    using contains =
        metal::any_of<seq, metal::partial<metal::lambda<metal::same>, val>>;
}

#endif
