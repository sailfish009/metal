// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_DEFER_HPP
#define METAL_LAMBDA_DEFER_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct defer
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref defer.
    template<typename... args>
    using defer_t = typename defer<args...>::type;
}

#include <metal/lambda/arg.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/list/at.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/just.hpp>
#include <metal/optional/nothing.hpp>

namespace metal
{
    namespace detail
    {
        template<
            template<typename...> class expr,
            typename... args,
            typename ret = expr<args...>
        >
        just<ret> instantiate(defer<lambda<expr>, args...>*);
        nothing instantiate(...);
    }

    template<template<typename...> class expr, typename... args>
    struct defer<lambda<expr>, args...> :
        decltype(
            detail::instantiate(
                static_cast<defer<lambda<expr>, args...>*>(0)
            )
        )
    {};

    template<
        template<typename...> class expr,
        typename... params,
        typename... args
    >
    struct defer<expr<params...>, args...> :
        defer<lift_t<lambda<expr>>, invoke<params, args...>...>
    {};

   template<typename val, typename... args>
    struct defer<val, args...>
    {
        using type = just<val>;
    };

    template<std::size_t n, typename... args>
    struct defer<arg<n>, args...> :
        just<at<defer<arg<n>, args...>, number<std::size_t, n>>>
    {};

    template<typename x, typename y, typename... tail>
    struct defer<arg<2U>, x, y, tail...>
    {
        using type = just<y>;
    };

    template<typename x, typename... tail>
    struct defer<arg<1U>, x, tail...>
    {
        using type = just<x>;
    };

    template<typename... args>
    struct defer<arg<0U>, args...>
    {};
}

#endif
