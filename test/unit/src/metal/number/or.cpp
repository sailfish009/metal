// Copyright Bruno Dutra 2015-2017
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, VALUE(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, VALUE(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, VALUE(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, VALUE(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, VALUE(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, VALUE(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, NUMBER(M) COMMA(N) VALUES(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, NUMBER(M) COMMA(N) NUMBERS(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, NUMBER(M) COMMA(N) PAIRS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, NUMBER(M) COMMA(N) LISTS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, NUMBER(M) COMMA(N) MAPS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, NUMBER(M) COMMA(N) LAMBDAS(N)>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, PAIR(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, PAIR(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, PAIR(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, PAIR(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, PAIR(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, PAIR(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LIST(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LIST(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LIST(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LIST(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LIST(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LIST(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, MAP(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, MAP(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, MAP(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, MAP(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, MAP(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, MAP(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(M) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(_) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(_) COMMA(N) NUMBERS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(_) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(_) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(_) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::or_>, LAMBDA(_) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::or_<NUMBER(M) COMMA(N) NUMBERS(N)>), (BOOL(M || N > 1))); \
    CHECK((metal::or_<ENUM(N, NUMBER FIX(M))>), (BOOL(N && M))); \
/**/

GEN(MATRIX)
