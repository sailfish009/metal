# Copyright Bruno Dutra 2015-2017
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

add_subdirectory(unit)
add_subdirectory(header)
add_subdirectory(deployment)

add_custom_target(tests DEPENDS
    test.unit
    test.header
    test.deployment
)
