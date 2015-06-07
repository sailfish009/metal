// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/metafunctional/lambda.hpp>
#include <boost/mpl2/metafunctional/placeholders.hpp>
#include <boost/mpl2/metafunctional/call.hpp>
#include <boost/mpl2/metafunctional/protect.hpp>
#include <boost/mpl2/metafunctional/traits.hpp>

#include "test/variadic.hpp"
#include "test/wrap.hpp"
#include "test/main.hpp"

using namespace boost::mpl2;
using namespace boost::mpl2::placeholders;

BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::fundamental<>>>, test::fundamental<>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::function<>>>, test::function<>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::incomplete<>>>, test::incomplete<>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::empty<>>>, test::empty<>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::eponym<test::call>>>, test::eponym<test::call>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::evaluable<>>>, test::evaluable<>::type>));

BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<_1>, void>, void>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<std::add_pointer<_1>>, void>, void*>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<protect<lambda<std::add_pointer<_1>>>>, void>, void*>));

BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::wrapper>, short, int, long, long long>, test::wrapper>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<protect<test::wrapper>>, void>, test::wrap<void>>));

BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::wrap<_1>>, short, int, long, long long>, test::wrap<short>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2>>, short, int, long, long long>, test::wrap<short, int>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2, _3>>, short, int, long, long long>, test::wrap<short, int, long>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<test::wrap<_1, _2, _3, _4>>, short, int, long, long long>, test::wrap<short, int, long, long long>>));

BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, void>, lambda<void>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<protect<lambda<_1>>>, void>, void>));

BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<lambda<_1>>, protect<_1>>, lambda<protect<_1>>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<protect<_1>>, lambda<_1>>, lambda<_1>>));

BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<quoter<protect>>, _1>, quoter<protect>>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<protect<quoter<protect>>>, _1>, protect<_1>>));

BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<call<lambda<std::add_pointer<_1>>, void>>, void*>, void**>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<call<_1, void>>, lambda<std::add_pointer<_1>>>, void*>));

using compose = protect<lambda<call<lambda<_1>, call<lambda<_2>, _3>>>>;
BOOST_MPL2_ASSERT((is_function<compose>));
BOOST_MPL2_ASSERT((std::is_same<call_t<compose, std::add_pointer<_1>, std::add_const<_1>, void>, void const*>));
BOOST_MPL2_ASSERT((std::is_same<call_t<compose, std::add_const<_1>, std::add_pointer<_1>, void>, void* const>));

using once = protect<lambda<call<compose, protect<_1>, _1, _2>>>;
BOOST_MPL2_ASSERT((is_function<once>));
BOOST_MPL2_ASSERT((std::is_same<call_t<once, std::add_pointer<_1>, void>, void*>));

using twice = protect<lambda<call<compose, _1, _1, _2>>>;
BOOST_MPL2_ASSERT((is_function<twice>));
BOOST_MPL2_ASSERT((std::is_same<call_t<twice, std::add_pointer<_1>, void>, void**>));

using thrice = protect<lambda<call<once, _1, call<twice, _1, _2>>>>;
BOOST_MPL2_ASSERT((is_function<thrice>));
BOOST_MPL2_ASSERT((std::is_same<call_t<thrice, std::add_pointer<_1>, void>, void***>));

using ptr2ptr2ptr = protect<lambda<call<thrice, protect<lambda<std::add_pointer<_1>>>, _1>>>;
BOOST_MPL2_ASSERT((is_function<ptr2ptr2ptr>));
BOOST_MPL2_ASSERT((std::is_same<call_t<ptr2ptr2ptr, void>, void***>));
BOOST_MPL2_ASSERT((std::is_same<call_t<lambda<ptr2ptr2ptr>, void>, void***>));
