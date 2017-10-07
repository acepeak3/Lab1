#pragma once

#include <cstdint>

struct Method1Parameters
{
	static const uint64_t
		m = 4294967291, 
		a = 4294967279 + 1, 
		c = 1111111111,
		X0 = 222222222;
};

struct Method2Parameters
{
	static const uint64_t
		m = 4294967291, 
		a = 4294967279 + 1, 
		c = 1111111111,
		d = 4294967279,
		X0 = 222222222;
};

struct Method3Parameters
{
	static const uint64_t
		m = 4294967291, 	
		X0 = 222222222,
		X1 = 123123123;
};

struct Method4Parameters
{
	static const uint64_t
		m = 4294967291, 
		a = 4294967279 + 1, 
		c = 1111111111,
		X0 = 222222222;
};

struct Method5Parameters
{
	static const uint64_t
		m = 4294967291,
		a = 4294967279 + 1,
		c = 1111111111,
		X0 = 222222222,
		d = 4294967279;
};