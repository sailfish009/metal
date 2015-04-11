// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <boost/mpl2/core/protect.hpp>
#include <boost/mpl2/core/function.hpp>
#include <boost/mpl2/core/bind.hpp>
#include <boost/mpl2/core/call.hpp>
#include <boost/mpl2/core/traits.hpp>
#include <boost/mpl2/core/assert.hpp>

#include <type_traits>

using namespace boost::mpl2;

using bound = bind<function<std::add_pointer>, void>;

BOOST_MPL2_ASSERT(is_function<bound>);
BOOST_MPL2_ASSERT(is_function<protect<bound> >);

BOOST_MPL2_ASSERT((std::is_same<eval<bound>, void*>));
BOOST_MPL2_ASSERT((std::is_same<eval<protect<bound> >, void*>));

BOOST_MPL2_ASSERT((std::is_same<eval<bind<function<std::add_pointer>, bound> >, void**>));
BOOST_MPL2_ASSERT((std::is_same<eval<bind<function<std::add_pointer>, protect<bound> > >, protect<bound>*>));

int main()
{
    return 0;
}