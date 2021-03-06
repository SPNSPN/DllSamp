// DllSamp.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include <utility>
#include <limits.h>
#include <vector>
#include "DllSamp.h"
#include "DllSampTemp.h"

// DLL internal state variables:
static std::vector<DllSampTemp<int>> dllsamptemp_int_mem;
static std::vector<DllSampTemp<char *>> dllsamptemp_str_mem;

size_t dllsamp_create_int ()
{
	dllsamptemp_int_mem.push_back(DllSampTemp<int>());
	return dllsamptemp_int_mem.size() - 1;
}

void dllsamp_release_int (size_t hdl)
{
	dllsamptemp_int_mem.at(hdl).set(0);
}

void dllsamp_set_int (size_t hdl, int v)
{
	dllsamptemp_int_mem.at(hdl).set(v);
}

int dllsamp_get_int (size_t hdl)
{
	return dllsamptemp_int_mem.at(hdl).get();
}

size_t dllsamp_create_str ()
{
	dllsamptemp_str_mem.push_back(DllSampTemp<char *>());
	return dllsamptemp_str_mem.size() - 1;
}

void dllsamp_release_str (size_t hdl)
{
	dllsamptemp_str_mem.at(hdl).set(NULL);
}

void dllsamp_set_str (size_t hdl, char *v)
{
	return dllsamptemp_str_mem.at(hdl).set(v);
}

char * dllsamp_get_str (size_t hdl)
{
	return dllsamptemp_str_mem.at(hdl).get();
}




// DLL internal state variables:
static unsigned long long previous_;  // Previous value, if any
static unsigned long long current_;   // Current sequence value
static unsigned index_;               // Current seq. position

// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
void fibonacci_init(
	const unsigned long long a,
	const unsigned long long b)
{
	index_ = 0;
	current_ = a;
	previous_ = b; // see special case when initialized
}

// Produce the next value in the sequence.
// Returns true on success, false on overflow.
bool fibonacci_next()
{
	// check to see if we'd overflow result or position
	if ((ULLONG_MAX - previous_ < current_) ||
		(UINT_MAX == index_))
	{
		return false;
	}

	// Special case when index == 0, just return b value
	if (index_ > 0)
	{
		// otherwise, calculate next sequence value
		previous_ += current_;
	}
	std::swap(current_, previous_);
	++index_;
	return true;
}

// Get the current value in the sequence.
unsigned long long fibonacci_current()
{
	return current_;
}

// Get the current index position in the sequence.
unsigned fibonacci_index()
{
	return index_;
}
