#pragma once

#ifdef DLLSAMP_EXPORTS
#define DLLSAMP_API __declspec(dllexport)
#else
#define DLLSAMP_API __declspec(dllimport)
#endif

extern "C" DLLSAMP_API size_t dllsamp_create_int ();
extern "C" DLLSAMP_API void dllsamp_release_int (size_t hdl);
extern "C" DLLSAMP_API void dllsamp_set_int (size_t hdl, int v);
extern "C" DLLSAMP_API int dllsamp_get_int (size_t hdl);

extern "C" DLLSAMP_API size_t dllsamp_create_str ();
extern "C" DLLSAMP_API void dllsamp_release_str (size_t hdl);
extern "C" DLLSAMP_API void dllsamp_set_str (size_t hdl, char *v);
extern "C" DLLSAMP_API char * dllsamp_get_str (size_t hdl);


// The Fibonacci recurrence relation describes a sequence F
// where F(n) is { n = 0, a
//               { n = 1, b
//               { n > 1, F(n-2) + F(n-1)
// for some initial integral values a and b.
// If the sequence is initialized F(0) = 1, F(1) = 1,
// then this relation produces the well-known Fibonacci
// sequence: 1, 1, 2, 3, 5, 8, 13, 21, 34, ...

// Initialize a Fibonacci relation sequence
// such that F(0) = a, F(1) = b.
// This function must be called before any other function.
extern "C" DLLSAMP_API void fibonacci_init(
	const unsigned long long a, const unsigned long long b);

// Produce the next value in the sequence.
// Returns true on success and updates current value and index;
// false on overflow, leaves current value and index unchanged.
extern "C" DLLSAMP_API bool fibonacci_next();

// Get the current value in the sequence.
extern "C" DLLSAMP_API unsigned long long fibonacci_current();

// Get the position of the current value in the sequence.
extern "C" DLLSAMP_API unsigned fibonacci_index();
