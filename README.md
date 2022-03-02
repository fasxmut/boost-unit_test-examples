boost::unit_test Examples
========================================================================

Using B2 Jamfile
----------------------------------------

How b2 jamfile:

```
# A b2 jamfile (or jamroot)

exe hello : hello.cpp ;
```

Using libraries in jamfile (Take boost::unit_test for example)
----------------------------------------

jamfile (or jamroot):

```
path-constant local-root : /sandbox ;

import testing ;

unit-test prog : prog.cpp : <library>boost-unit-test ;

lib boost-unit-test
	:
	:
	<name>boost_unit_test_framework <search>$(local-root)/lib
	:
	:
	<link>shared:<define>BOOST_TEST_DYN_LINK=1
	<include>$(local-root)/include
	;
```

`site-config.jam` or `user-config.jam`
----------------------------------------

Enable c++20 in `/etc/site-config.jam` :

Write into `/etc/site-config.jam`  =>
```
project : requirements
	<cxxstd>20
	;
```

If you have no permission to write `/etc/site-config.jam`, write them to your `$HOME/user-config.jam`



